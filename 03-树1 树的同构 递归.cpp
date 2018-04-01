#include <iostream>
using namespace std;

int N1, N2;
int root1 = -1;
int root2 = -1;
struct Node * tree1;
struct Node * tree2;

struct Node{
	int lch;
	int rch;
	char data;
}; 

int createTree(struct Node * & tree, int N)
{
	tree = new struct Node[N];
	bool * check = new bool[N];
	int root = -1;
	for ( int i = 0; i < N; i++ )	check[i] = false;
	for ( int i = 0; i < N; i++ ) {
		char temp1, temp2;
		cin >> tree[i].data >> temp1 >> temp2;
		tree[i].lch = '-' == temp1? -1 : (temp1 - '0');
		tree[i].rch = '-' == temp2? -1 : (temp2 - '0');
		check[tree[i].lch] = true;
		check[tree[i].rch] = true;
	}
//	find the root node
	for ( int i = 0; i < N; i++ ) {
		if ( !check[i] ) {
			root = i;
			break;
		}
	}
	delete[] check;
	return root;
}

bool isSimilar(int node1, int node2)
{
//	both empty
	if ( -1 == node1 && -1 == node2 )	return true;
//	one of them is empty
	if ( ( -1 == node1 && -1 != node2 ) || ( -1 != node1 && -1 == node2 ) )	return false;
//	roots are different
	if ( tree1[node1].data != tree2[node2].data )	return false;
//	both have no left subtree
	if ( -1 == tree1[node1].lch && -1 == tree2[node2].lch )
		return isSimilar(tree1[node1].rch, tree2[node2].rch);
//	no need to swap the left and the right
	if ( (-1 != tree1[node1].lch && -1 != tree2[node2].lch) && ( tree1[tree1[node1].lch].data == tree2[tree2[node2].lch].data ) )
		return isSimilar(tree1[node1].lch, tree2[node2].lch) && isSimilar(tree1[node1].rch, tree2[node2].rch);
//	need to swap the left and the right	
	else
		return isSimilar(tree1[node1].rch, tree2[node2].lch) && isSimilar(tree1[node1].lch, tree2[node2].rch);
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N1;	root1 = createTree(tree1,N1);
	cin >> N2;	root2 = createTree(tree2,N2);
	cout << (isSimilar(root1,root2)? "Yes" : "No") << endl;
//	if delete wrong answer 
	delete[] tree1;
	delete[] tree2;
	return 0;
}

