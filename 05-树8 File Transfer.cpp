#include <iostream>
using namespace std;

int N;
int * id;
int * size;

int find(int a)
{
	if( a == id[a] )	return a;
	else	return id[a] = find(id[a]);
}

void check(int a, int b)
{
	int a_root = find(a);
	int b_root = find(b);
	cout << (a_root == b_root? "yes" : "no") << endl;
}

void connect(int a, int b)
{
	int a_root = find(a);
	int b_root = find(b);
	if ( a_root == b_root )	return;
	else if ( size[a_root] >= size[b_root] ) {
		id[b_root] = a_root;
		size[a_root] += size[b_root];
	}
	else {
		id[a_root] = b_root;
		size[b_root] += size[a_root];
	}
}

void showResult()
{
	int count = 0;
	int * index = new int[N + 1];
	for ( int i = 1; i <= N; i++ )	index[i] = i;
	for ( int i = 1; i <= N; i++ ) {
		int root = find(i);
		index[root] = 0;
	}	
	for ( int i = 1; i <= N; i++ ) {
		if ( !index[i] )	count++;
	}
	if ( 1 == count )	cout << "The network is connected." << endl;
	else	cout << "There are " << count << " components." << endl;
}

int main()
{
//	freopen("F://input.txt","r",stdin);
	cin >> N;
	id = new int[N + 1];
	size = new int[N + 1]; 
	for ( int i = 1; i <= N; i++ )	id[i] = i;
	for ( int i = 1; i <= N; i++ )	size[i] = 1;
//	????
	string inp;
	getline(cin,inp);
	while ( true ) {
		getline(cin,inp);
		if ( 'S' == inp[0] )	break;
		int a = inp[2] - '0';
		int b = inp[4] - '0';
		if ( 'C' == inp[0] )	check(a,b);
		else	connect(a,b);
	}	
	showResult();
//	for ( int i = 1; i <= 5; i++ ) cout << id[i] << " ";
	delete[] id;
	delete[] size;
	return 0;
}
