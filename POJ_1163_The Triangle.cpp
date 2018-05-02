#include <iostream>
using namespace std;

const int MAX = 101;
int N;
int d[MAX][MAX];
int thisSum[MAX][MAX];

int MaxSum(int r, int c)
{
	if ( -1 != thisSum[r][c] )	return thisSum[r][c];
	if ( N == r ) return d[r][c];
	int a = MaxSum(r + 1,c);
	int b = MaxSum(r + 1,c + 1);
	thisSum[r][c] = max(a,b) + d[r][c];
	return thisSum[r][c];
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	for ( int i = 1; i <= N; i++ )
		for ( int j = 1; j <= i; j++ ) {
			cin >> d[i][j];
			thisSum[i][j] = -1;
		} 
	cout << MaxSum(1,1);
}
