#include <iostream>
using namespace std;

int R,C;
int ** h;
int ** L;
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
int result = -1;

int dp(int r, int c)
{
	if ( 0 != L[r][c] )	return L[r][c];
	int res = 0;
	for ( int i = 0; i < 4; ++i ) {
		int temp_x,temp_y;
		temp_x = r + dir[i][0];
		temp_y = c + dir[i][1];
		if ( 0 <= temp_x && R > temp_x && 0 <= temp_y && C > temp_y && h[temp_x][temp_y] < h[r][c] ) {
			int temp = dp(temp_x,temp_y);
			res = max(res,temp);
		}
	}
	L[r][c] = ++res; 
	return L[r][c];
}

int main()
{
//	init array
	freopen("F://input.txt","r",stdin);
	cin >> R >> C;
	h = new int * [R];
	L = new int * [R];
	for ( int i = 0; i < R; ++i ) {
		h[i] = new int[C];
		L[i] = new int[C];
		for ( int j = 0; j < C; ++j ) {
			cin >> h[i][j];
			L[i][j] = 0;
		}
	} 
//	solve problem
	for ( int i = 0; i < R; ++i ) {
		for ( int j = 0; j < C; ++j ) {
			int temp = dp(i,j);
			result = result > temp? result : temp;
		}
	}
	cout << result << endl;
//	delete the array memory
	for ( int i = 0; i < R; ++i ) {
		delete[] h[i];
		delete[] L[i];
	}
	delete[] h;
	delete[] L;
	return 0;
}
