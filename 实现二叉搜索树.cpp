#include <iostream>
#include <malloc.h>
using namespace std;

typedef int ElemType;
const ElemType ERROR = -1; 

typedef struct Node * PtrToNode;
struct Node{
	PtrToNode lch;
	PtrToNode rch;
	ElemType data;
}; 
typedef PtrToNode BinTree; 

BinTree Insert(ElemType X, BinTree & BST)
{
//	树空，就建立一个根节点 
	if ( NULL == BST )	{
		BST = new struct Node;
		BST -> lch = NULL;
		BST -> rch = NULL;
		BST -> data = X;
	}
	else if ( X < BST -> data )
		BST -> lch = Insert(X,BST -> lch);
	else if ( X > BST -> data )
		BST -> rch = Insert(X,BST -> rch);
	return BST;
}

ElemType FindMax(BinTree BST)
{
//	空树，返回错误 
	if ( !BST )	return ERROR;
	ElemType max_node_data;
	while ( BST ) {
		max_node_data = BST -> data;
		BST = BST -> rch;
	}
	return max_node_data;
}

bool Search(ElemType X, BinTree BST)
{
	if ( !BST )	return false;
	if ( X == BST -> data )	return true;
	else if ( X < BST -> data)	return Search(X,BST -> lch);
	else	return Search(X,BST -> rch);	
}

int main()
{
	BinTree root;
	for ( int i = 1; i < 5; i++ )	root = Insert(i,root);
//	cout << FindMax(root) << endl;
//	cout << Search(2,root);
	return 0;
}

