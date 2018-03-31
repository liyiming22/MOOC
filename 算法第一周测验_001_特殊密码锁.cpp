#include <iostream>
#include <cmath>
using namespace std;

int getBit(char c, int pos)
{
	return (c >> pos) & 1;
}

void Flip(char * & res, int pos)
{
	if ( res[pos] == '1' )	res[pos] = '0';
	else	res[pos] = '1';
}

void showResult(int switches)
{
	int count = 0;
	while ( switches ) {
		int temp = switches % 2;
		if ( temp )	count++;
		switches /= 2;
	}
	cout << count << endl;
}

void solve(const int len, char * ori, char * exp)
{
	for ( int n = 0; n < pow(2,len); n++ ) {
		char * res = new char[30];
		bool flag = true;
		int switches = n;
		for ( int i = 0; i < len; i++ )	res[i] = ori[i];
		res[len] = '\0';
		for ( int i = len - 1; i >= 0; i-- ) {
			if ( getBit(switches,i) ) {
				if ( 0 == i )	Flip(res,len - 2);
				else if ( len - 1 == i )	Flip(res,1);
				else {
					Flip(res,i - 1);
					Flip(res,i + 1);
				}
				Flip(res,i);
			}
		}
		for ( int pos = 0; pos < len; ++pos ) {
			if ( res[pos] != exp[pos] ) {
				flag = false;
				break;
			}
		}
		if ( flag ) {
			showResult(switches);
			return; 
		}
		delete[] res;
	}
	cout << "impossible" << endl;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	int len = 0;
	char * ori = new char[30];
	char * exp = new char[30];
	cin >> ori;
	cin >> exp;
	for ( len; ori[len] != '\0'; ++len ); 
	solve(len,ori,exp);
	delete[] ori;
	delete[] exp;
	return 0;
}

