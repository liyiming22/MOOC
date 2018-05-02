#include <iostream>
using namespace std;

const int MAX = 101;
int N;
int d[MAX][MAX];
int maxSum[MAX];

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	for ( int i = 1; i <= N; i++ )
	for ( int j = 1; j <= i; j++ )	cin >> d[i][j];
	for ( int i = 1; i <= N; i++ )	maxSum[i] = d[N][i];
	for ( int i = N - 1; i >= 1; i-- )
		for ( int j = 1; j <= i; j++ ) {
			maxSum[j] = d[i][j] + max(maxSum[j],maxSum[j + 1]);
		}
	cout << maxSum[1];
	return 0;
}
