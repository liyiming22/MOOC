#include <iostream>
using namespace std;

//	m表示可以出现的最大数 
int divide(int n, int m)
{
	if ( 1 == n || 1 == m )	return 1;
//	当n小于最大的数m时，显然时不可能出现负数的，所以相当于最大数为n 
	else if ( n < m )	return divide(n,n);
//	含最大数m(n)时，只有一种，就是数字本身。不包含最大数时，取小于一的第二大数 
	else if ( n == m )	return 1 + divide(n,m - 1);
	else	return divide(n - m,m) + divide(n,m - 1);
/**
	当n>m时，分为两种情况。
	1.包含最大数m，那么剩下的和就是n - m。
	2.不包含最大数m，即划分中所有的数都比m小，那么取m - 1个划分。 
**/	
}

int main()
{
	int N;
	while ( cin >> N )	cout << divide(N,N) << endl;
	return 0;
}

