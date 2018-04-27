#include <iostream>
using namespace std;

int N;
int * A;

int setPivot(int * & A, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = A[low];
	while ( i < j ) {
//		move pointer to right
		while ( i < j && pivot >= A[i] )	i++;
//		move pointer to left
		while ( i < j && pivot < A[j] )		j--;
//		find two positions,swap		
		if ( i < j )	swap(A[i++],A[j--]);
	}
	if ( A[i] > pivot )	swap(A[low],A[--i]);
	else	swap(A[low],A[i]);
	return i;
}

void quickSort(int * & A, int low, int high)
{
	if ( low < high ) {
		int pivot = setPivot(A,low,high);
		quickSort(A,low,pivot - 1);
		quickSort(A,pivot + 1,high);
	}
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	A = new int[N];
	for ( int i = 0; i < N; i++ )	cin >> A[i];
	quickSort(A,0,N - 1);
	for ( int i = 0; i < N; i++ )	cout << A[i] << " ";
	delete[] A;
}
