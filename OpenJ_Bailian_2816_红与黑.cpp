#include <iostream>
#include <memory.h>
using namespace std;

char tiles[22][22];
int visited[22][22];
int sta,stb;
int W,H;
int count = 0;

void dfs(int a,int b)
{
	++count;
	visited[a][b] = 1;
	if ( 1 <= b - 1 && !visited[a][b - 1] && tiles[a][b - 1] != '#' )	dfs(a,b - 1);
	if ( 1 <= a - 1 && !visited[a - 1][b] && tiles[a - 1][b] != '#' )	dfs(a - 1,b);
	if ( W >= b + 1 && !visited[a][b + 1] && tiles[a][b + 1] != '#' )	dfs(a,b + 1);
	if ( H >= a + 1 && !visited[a + 1][b] && tiles[a + 1][b] != '#' )	dfs(a + 1,b);
}

int main()
{
//	freopen("F://input.txt","r",stdin);
	while ( true ) {
		memset(tiles,'#',sizeof(tiles));
		memset(visited,0,sizeof(visited));
		cin >> W >> H;
		if ( 0 == W && 0 == H )	break;
		for ( int i = 1; i <= H; ++i )
			for ( int j = 1; j <= W; ++j ) {
				cin >> tiles[i][j];
				if ( '@' == tiles[i][j] ) {
					sta = i;
					stb = j;
				}
			}
		dfs(sta,stb);
		cout << count << endl;
		count = 0;
	}
	return 0;
}
