#include <iostream>
#include <stdlib.h>
using namespace std;

double expression()
{
	char s[20];
	cin >> s;
	switch( s[0] ) {
		case '+' : return expression() + expression();	
		case '-' : return expression() - expression();
		case '*' : return expression() * expression();
		case '/' : return expression() / expression();
		default : return  atof(s);
	}
}

int main()
{
	freopen("F://input.txt","r",stdin);
	printf("%lf\n",expression());
	return 0;
}

