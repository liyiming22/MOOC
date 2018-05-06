#include <iostream>
#include <memory.h>
using namespace std;

int N;
int count = 1;
int dp[201][201];

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	while ( N-- ) {
		string a,b,c;
		cin >> a >> b >> c;
		int lenA = a.length();
		int lenB = b.length();
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for ( int i = 0; i <= lenA; ++i ) {
			for ( int j = 0; j <= lenB; ++j ) {
				if ( i > 0 && dp[i - 1][j] && a[i - 1] == c[i + j - 1] )	dp[i][j] = 1;
				if ( j > 0 && dp[i][j - 1] && b[j - 1] == c[i + j - 1] )	dp[i][j] = 1;
			} 
		}
		cout << "Data set " << count++ << ": ";
		printf("%s\n",dp[lenA][lenB]? "yes" : "no");
	}
	return 0;
}
