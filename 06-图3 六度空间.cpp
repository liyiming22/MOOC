// 16:07
#include <iostream>
#include <cstring>
using namespace std;

int N,M;
double thisCount;
int thisLength;
int v[1005][1005];
int visited[1005];

void dfs(int p)
{
	visited[p] = 1;
	for ( int i = 1; i <= N; ++i ) {
		if ( 0 == visited[i] && 1 == v[p][i] ) {
			++thisLength;
			++thisCount;
			if ( thisLength < 6 )	dfs(i);
			--thisLength;
		}
	}
	visited[p] = 0;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N >> M;
	memset(v,0,sizeof(v));
	for ( int i = 0; i < M; ++i ) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		v[temp1][temp2] = v[temp2][temp1] = 1;
	}
	for ( int i = 1; i <= N; ++i ) {
		cout << i << ": ";
		memset(visited,0,sizeof(visited));
		thisLength = 0;
		thisCount = 0;
		dfs(i);
		thisCount = (thisCount + 1) * 100;
		double res = thisCount/N;
		printf("%3.2lf",res);
		cout << '%' << endl;
	}
	return 0;
}
