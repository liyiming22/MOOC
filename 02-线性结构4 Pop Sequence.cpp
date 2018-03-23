#include <iostream>
#include <malloc.h>
using namespace std;

typedef int ElemType;
typedef int Position;
const ElemType ERROR = -1;

struct SNode{
	ElemType * Data;
	Position top;
	int MaxSize;
};
typedef struct SNode * Stack;

Stack Create( int MaxSize )
{
	Stack s = (Stack)malloc(sizeof(struct SNode));
	s -> Data = (ElemType *)malloc(MaxSize * sizeof(ElemType));
	s -> top = -1;
	s -> MaxSize = MaxSize;
	return s;
}

bool isFull( Stack s )
{
	return ( s -> MaxSize - 1 == s -> top );
	return false;
}

bool isEmpty( Stack s )
{
	return ( -1 == s -> top );
}

bool push( Stack s, ElemType e )
{
	if ( isFull(s) )	return false;
	s -> Data[++(s -> top)] = e;
	return true;
}

ElemType pop( Stack s )
{
	if ( isEmpty(s) )	return ERROR;
	return s -> Data[(s -> top)--];		
}

int main()
{
	freopen("F://input.txt","r",stdin);
	int M,N,K;
	cin >> M >> N >> K;
	while (K) {
		Stack s;
		s = Create(M);
		int ptr;
		cin >> ptr;
		int check = N;
		int start = 1;
		s -> Data[s -> top] = -1;
		while (check) {
//			栈顶元素和当前输入的元素相等 
			if ( s -> Data[s -> top] == ptr ) {
				ElemType temp = pop(s);
//				start控制下一次批量放入堆栈的起点 
				start = (ptr >= start? ptr + 1 : start);
				check--;
//				如果一整行都check完毕了，那么就防止把下一行的输入在这一行 
				if ( check )	cin >> ptr;
			}
//			栈顶元素和当前元素不等 
			else if ( s -> Data[s -> top] != ptr ) {
//			从check完毕的起始点开始到当前值全部入栈 
				for ( int i = start; i <= ptr; i++ )	push(s,i);
			}
//			一种情况是栈满了但是当前值并不等于栈顶元素，即再也放不进去了 
			if ( isFull(s) && ptr != s -> Data[s -> top] )	break;
//			第二种情况是栈顶元素比当前值还要大，按照逻辑当前值必定先于其输出，不合逻辑 
			if ( ptr < s -> Data[s -> top] )	break;
		}
//		注意不要忘了把当前行所有值读入完毕 
		for ( int i = 1; i < check; i++ )	cin >> start;
		cout << (check? "NO" : "YES") << endl;
		K--; 
	}
	return 0;
}

