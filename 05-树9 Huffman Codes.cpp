#include <iostream>
#include <cmath>
using namespace std;

int N,M;

bool check(const long long * pos, const int M)
{
	for ( int i = 0; i < M; i++ ) {
		long long node1 = pos[i];
		for ( int j = i + 1; j < M; j++ ) {
			long long node2 = pos[j];
			if ( node1 == node2 / 2 || node2 == node1 / 2 )	return false;
		}
	}
	return true;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	string s;
	getline(cin,s);
	getline(cin,s);
	cin >> M;
	for ( int i = 0; i < M; i++ ) {
		long long * pos = new long long[N];
		for ( int j = 0; j < N; j++ ) {
			int sum = 1;
			char c;
			cin >> c >> s;
			for ( int i = 0; '\0' != s[i]; i++ ) {
				if ( '0' == s[i] )	sum *= 2;
				else	sum = sum * 2 + 1;
			}
			pos[j] = sum;
		}
		bool res = check(pos,N);
		cout << (res? "Yes" : "No") << endl;
		delete[] pos;		
	}
}
