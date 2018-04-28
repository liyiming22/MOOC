#include <iostream>
#include <algorithm>
using namespace std;

long long * A;

long long arrangeRight(long long low, long long high, long long k)
{
	long long i = low;
	long long j = high;
	long long pivot = A[low];
	if ( i < j ) {
		while ( i < j && A[i] <= pivot )	i++;
		while ( i < j && A[j] > pivot )	j--;
		if ( i < j )	swap(A[i++],A[j--]);
	}
	if ( A[i] > pivot )	i--;
	swap(A[low],A[i]);
	return i;
}

void arrange(long long low, long long high, long long k)
{
	long long pivot = arrangeRight(low,high,k);
	long long a = high - pivot + 1;
	if ( a == k )	return;
	else if ( a < k )	arrange(0,pivot - 1,k - a);
	else	arrange(pivot + 1,high,k);
}

bool Cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	long long N,K;
	cin >> N;
	A = new long long[N];
	for ( long long i = 0; i < N; i++ )	cin >> A[i];
	cin >> K;
	arrange(0,N - 1,K);
	long long * B = new long long[K];
	for ( long long i = 0; i < K; i++ )	B[i] = A[N - K + i];
	sort(B,B + K,Cmp);
	for ( long long i = 0; i < K; i++ )	cout << B[i] << endl;
	delete[] A;
	delete[] B;
	return 0;
}
