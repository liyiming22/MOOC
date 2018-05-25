#include <iostream>
#include <cstring>
using namespace std;

int N,L;
int thisCount;
int thisLength;
int v[1005][1005];
int visited[1005];

// v[a][b] = 1 表示a follow b

void dfs(int node)
{
	visited[node] = 1;
	for ( int i = 1; i <= N; ++i ) {
		if ( 0 == visited[i] && 1 == v[node][i] ) {
			++thisLength;
			++thisCount;
//			cout << i << " ";
			if ( thisLength < L )
				dfs(i);
			else visited[i] = 1;
			--thisLength;
		}
	}
//	visited[node] = 0;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N >> L;
	memset(v,0,sizeof(v));
	for ( int i = 1; i <= N; ++i ) {
		int temp;
		cin >> temp;
		for ( int j = 1; j <= temp; ++j ) {
			int node;
			cin >> node;
			v[node][i] = 1;
		}
	}
//	for ( int i = 1; i <= N; ++i ) {
//		cout << i << ": ";
//		for ( int j = 1; j <= N; ++j ) {
//			if ( v[i][j] == 1 )	cout << j << " ";
//		}
//		cout << endl;
//	}
	int temp;
	cin >> temp;
	while ( temp-- ) {
		int node;
		cin >> node;
		thisCount = 0;
		thisLength = 0;
		memset(visited,0,sizeof(visited));
		dfs(node);
		cout << thisCount << endl;
	}
	return 0;
}
