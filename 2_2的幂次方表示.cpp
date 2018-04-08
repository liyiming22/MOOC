#include <iostream>
#include <cmath>
using namespace std;

int N;

int scanLimit(int n)
{
	int edge;
	for ( edge = 0; edge <= 15; edge++ ) {
		if ( n >= pow(2,edge) && n < pow(2,edge + 1) )
			break;
	}
	return edge;
}

void  express(int n)
{
	int temp = n;
	cout << 2;
	int edge = scanLimit(temp);
	if ( 0 == edge || 2 == edge )	cout << "(" << edge << ")";
	else if ( 1 == edge )	cout << "";
	else {
		cout << "(";
		express(edge);
		cout << ")";	
	}
	temp -= pow(2,edge);
	cout << (0 == temp? "" : "+");
	if ( 1 <= temp )	express(temp);
}

int main()
{
//	freopen("F://input.txt","r",stdin);
	cin >> N;
	express(N);
	return 0;
}

