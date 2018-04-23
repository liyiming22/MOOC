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

void check()
{
	int a,b;
	cin >> a >> b;
	int a_root = find(a);
	int b_root = find(b);
	cout << (a_root == b_root? "yes" : "no") << endl;
}

void connect()
{
	int a,b;
	cin >> a >> b;
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
	freopen("F://input.txt","r",stdin);
	cin >> N;
	id = new int[N + 1];
	size = new int[N + 1]; 
	for ( int i = 1; i <= N; i++ )	id[i] = i;
	for ( int i = 1; i <= N; i++ )	size[i] = 1;
	while ( true ) {
		char c;
		cin >> c; 
		if ( 'S' == c )	break;
		if ( 'C' == c )	check();
		else	connect();
	}	
	showResult();
	delete[] id;
	delete[] size;
	return 0;
}
