#include <iostream>
#include <cstring>
using namespace std;

int N;
int p,q;
int count;
bool flag;
int visited[28][28];
int resX[28],resY[28];
int dx[10] = {0,-1,1,-2,2,-2,2,-1,1};
int dy[10] = {0,-2,-2,-1,-1,1,1,2,2};

bool judge(int temp_x, int temp_y)
{
	if ( visited[temp_x][temp_y] )	return false;
	else if ( temp_x < 1 || temp_x > p || temp_y < 1 || temp_y > q )	return false;
	return true;
}

void printResult()
{
	for ( int i = 1; i <= count; ++i )
		cout << char('A' + resY[i] - 1) << resX[i];
	cout << endl;
}

void dfs(int x, int y)
{
	++count;
	resX[count] = x;
	resY[count] = y;
	if ( p * q == count ) {
		flag = true;
		printResult();
		return;
	}
	visited[x][y] = 1;
	for ( int i = 1; i <= 8; ++i ) {
		int temp_x = x + dx[i];
		int temp_y = y + dy[i];
		if ( judge(temp_x,temp_y) )	dfs(temp_x,temp_y);
		if ( flag )	break;
	}
	visited[x][y] = 0;
	--count;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	for ( int n = 1; n <= N; ++n ) {
		flag = false;
		count = 0;
		memset(visited,0,sizeof(visited));
		memset(resX,0,sizeof(resX));
		memset(resY,0,sizeof(resY));
		cin >> p >> q;
		cout << "Scenario #" << n << ":" << endl;
		dfs(1,1);
		if ( !flag )	cout << "impossible" << endl;
		cout << endl;
	}
}
