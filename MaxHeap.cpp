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

/*----------- 建造最大堆 -----------*/
void PercDown( MaxHeap H, int p )
{ /* 下滤：将H中以H->Data[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;
 
    X = H->Data[p]; /* 取出根结点存放的值 */
    for( Parent=p; Parent*2<=H->Size; Parent=Child ) {
        Child = Parent * 2;
        if( (Child!=H->Size) && (H->Data[Child]<H->Data[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= H->Data[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
}
 
void BuildHeap( MaxHeap H )
{ /* 调整H->Data[]中的元素，使满足最大堆的有序性  */
  /* 这里假设所有H->Size个元素已经存在H->Data[]中 */
 
    int i;
 
    /* 从最后一个结点的父节点开始，到根结点1 */
    for( i = H->Size/2; i>0; i-- )
        PercDown( H, i );
}

int main()
{
	return 0;
}

