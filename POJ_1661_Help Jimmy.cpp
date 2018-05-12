#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t;
int N,X,Y,MAX;
int lmTime[1010];
int rmTime[1010];
const int INFINITY = 50000;

struct Node{
	int x1;
	int x2;
	int h;
};

bool Cmp(struct Node node1, struct Node node2);
int dpLeft(int x, int num, const struct Node * node);
int dpRight(int x, int num, const struct Node * node);

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> t;
	while ( t-- ) {
		cin >> N >> X >> Y >> MAX;
		struct Node * node = new struct Node[N + 1];
		memset(lmTime,-1,sizeof(lmTime));
		memset(rmTime,-1,sizeof(rmTime));
		node[0].x1 = node[0].x2 = X;
		node[0].h = Y;
		for ( int i = 1; i <= N; ++i ) {
			cin >> node[i].x1 >> node[i].x2 >> node[i].h;
		}
		sort(node,node + N + 1,Cmp);
		int a = dpLeft(X,0,node);
		int b = dpRight(X,0,node);
		int res = min(a,b);
		cout << res << endl;
		delete[] node;
	}
	return 0;
}

bool Cmp(struct Node node1, struct Node node2)
{
	return node1.h > node2.h;
}

int dpLeft(int x, int num, const struct Node * node)
{
	if ( -1 != lmTime[num] )	return lmTime[num];
	int thisLeft = node[num].x1;
	int thisRight = node[num].x2;
	int nextLeft,nextRight;
	int pos = num;
//	find the closet left node;
	for ( int i = num + 1; i <= N; ++i ) {
		nextLeft = node[i].x1;
		nextRight = node[i].x2;
		if ( nextLeft < thisLeft && nextRight >= thisLeft && node[num].h - node[i].h <= MAX ) {
			pos = i;
			break;
		}
	}
//	not found
	if ( pos == num ) {
		if ( node[pos].h > MAX )	return lmTime[pos] = INFINITY;
		else	return lmTime[pos] = x - thisLeft + node[pos].h;
	}
//	found
	else {
		int goLeft = x - thisLeft + dpLeft(thisLeft,pos,node);
		int goRight = x - thisLeft + dpRight(thisLeft,pos,node);
		lmTime[num] = min(goLeft,goRight);
	}
	lmTime[num] += node[num].h - node[pos].h;
	return lmTime[num];
}

int dpRight(int x, int num, const struct Node * node)
{
	if ( -1 != rmTime[num] )	return rmTime[num];
	int thisLeft = node[num].x1;
	int thisRight = node[num].x2;
	int nextLeft,nextRight;
	int pos = num;
//	find the closet left node;
	for ( int i = num + 1; i <= N; ++i ) {
		nextLeft = node[i].x1;
		nextRight = node[i].x2;
		if ( nextLeft <= thisRight && nextRight > thisRight && node[num].h - node[i].h <= MAX ) {
			pos = i;
			break;
		}
	}
//	not found
	if ( pos == num ) {
		if ( node[pos].h > MAX )	return rmTime[pos] = INFINITY;
		else	return rmTime[pos] = thisRight - x + node[pos].h;
	}
//	found
	else {
		int goLeft = thisRight - x + dpLeft(thisRight,pos,node);
		int goRight = thisRight - x + dpRight(thisRight,pos,node);
		rmTime[num] = min(goLeft,goRight);
	}
	rmTime[num] += node[num].h - node[pos].h;
	return rmTime[num];
}
