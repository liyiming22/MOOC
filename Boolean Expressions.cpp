#include <iostream>
#include <string>
using namespace std;

int pos = 0;
bool expression(string a);
bool termValue(string a);

bool factorValue(string a)
{
	bool res;
	if ( '(' == a[pos] ) {
		pos++;
		res = expression(a);
		pos++;
	}
	else if ( '!' == a[pos] )	res = termValue(a);
	else {
		if ( 'V' == a[pos] )	res = true;
		else	res = false;
		pos++;
	}
	return res;
}

bool termValue(string a)
{
	bool res;
	if ( '!' == a[pos] ) {
		pos++;
		res = !factorValue(a);
	}
	else	res = factorValue(a);
	return res;
}

bool expression(string a)
{
	bool res = termValue(a);
	bool more = true;
	while ( more ) {
		char c = a[pos];
		if ( '&' == c || '|' == c ) {
			pos++;
			bool value = termValue(a);
			if ( '&' == c )	res &= value;
			else	res |= value;
		}
		else	more = false;
	}
	return res;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	string inp;
	int count = 1;
	while (getline(cin,inp)) {
		pos = 0;
		int i = 0;
		string a;
		while ( '\0' != inp[i] ) {
			if ( ' ' != inp[i] )	a.push_back(inp[i]);
			i++;
		}
		cout << "Expression " << count++  << ": " << (expression(a)? "V" : "F") << endl;
	}
	return 0;
}

