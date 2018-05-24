#include <iostream>
#include <cstring>
using namespace std;

int N;
int count = 0;
int temp[11];
int res[10005][11];

void printRes()
{
	cout << count << endl;
	for ( int i = 1; i <= count; ++i ) {
		for ( int j = 1; j <= 10; ++j )	cout << res[i][j] << " ";
		cout << endl;
	}
}

void dfs(int thisPos, int thisSum)
{
	if ( 11 == thisPos ) {
		if ( N == thisSum ) {
			++count;
			for ( int i = 1; i <= 10; ++i )	res[count][i] = temp[i];
		}
		return;
	}
	else if ( N <= thisSum )	return;
	for ( int i = 1; i <= 3; ++i ) {
		temp[thisPos] = i;
		dfs(thisPos + 1,thisSum + i);
	}
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	memset(res,0,sizeof(res));
	memset(temp,0,sizeof(temp));
	dfs(1,0);
	printRes();
	return 0;
}
