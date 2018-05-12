#include <iostream>
#include <cstring>
#include <stack> 
#include <cmath>
using namespace std;

int N;
int * bag;
int binaryExp[21];
int res = 0;
const int maxSize = 40;

void getBinary(int n)
{
	stack <int> s;
	int len = 0;
	while ( n ) {
		s.push(n % 2);
		n /= 2;
		len++;
	}
	for ( int i = N - len; i < N; ++i ) {
		binaryExp[i] = s.top();
		s.pop();
	}
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	bag = new int[N];
	for ( int i = 0; i < N; ++i ) cin >> bag[i];
	for ( int i = 0; i < pow(2,N); ++i ) {
		memset(binaryExp,0,sizeof(binaryExp));
		getBinary(i);
		int this_size = 0;
		for ( int j = 0; j < N; ++j ) {
			if ( binaryExp[j] )	this_size += bag[N - 1 - j];
		}
		if ( this_size == maxSize )	++res;
	}
	cout << res << endl;
	delete[] bag;
	return 0;
}
