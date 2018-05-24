// 2018-5-24
// 16:44
#include <iostream>
#include <cstring>
using namespace std;

int N,E;
int visited[12];
int v[12][12];
int rear = 0;
int front = 0;
int q[150];

void DFS(int pos)
{
	cout << " " << pos;
	visited[pos] = 1;
	for ( int i = 0; i < N; ++i ) {
		if ( !visited[i] && v[pos][i] )
			DFS(i);
	}
}

void TDFS()
{
	for ( int i = 0; i < N; ++i ) {
		if ( !visited[i] ) {
			cout << "{";
			DFS(i);
			cout << " }" << endl;
		} 
	}
}

void BFS(int pos)
{
	if ( !visited[pos] )	cout << " " << pos;
	visited[pos] = 1;
	for ( int i = 0; i < N; ++i ) {
		if ( !visited[i] && v[pos][i] )
			q[rear++] = i;
	}
	while ( front != rear ) {
		pos = q[front++];
		BFS(pos);
	}
}

void TBFS()
{
	for ( int i = 0; i < N; ++i ) {
		if ( !visited[i] ) {
			cout << "{";
			BFS(i);
			cout << " }" << endl;
		} 
	}
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N >> E;
	memset(visited,0,sizeof(visited));
	memset(v,0,sizeof(v));
	for ( int i = 0; i < E; ++i ) {
		int a,b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1; 
	}
	TDFS();
	memset(visited,0,sizeof(visited));
	memset(q,0,sizeof(q));
	TBFS();
	return 0;
}
// 2018/5/24 17:30:49