#include <iostream>
using namespace std;

//	m��ʾ���Գ��ֵ������ 
int divide(int n, int m)
{
	if ( 1 == n || 1 == m )	return 1;
//	��nС��������mʱ����Ȼʱ�����ܳ��ָ����ģ������൱�������Ϊn 
	else if ( n < m )	return divide(n,n);
//	�������m(n)ʱ��ֻ��һ�֣��������ֱ��������������ʱ��ȡС��һ�ĵڶ����� 
	else if ( n == m )	return 1 + divide(n,m - 1);
	else	return divide(n - m,m) + divide(n,m - 1);
/**
	��n>mʱ����Ϊ���������
	1.���������m����ôʣ�µĺ;���n - m��
	2.�����������m�������������е�������mС����ôȡm - 1�����֡� 
**/	
}

int main()
{
	int N;
	while ( cin >> N )	cout << divide(N,N) << endl;
	return 0;
}

