#include <iostream>
using namespace std;

long long N,K;
long long * maxHeap;
long long size = 0;

void insertItem(long long * maxHeap)
{
	long long item;
	cin >> item;
	long long pos = ++size;
	for  ( pos; maxHeap[pos / 2] <= item; pos /= 2 )	maxHeap[pos] = maxHeap[pos / 2];
	maxHeap[pos] = item;
}

long long deleteItem(long long * maxHeap)
{
	long long max_item = maxHeap[1];
	long long item = maxHeap[size--];
	long long parent = 1;
	long long child;
	for ( parent; size >= parent * 2; parent = child ) {
		child = parent * 2;
		if ( child < size && maxHeap[child] < maxHeap[child + 1] )	child++;
		if ( item > maxHeap[child] )	break;
		else	maxHeap[parent] = maxHeap[child];
	}
	maxHeap[parent] = item;	
	return max_item;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	maxHeap = new long long[N + 1];
	maxHeap[0] = 1e9;
	for ( long long i = 0; i < N; i++ )	insertItem(maxHeap);
	cin >> K;
	for ( long long i = 0; i < K; i++ )	cout << deleteItem(maxHeap) << endl;
	delete[] maxHeap;
}
