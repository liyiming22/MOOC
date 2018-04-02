#include <iostream>
#include <cmath>
using namespace std;

int N;
int res[30];
 
void solve(int K)
{
	if ( N == K ) {
		for ( int i = 0; i < N; i++ ) printf("%s%d",(0 == i? "" : " "), res[i] + 1);
		printf("\n");
		return;
	}
//	将当前皇后摆放在i列上 
	for ( int i = 0; i < N; i++ ) {
//		判断是否和前面摆列好的N行皇后发生冲突 
		int j;
		for ( j = 0; j < K; j++ ) {
//			冲突就退出当前循环，即放在当前列不可行 
			if ( res[j] == i || ( abs( res[j] - i ) == abs( K - j )  ) )	break;
		} 
//		和所有已经排列好的皇后没有冲突，那么上一个循环正常退出，即K - 1 == j 
		if ( K == j ) {
			res[K] = i;
//			当前皇后摆放没有问题，摆放下一个 
			solve(K + 1); 
		}
	}
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	solve(0);
	return 0;
}

