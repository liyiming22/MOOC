// 15:39
#include <iostream>
#include <stack>
using namespace std;

int N;
int preOrder[35];
int inOrder[35];
int postOrder[35]; 

void initOrder()
{
	stack <int> s;
	int preCount = 1;
	int inCount = 1;
	for ( int i = 1; i <= 2 * N; ++i ) {
		string temp;
		cin >> temp;
		if ( 'u' == temp[1] ) {
			cin >> preOrder[preCount];
			s.push(preOrder[preCount++]);
		}
		else {
			inOrder[inCount++] = s.top();
			s.pop();
		}
	}
}

void solve(int preL, int inL, int postL, int num)
{
	if ( 0 == num )	return;
	else if ( 1 == num ) {
		postOrder[postL] = preOrder[preL];
		return;
	}
	int root = preOrder[preL];
	postOrder[postL + num - 1] = root;
	int L;
	for ( L = 0; L <= num; ++L ) {
		if ( root == inOrder[inL + L] )	break;
	}
	solve(preL + 1,inL,postL,L);
	solve(preL + L + 1,inL + L + 1,postL + L,num - L - 1);
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	initOrder();
	solve(1,1,1,N);
	cout << postOrder[1];
	for ( int i = 2; i <= N; ++i )	cout << " " << postOrder[i];
	return 0;
}
