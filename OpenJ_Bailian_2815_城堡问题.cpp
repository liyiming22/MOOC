#include <iostream>
#include <memory.h>
using namespace std;

int R,C;
int rooms[51][51];
int visited[51][51];
int maxRoom = 0, roomNum = 0;
int thisRoom;

void dfs(int r, int c)
{
	if ( visited[r][c] )	return;
	++thisRoom;
	visited[r][c] = 1;
	if ( 0 == (rooms[r][c] & 1) )	dfs(r,c - 1);
	if ( 0 == (rooms[r][c] & 2) )	dfs(r - 1,c);
	if ( 0 == (rooms[r][c] & 4) )	dfs(r,c + 1);
	if ( 0 == (rooms[r][c] & 8) )	dfs(r + 1,c);
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> R >> C;
	for ( int i = 1; i <= R; ++i )
		for ( int j = 1; j <= C; ++j )	cin >> rooms[i][j];
	memset(visited,0,sizeof(visited));
	for ( int i = 1; i <= R; ++i )
		for ( int j = 1; j <= C; ++j ) {
			if ( !visited[i][j] ) {
				++roomNum;
				thisRoom = 0;
				dfs(i,j);
				maxRoom = maxRoom > thisRoom? maxRoom : thisRoom;
			}
		}
	cout << roomNum << endl << maxRoom << endl;
	return 0;
}