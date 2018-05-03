#include <iostream>
using namespace std;

int N;
int * a;
int * maxLen;

int solve()
{
	int total_max = 1;
	for ( int i = 1; i < N; i++ ) {
		int temp = 0;
		for ( int j = 0; j < i; j++ ) {
			if ( a[j] < a[i] && maxLen[j] > temp ) 
				temp = maxLen[j];
		}
		maxLen[i] = temp + 1;
		total_max = total_max > maxLen[i]? total_max : maxLen[i];
	}
	return total_max; 
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	a = new int[N];
	maxLen = new int[N];
	for ( int i = 0; i < N; i++ ) {
		cin >> a[i];
		maxLen[i] = 1;
	}
	cout << solve();
	delete[] a;
	delete[] maxLen;
	return 0; 
}
