#include <iostream>
#include <stack>
using namespace std;

int N;
int * preOrder;
int * inOrder;
int * postOrder;
int ini_root;

void initOrder()
{
	stack <int> s;
	cin >> N;
	preOrder = new int[N];
	inOrder = new int[N];
	int pre_cnt = 0;
	int in_cnt = 0;
	for ( int i = 0; i < 2 * N; ++i ) {
		string temp;
		cin >> temp;		
		if ( 'u' == temp[1] ) {
			int node;
			cin >> node;
			preOrder[pre_cnt++] = node;
			s.push(node);
		}
		else if ( 'o' == temp[1] ) {
			inOrder[in_cnt++] = s.top();
			s.pop();
		}
	}
}

int findRoot(int start, int end)
{
	if ( start == end )	return start;
	for ( int i = 0; i < N; ++i ) {
		for ( int j = start; j <= end; ++j ) {
			if ( preOrder[i] == inOrder[j] )	return j;
		}
	}
}

void postTravel(int start, int end, int root)
{
	if ( start == end )	root = end;
	else {
		int sub_root = findRoot(start,root - 1);
		if ( sub_root >= 0 ) postTravel(start,root - 1,sub_root);
		sub_root = findRoot(root + 1,end);
		if ( sub_root < N )	postTravel(root + 1,end,sub_root);
	}
	cout << inOrder[root];
	if ( root != ini_root )	cout << " ";
}

int main()
{
	freopen("F://input.txt","r",stdin);
	initOrder();
	ini_root = findRoot(0,N - 1);
	postTravel(0,N - 1,ini_root);
	delete[] preOrder;
	delete[] inOrder;
	delete[] postOrder;
	return 0;
}

