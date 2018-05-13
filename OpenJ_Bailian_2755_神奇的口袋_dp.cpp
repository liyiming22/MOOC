#include <iostream>
using namespace std;

const int MAX_SIZE = 40;
int N;
int * bags;
int ** dp;

int main()
{
//	freopen("F://input.txt","r",stdin);
	cin >> N;
	bags = new int[N + 1];
	dp = new int * [MAX_SIZE + 1];
	for ( int i = 0; i <= MAX_SIZE; ++i )	dp[i] = new int[N + 1];
	for ( int i = 1; i <= N; ++i ) {
		cin >> bags[i];
		dp[0][i] = 1;
	}
	dp[0][0] = 1;
//	solve problems
	for ( int i = 1; i <= MAX_SIZE; ++i ) {
		for ( int j = 1; j <= N; ++j ) {
			dp[i][j] = dp[i][j - 1];
			if ( bags[j] <= i )	dp[i][j] += dp[i - bags[j]][j - 1];
		}
	}
	cout << dp[MAX_SIZE][N] << endl;
// 	delete arrays
	for ( int i = 0; i <= MAX_SIZE; ++i )	delete[] dp[i];
	delete[] bags;
	delete[] dp;		
	return 0;
}
