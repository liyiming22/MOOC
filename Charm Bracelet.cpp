#include <iostream>
using namespace std;

int N,M;

int * w;
int * v;
int dp[35000];

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N >> M;
	w = new int[N + 1];
	v = new int[N + 1];
	for ( int i = 1; i <= N; ++i )	cin >> w[i] >> v[i];
//	solove problem
	for ( int i = 1; i <= N; ++i ) {
		for ( int j = M; j >= w[i]; --j ) {
			dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[M] << endl;
	delete[] w;
	delete[] v;
	return 0;
}

