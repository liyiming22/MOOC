#include <iostream>
using namespace std;

typedef struct HeapStruct * minHeap;
struct HeapStruct{
	int * elem;
	int size;
};

int N,M; 
minHeap H = new struct HeapStruct;

minHeap createHeap(int MaxSize)
{
	minHeap H = new struct HeapStruct;
	H -> elem = new int[MaxSize + 1];
	H -> elem[0] = -100000;
	H -> size = 0;
	return H;
}

void Insert(minHeap H, int e)
{
	int pos = ++H -> size;
	for ( pos; H -> elem[pos / 2] > e; pos /= 2 )	H -> elem[pos] = H -> elem[pos / 2];
	H -> elem[pos] = e;
}

void showElements(int start)
{
	int pos = start;
	for ( pos; pos > 0; pos /= 2 ) {
		cout << (pos == start? "" : " ");
		cout << H -> elem[pos]; 
	}
	cout << endl;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N >> M;
	H = createHeap(100000);
	for ( int i = 0; i < N; i++ ) {
		int e;
		cin >> e;
		Insert(H,e);
	}
	for ( int i = 0; i < M; i++ ) {
		int start;
		cin >> start;
		showElements(start);
	}
	delete H;
	return 0;
}

