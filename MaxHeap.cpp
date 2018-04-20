#include <iostream>
using namespace std;

const int MAX_SIZE = 50;
const int MAX_DATA = 1e3;
const int ERROR = -1;

typedef int ElementType;
typedef struct HeapStruct * MaxHeap;
struct HeapStruct{
	ElementType * Elements;
	int Size;
	int Capacity;
};

MaxHeap createHeap(int MaxSize)
{
	MaxHeap H = new struct HeapStruct;
	H -> Elements = new ElementType[MAX_SIZE + 1];
	H -> Elements[0] = MAX_DATA;
	H -> Capacity = MAX_SIZE; 
	H -> Size = 0;
	return H;
}

bool isFull(MaxHeap H)
{
	return H -> Size == H -> Capacity;
}

bool isEmpty(MaxHeap H)
{
	return H -> Size == 0;
}

void insertItem(MaxHeap H, ElementType item)
{
	if ( isFull(H) ) {
		cout << "Out of capacity!" << endl;
		return;
	}
	int pos = ++H -> Size;
//	从当前size的路径从下往上一路找到适合插入结点的位置 
	for ( pos; H -> Elements[pos / 2] < item; pos / 2)	H -> Elements[pos] = H -> Elements[pos / 2];
	H -> Elements[pos] = item;
}

ElementType deleteMax(MaxHeap H)
{
	if ( isEmpty(H) ) {
		cout << "Empty Heap!" << endl;
		return ERROR;
	}
//	删去最大的元素,并且插入最后一个元素到合适的位置 
	ElementType max_element = H -> Elements[1];
	ElementType temp = H -> Elements[H -> Size--];
	int parent = 1;
//	从上往下查找位置 
	for ( parent; parent * 2 <= H -> Size; parent = child ) {
		int child = parent * 2;
//		child指向左右两个孩子结点中较大的那一个 
		if (child < H -> Size && H -> Elements[child + 1] > H -> Elements[child] )	child++;
//		找到适合最后一个结点插入的位置(parent) 
		if ( temp >= H -> Elements[child] )	break;
		else	H -> Elements[parent] = H -> Elements[child];
	}
//	插入最后一个结点 
	H -> Elements[parent] = temp;
	return max_element;
}

/*void percDown(MaxHeap H, int p)
{
	
}

void buildHeap(MaxHeap H)
{
	
}*/

int main()
{
	return 0;
}

