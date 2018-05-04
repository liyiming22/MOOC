#include <iostream>
#include <stack>
using namespace std;

string num[51][51];

string plusString(string a, string b)
{
	string res;
	stack <char> s;
	bool flag = false;
	int i = a.length() - 1;
	int j = b.length() - 1;
	while ( 0 <= i && 0 <= j ) {
		int temp = a[i--] - '0' + b[j--] - '0';
		if ( flag ) {
			temp += 1;
			flag = false;
		}
		if ( 10 <= temp ) {
			temp -= 10;
			flag = true;
		}
		s.push(temp + '0');
	}
	while ( 0 <= i ) {
		int temp = a[i--] - '0';
		if ( flag ) {
			temp += 1;
			flag = false;
		}
		if ( 10 <= temp ) {
			temp -= 10;
			flag = true;
		}
		s.push(temp + '0');
	}
	while ( 0 <= j ) {
		int temp = b[j--] - '0';
		if ( flag ) {
			temp += 1;
			flag = false;
		}
		if ( 10 <= temp ) {
			temp -= 10;
			flag = true;
		}
		s.push(temp + '0');		
	}
	if ( flag )	s.push('1');
	while ( !s.empty() ) {
		res += s.top();
		s.pop();
	}	
	return res;
}

bool judgeMin(string a,string b)
{
	if ( a.length() != b.length() )	return a.length() < b.length();
	for ( int i = 0; '\0' != a[i]; ++i )
		if ( a[i] != b[i] )	return a[i] < b[i];
	return true;		
}

string dp(int M, int N, string inp)
{
	string res;
	if ( !M ) for ( int i = 0; i < N; ++i ) res += inp[i];
	else {
		string temp = plusString(num[M][N],dp(M - 1,M,inp));
		for ( int i = M; i < N - 1; ++i ) {
			string plus_dp = plusString(num[i + 1][N],dp(i,i + 1,inp));
			temp = judgeMin(temp,plus_dp)? temp : plus_dp;
		}		
		res = temp;
	}
	return res;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	int M;
	string inp;
	while ( cin >> M >> inp ) {
		for ( int i = 0; i < inp.length(); ++i )
		for ( int j = 0; j < inp.length(); ++j )
		for ( int pos = i; pos <= j; ++pos )	num[i][j] += inp[pos];	
		cout << dp(M,inp.length(),inp) << endl;		
		for ( int i = 0; i < inp.length(); ++i )
		for ( int j = 0; j < inp.length(); ++j )
		num[i][j] = "";
	}
	return 0;
}
