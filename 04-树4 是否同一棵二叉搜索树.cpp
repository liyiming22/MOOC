#include <iostream>
using namespace std;

int N,L;

typedef int ElementType;
typedef struct Node * ptrToNode;
struct Node{
	ptrToNode lch;
	ptrToNode rch;
	ElementType data;
};
typedef ptrToNode BinTree;

BinTree Insert(BinTree BST, ElementType X)
{
	if ( !BST )	{
		BST = new struct Node;
		BST -> lch = NULL;
		BST -> rch = NULL;
		BST -> data = X;
	}
	else if ( X < BST -> data )	BST -> lch = Insert(BST -> lch,X);
	else	BST -> rch = Insert(BST -> rch,X);
	return BST;
}

bool checkSame(BinTree iniTree,BinTree checkTree)
{
	if ( !iniTree && !checkTree )	return true;
	else if ( (!iniTree && checkTree) || (iniTree && !checkTree))	return false;	
	else if ( iniTree -> data != checkTree -> data )	return false;
//	iniTree -> data == checkTree -> data
	else	return checkSame(iniTree -> lch,checkTree -> lch) && checkSame(iniTree -> rch,checkTree -> rch);
}

int main()
{
	freopen("F://input.txt","r",stdin);
	while ( true ) {
		cin >> N >> L;
		if ( !N )	break;
		BinTree iniTree = NULL;
		BinTree checkTree = NULL;
		for ( int i = 0; i <= L ; i++ ) {
			for ( int j = 0; j < N; j++ ) {
				ElementType node;
				cin >> node;
				if ( !i )	iniTree = Insert(iniTree,node);
				else	checkTree = Insert(checkTree,node);
			}
			if ( 0 != i ) {
				bool res = checkSame(iniTree,checkTree);
				cout << (res? "Yes" : "No") << endl;
			}
		}
		delete iniTree;
		delete checkTree;
	}
	return 0;
}
