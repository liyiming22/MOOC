#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int t,N,X,Y,MAX;
struct Node{
	int Lx;
	int Rx;
	int h;
};
int LeftTime[1010];
int RightTime[1010];
const int INFINITY = 30000;

bool Cmp(struct Node node1, struct Node node2)
{
	return node1.h > node2.h;
}

int dp(int pos, bool goLeft, const struct Node * node)
{
	int thisH = node[pos].h;
	int thisX = goLeft? node[pos].Lx : node[pos].Rx;
// 	find the next closet board
	int next = pos;
	for ( int i = pos + 1; i <= N; ++i ) {
		if ( node[i].Lx <= thisX && node[i].Rx >= thisX && thisH - node[i].h <= MAX ) {
			next = i;
			break;
		}
	}
//	no found
	if ( next == pos ) {
		if ( thisH > MAX )	return INFINITY;
		else	return thisH;
	}
//	found
	int tempLeft = thisH - node[next].h + thisX - node[next].Lx;
	int tempRight = thisH - node[next].h + node[next].Rx - thisX;
	if ( -1 == LeftTime[next] )	LeftTime[next] = dp(next,true,node);
	if ( -1 == RightTime[next] ) RightTime[next] = dp(next,false,node);
	tempLeft += LeftTime[next];
	tempRight += RightTime[next];
	return min(tempLeft,tempRight);
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> t;
	while ( t-- ) {
		cin >> N >> X >> Y >> MAX;
		struct Node * node = new struct Node[N + 1];
		node[0].Lx = node[0].Rx = X;
		node[0].h = Y;
		memset(LeftTime,-1,sizeof(LeftTime));
		memset(RightTime,-1,sizeof(RightTime));
		for ( int i = 1; i <= N; ++i ) {
			cin >> node[i].Lx >> node[i].Rx >> node[i].h;
		}
		sort(node,node + N + 1,Cmp);
		cout << dp(0,true,node) << endl;
		delete[] node;
	}
	return 0;
}
