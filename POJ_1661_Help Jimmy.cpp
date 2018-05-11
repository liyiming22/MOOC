#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int t;
int N,X,Y,MAX;
//int * lmTime;
//int * rmTime;
int lmTime[5];
int rmTime[5];
const int INFINITY = 50000;

struct Node{
	int x1;
	int x2;
	int h;
};

bool Cmp(struct Node node1, struct Node node2);
int dpLeft(int x, int y, int num, const struct Node * node);
int dpRight(int x, int y, int num, const struct Node * node);

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> t;
	while ( t-- ) {
		cin >> N >> X >> Y >> MAX;
		struct Node * node = new struct Node[N + 1];
//		lmTime = new int[N + 1];
//		rmTime = new int[N + 1];
		memset(lmTime,-1,sizeof(lmTime));
		memset(rmTime,-1,sizeof(rmTime));
		cout << rmTime[2] << " " << lmTime[3] << endl;
		node[0].x1 = node[0].x2 = X;
		node[0].h = Y;
		for ( int i = 1; i <= N; ++i ) {
			cin >> node[i].x1 >> node[i].x2 >> node[i].h;
		}
		sort(node,node + N + 1,Cmp);
		int a = dpLeft(X,Y,0,node);
		int b = dpRight(X,Y,0,node);
		int res = min(a,b);
		cout << res << endl;
		cout << lmTime[0] << " " << rmTime[0] << endl;
		delete[] node;
//		delete[] lmTime;
//		delete[] rmTime;
	}
	return 0;
}

bool Cmp(struct Node node1, struct Node node2)
{
	return node1.h > node2.h;
}

int dpLeft(int x, int y, int num, const struct Node * node)
{
//	if ( -1 != lmTime[num] )	return lmTime[num];
//	find the closet left node;
	int pos = num;
	for ( int i = num + 1; i <= N + 1; ++i ) {
		if ( node[i].x1 < node[num].x1 && node[num].h - node[i].h <= MAX )
			pos = i;
	}
//	not found
	if ( num == pos ) {
		if ( node[num].h > MAX )	lmTime[num] = INFINITY;
		else	lmTime[num] = x - node[num].x1 + node[num].h;
	}
//	found
	else {
		lmTime[num] = min(x - node[num].x1 + dpLeft(node[num].x1,node[pos].h,pos,node),node[num].x2 - x + dpRight(node[num].x2,node[pos].h,pos,node));
	}
	lmTime[num] += (node[num].h - node[pos].h); 
	return lmTime[num];
}

int dpRight(int x, int y, int num, const struct Node * node)
{
//	if ( -1 != rmTime[num] )	return rmTime[num];
//	find the closet right node;
	int pos = num;
	for ( int i = num + 1; i <= N + 1; ++i ) {
		if ( node[i].x2 > node[num].x2 && node[num].h - node[i].h <= MAX )
			pos = i;
	}
//	not found
	if ( num == pos ) {
		if ( node[num].h > MAX )	rmTime[num] = INFINITY;
		else	rmTime[num] = node[num].x2 - x + node[num].h;
	}
//	found
	else {
		rmTime[num] = min(x - node[num].x1 + dpLeft(node[num].x1,node[pos].h,pos,node),node[num].x2 - x + dpRight(node[num].x2,node[pos].h,pos,node));
	}
	rmTime[num] += (node[num].h - node[pos].h); 
	return rmTime[num];
}

