#include <iostream>
using namespace std;

int N;
int * A;

void mergeArray(int * & A, int low, int high)
{
	int cnt = 0;
	int * B = new int[high - low + 1];
	int mid = low + (high - low) / 2;
	int i = low;
	int j = mid + 1;
	while( mid + 1 > i && high + 1 > j ) {
		if ( A[i] < A[j] )	B[cnt++] = A[i++];
		else	B[cnt++] = A[j++];
	}
	while( mid + 1 > i )	B[cnt++] = A[i++];
	while( high + 1 > j )	B[cnt++] = A[j++];
//	A:loop from low, B:loop from 0 
	for ( i = low, cnt = 0; i < high + 1; i++ )	A[i] = B[cnt++];
	delete[] B;
}

void mergeSort(int * & A, int low, int high)
{
	if ( low < high) {
		int mid = low + (high - low) / 2;
		mergeSort(A,low,mid);
		mergeSort(A,mid + 1,high);
		mergeArray(A,low,high);
	}
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	A = new int[N];
	for ( int i = 0; i < N; i++ )	cin >> A[i];
	mergeSort(A,0,N - 1);
	for ( int i = 0; i < N; i++ )	cout << A[i] << " ";
	delete[] A;
}
