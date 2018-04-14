#include <iostream>
using namespace std;

int step(int N)
{
	if ( 1 == N )	return 1;
	else if ( 2 == N )	return 2;
	else	return step(N - 1) + step(N - 2);
}

int main()
{
	int N;
	cin >> N;
	cout << step(N) << endl;;
	return 0;
}

