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
//	�ӵ�ǰsize��·����������һ·�ҵ��ʺϲ������λ�� 
	for ( pos; H -> Elements[pos / 2] < item; pos / 2)	H -> Elements[pos] = H -> Elements[pos / 2];
	H -> Elements[pos] = item;
}

ElementType deleteMax(MaxHeap H)
{
	if ( isEmpty(H) ) {
		cout << "Empty Heap!" << endl;
		return ERROR;
	}
//	ɾȥ����Ԫ��,���Ҳ������һ��Ԫ�ص����ʵ�λ�� 
	ElementType max_element = H -> Elements[1];
	ElementType temp = H -> Elements[H -> Size--];
	int parent = 1;
//	�������²���λ�� 
	for ( parent; parent * 2 <= H -> Size; parent = child ) {
		int child = parent * 2;
//		childָ�������������ӽ���нϴ����һ�� 
		if (child < H -> Size && H -> Elements[child + 1] > H -> Elements[child] )	child++;
//		�ҵ��ʺ����һ���������λ��(parent) 
		if ( temp >= H -> Elements[child] )	break;
		else	H -> Elements[parent] = H -> Elements[child];
	}
//	�������һ����� 
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

