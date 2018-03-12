#include <stdio.h>  
#include <stdlib.h>  
  
typedef int ElementType;  
typedef struct Node *PtrToNode;  
struct Node {  
    ElementType Data;  
    PtrToNode   Next;  
};  
typedef PtrToNode List;  
  
List Read(); /* 细节在此不表     （也就是说提交的时候可以不考虑，不过还是要写的！）    */  
void Print( List L ); /* 细节在此不表；空链表将输出NULL   （同上）*/  
  
List Merge( List L1, List L2 );  
  
int main()  
{  
    List L1, L2, L;  
    L1 = Read();  
    L2 = Read();  
    L = Merge(L1, L2);  
    Print(L);  
    Print(L1);  
    Print(L2);  
    return 0;  
} 

/* 你的代码将被嵌在这里 */
List Read()
{
	int N;
	scanf("%d",&N);
	List head = (List)malloc(sizeof(struct Node));
	head -> Next = NULL;
	List ptr = head;
	while(N) {
		List L = (List)malloc(sizeof(struct Node));
		int data;
		scanf("%d",&L -> Data);
		ptr -> Next = L;
		ptr = L;
		N--;
	}
	ptr -> Next = NULL;
	return head;
}

void Print( List L )
{
	List ptr = L -> Next;
	if ( ptr == NULL )	{
		printf("NULL");
	}
	while ( ptr )	{
		printf("%d ",ptr -> Data);
		ptr = ptr -> Next;
	}
	printf("\n");
}

List Merge ( List L1, List L2 )
{
	List head = ( List ) malloc ( sizeof(struct Node) );
	List p = head;
	List pa = L1 -> Next;
	List pb = L2 -> Next;
	while ( pa && pb )	{
		if( pa -> Data <= pb -> Data ) {
			p -> Next = pa;
			pa = pa -> Next;
		}
		else	{
			p -> Next = pb;
			pb = pb -> Next;
		}
		p = p -> Next;
	}
	p -> Next = ( pa? pa : pb );
	L1 -> Next = NULL;
	L2 -> Next = NULL;
	return head;
}