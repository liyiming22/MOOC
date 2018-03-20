#include <iostream>
using namespace std;

typedef struct tagLNode{
	int addr;
	int data;
	int nextAddr;
	struct tagLNode * next;
} LNode;
typedef struct tagLNode *ptrToNode;
const int MAX_SIZE = 100000;

void showList(LNode * head)
{
	LNode * p = head;
	while ( p ) {
//		cout << p -> addr << " " << p -> data << " " << p -> nextAddr << endl;
		if ( p -> next )
			printf("%05d %d %05d\n",p -> addr, p -> data, p -> nextAddr);
		else
			printf("%05d %d %d\n",p -> addr, p -> data, p -> nextAddr);
		p = p -> next;
	}
}

void Reverse(LNode * a, int N, int K)
{
//	K %= N;
	if ( 1 == K ) {
		showList(&a[1]);
		return;
	}
	int i = 1;
	LNode res[N + 1];
	for ( i = 1 ; i < K + 1; i++ ) {
		res[i].addr = a[K + 1 - i].addr;
		res[i].data = a[K + 1 - i].data;
		res[i].nextAddr = K == i? -1 : a[K - i].addr;
		res[i].next = K == i? NULL : &res[i + 1];
	}
	if ( i < N ) {
		res[i - 1].nextAddr = a[i].addr;
		res[i - 1].next = &a[i];
		while ( i <= N ) {
			res[i].addr = a[i].addr;
			res[i].data = a[i].data;
			res[i].nextAddr = a[i].nextAddr;
			res[i].next = a[i].next;
			i++;
		}	
	}
//	cout << res[5].addr << endl;
	showList(&res[1]);
}

/*LNode * Reverse(LNode * head, int N, int K)
{
	int i = 1;
	LNode * p = head + K;
	LNode res[N + 1];
	for ( ; i < K + 1; i++ ) {
		res[i].addr = a[K + 1 - i].addr;
		res[i].data = a[K + 1 - i].data;
		res[i].nextAddr = K == i? -1 : a[K - i].addr;
		res[i].next = K == i? NULL : &res[i + 1];
	}
	return &res[1];
}*/

int main()
{
	freopen("F://input.txt","r",stdin);
	int firstAddr;
	int N,K;
	cin >> firstAddr >> N >> K;
	LNode a[N + 1];
	int data[MAX_SIZE];
	int temp_nextAddr[MAX_SIZE];
//	use index as array address
	for ( int i = 1; i < N + 1; i++ ) {
		int temp;
		cin >> temp;
		cin >> data[temp] >> temp_nextAddr[temp];
		if ( firstAddr == temp ) {
			a[1].addr = temp;
			a[1].data = data[temp];
			a[1].nextAddr = temp_nextAddr[temp];
		}
	}
//	init array
	for ( int i = 2; i < N + 1; i++ ) {
		a[i].addr = a[i - 1].nextAddr;
		a[i].data = data[a[i].addr];
		a[i].nextAddr = temp_nextAddr[a[i].addr];
		if ( -1 == a[i].nextAddr )	a[i].next = NULL;
		else	a[i].next = &a[i + 1];
	}
	a[1].next = 1 == N? NULL : &a[2];
//	for ( int i = 1; i < N + 1; i++ )
//		cout << a[i].addr << " " << a[i].data << " " << a[i].nextAddr << endl;
//	cout << a[1].next -> data;
//	LNode * head = NULL;
//	head = Reverse(a,N,K);
//	showList(head);
	Reverse(a,N,K);
	return 0;
}

