#include <iostream>
#include <memory.h>
using namespace std;

int maxLen[1000][1000];

int main()
{
	freopen("F://input.txt","r",stdin);
	string a,b; 
	while ( cin >> a >> b ) {
		int lenA = a.length();
		int lenB = b.length();
		memset(maxLen,0,sizeof(maxLen));
		for ( int i = 1; i <= lenA; i++ ) {
			for ( int j = 1; j <= lenB; j++ ) {
				if ( a[i - 1] == b[j - 1] )	maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
				else	maxLen[i][j] = max(maxLen[i - 1][j],maxLen[i][j - 1]);
			}
		}
		cout << maxLen[lenA][lenB] << endl;
	}
	return 0;
}
