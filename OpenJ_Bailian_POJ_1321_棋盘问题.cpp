#include <iostream>
#include <memory.h>
using namespace std;

int N,K;
char chess[10][10];
int visited[10];
int count;

void dfs(int r, int k)
{
	if ( 0 == k ) {
		++count;
		return;
	}
	int end = N - k + 1;
	for ( int i = r; i <= end; ++i )
		for ( int j = 1; j <= N; ++j ) {
			if ( 0 == visited[j] && '#' == chess[i][j] ) {
				visited[j] = 1;
				dfs(i + 1,k - 1);
				visited[j] = 0;
			}
		}
}

int main()
{
	freopen("F://input.txt","r",stdin);
	while ( true ) {
		cin >> N >> K;
		if ( -1 == N )	break;
		count = 0;
		memset(chess,'\0',sizeof(chess));
		memset(visited,0,sizeof(visited));
		for ( int i = 1; i <= N; ++i )
			for ( int j = 1; j <= N; ++j )	cin >> chess[i][j];
		dfs(1,K);
		cout << count << endl;
	}
	return 0;
}
