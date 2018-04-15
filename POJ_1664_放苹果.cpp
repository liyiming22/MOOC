#include <iostream>
using namespace std;

int place(int M, int N)
{
	if ( 0 == M )	return 1;
	else if ( 0 == N )	return 0;
//	当盘子数量比苹果大时，必定至少会有N - M个盘子空的，所以相当于M个盘子，M个苹果 
	else if ( M < N )	return place(M,M);
	else {
		int count = 0;
//	没有空盘子 
		count += place(M - N,N);
//	有空盘子 
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

