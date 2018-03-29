#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
	int dad;
	int lch;
	int rch;
	char id;
};

int N1,N2;
int root1,root2;

//	pay attention to the "&" sign 
int initTree( struct Node * & tree, int N )
{
	tree = new struct Node[N];
	for ( int i = 0; i < N; i++ )	tree[i].dad = -1;
	for ( int i = 0; i < N; i++ )	{
		char temp1, temp2;
		cin >> tree[i].id >> temp1 >> temp2;
		tree[i].lch = '-' == temp1? -1 : (int)(temp1 % '0');
		tree[i].rch = '-' == temp2? -1 : (int)(temp2 % '0');
		if ( tree[i].lch >= 0 )	tree[tree[i].lch].dad = i;
		if ( tree[i].rch >= 0 )	tree[tree[i].rch].dad = i;
	}
//	find the root node
	int root;
	for ( int i = 0; i < N; i++ )	{
		if ( -1 == tree[i].dad )	{
			root = i;
			break;
		}
	}
	return root;
}

//void range(char * & A)
//{
//	int len = 0;
//	for ( int i = 0; '\0' != A[i]; i++ )	len++;
//	for ( int i = 0; i < len; i++ ) {
//		for ( int j = i + 1; j < len; j++ ) {
//			if ( A[i] > A[j] ) {
//				char temp = A[i];
//				A[i] = A[j];
//				A[j] = A[i];
//			}
//		}
//	} 
//}

void fun(char * A, int & length, const struct Node * tree, queue <int> q)
{
	int i;
	int len = length;
	for ( i = 0; i < len; i++ ) {
		int fro = q.front();
		if ( tree[fro].lch != -1 ) {
			q.push(tree[fro].lch);
			length++;
		}
		if ( tree[fro].rch != -1 ) {
			q.push(tree[fro].rch);
			length++;
		}
		A[i] = tree[fro].id;
		q.pop();
		length--;
	}
	A[i] = '\0';
	sort(A,A + i);
//	range(A);
}

void showArray(const char * A)
{
	for ( int i = 0; '\0' != A[i]; i++ )	cout << A[i] << " ";
	cout << endl;
}

void Solve(const struct Node * tree1, const struct Node * tree2)
{
//	if ( tree1[root1].id != tree2[root2].id )	{
//		cout << "No" << endl;
//		return;
//	}
	int len1 = 1;
	int len2 = 1;
	queue <int> q1;
	queue <int> q2;
	q1.push(root1);
	q2.push(root2);
	while ( !q1.empty() && !q2.empty() ) {
		char * A = new char[10];
		char * B = new char[10];
		fun(A,len1,tree1,q1);
		showArray(A);
		fun(B,len2,tree2,q2);
//		showArray(B);
		for ( int i = 0; '\0' != A[i] && '\0' != B[i]; i++ ) {
			if ( A[i] != B[i] ) {
				cout << "No" << endl;
				return;
			}
		}
		delete []A;
		delete []B;
	}
//	cout << "Yes" << sendl;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N1;
	struct Node * tree1;
	root1 = initTree(tree1,N1);
	cin >> N2;
	if ( N1 != N2 )	{
		cout << "No" << endl;
		return 0;
	}
	struct Node * tree2;
	root2 = initTree(tree2,N2);
//	cout << root1 << " " << root2 << endl;
//	for ( int i = 0; i < N2; i++ )	{
//		cout << tree2[i].id << " " << tree2[i].lch << " " << tree2[i].rch << endl;		
//	}
	Solve(tree1,tree2);
	delete tree1;
	delete tree2;
	return 0;
}

