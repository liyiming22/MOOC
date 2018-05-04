#include <iostream>
using namespace std;

int K;
int * inp;
int * dp;
int res = 0;

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> K;
	inp = new int[K + 1];
	dp = new int[K + 1];
	for ( int i = 1; i <= K; ++i ) {
		cin >> inp[i];
		dp[i] = 1;
	}
	for ( int i = 2; i <= K; ++i ) {
		int temp = 0;
		for ( int j = 1; j < i; ++j ) {
			if ( inp[i] <= inp[j] && dp[j] > temp )
				temp = dp[j];
		}
		dp[i] = temp + 1;
		res = res > dp[i]? res : dp[i];
	}
	cout << res;
	delete[] inp;
	delete[] dp;
	return 0;
}
