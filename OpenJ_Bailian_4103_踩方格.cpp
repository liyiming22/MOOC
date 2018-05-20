#include <iostream>
#include <memory.h>
using namespace std;

int N;
int visited[20][50];

int dfs(int r, int c, int n)
{
	if ( 0 == n )	return 1;
	int ways = 0;
	visited[r][c] = 1;
	if ( !visited[r + 1][c] )	ways += dfs(r + 1,c,n - 1);
	if ( !visited[r][c - 1] )	ways += dfs(r,c - 1,n - 1);
	if ( !visited[r][c + 1] )	ways += dfs(r,c + 1,n - 1);
	visited[r][c] = 0;
	return ways;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	memset(visited,0,sizeof(visited));
	cout << dfs(0,20,N) << endl;
	return 0;
}
