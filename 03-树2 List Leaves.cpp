#include <iostream>
#include <queue>
using namespace std;

int N;
const int null = -1;

typedef struct Node * ptrToNode;
struct Node{
	int lch;
	int rch;
};
typedef ptrToNode Tree;

int InitTree(struct Node * & tree, int n)
{
	int root = null;
	bool * check = new bool[n];
	for ( int i = 0; i < n; i++ )	check[i] = false;
	for ( int i = 0; i < n; i++ ) {
		char temp1, temp2;
		cin >> temp1 >> temp2;
		tree[i].lch = '-' == temp1? null : (temp1 - '0');
		tree[i].rch = '-' == temp2? null : (temp2 - '0');
		check[tree[i].lch] = true;
		check[tree[i].rch] = true;
	}
	for ( int i = 0; i < n; i++ ) {
		if ( !check[i] ) {
			root = i;
			break;
		}
	}
	return root;
}

void showLeaves(struct Node * tree, int root, int n)
{
	bool first_flag = true;
	queue <int> q;
	q.push(root);
	while ( !q.empty() ) {
		int node = q.front();
//		if ( -1 == tree[node].lch && -1 == tree[node].rch )	cout << (first_flag? "" : " ") << node;
		if ( -1 == tree[node].lch && -1 == tree[node].rch ) {
			if ( !first_flag )	cout << " ";
			else	first_flag = false;
			cout << node;
		}
		if ( -1 != tree[node].lch )	q.push(tree[node].lch);
		if ( -1 != tree[node].rch ) q.push(tree[node].rch);
		q.pop();
	}
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	Tree tree = new struct Node[N];
	int root = InitTree(tree,N);
	showLeaves(tree,root,N);
	return 0;
}

