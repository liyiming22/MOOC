#include <iostream>
using namespace std;

int place(int M, int N)
{
	if ( 0 == M )	return 1;
	else if ( 0 == N )	return 0;
//	������������ƻ����ʱ���ض����ٻ���N - M�����ӿյģ������൱��M�����ӣ�M��ƻ�� 
	else if ( M < N )	return place(M,M);
	else {
		int count = 0;
//	û�п����� 
		count += place(M - N,N);
//	�п����� 
		count += place(M,N - 1);
		return count;
	}
}

int main()
{
	int t;
	cin >> t;
	while ( t-- ) {
		int M,N;
		cin >> M >> N;
		cout << place(M,N) << endl;
	}
	return 0;
}

