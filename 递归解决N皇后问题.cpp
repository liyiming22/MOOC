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
//	����ǰ�ʺ�ڷ���i���� 
	for ( int i = 0; i < N; i++ ) {
//		�ж��Ƿ��ǰ����кõ�N�лʺ�����ͻ 
		int j;
		for ( j = 0; j < K; j++ ) {
//			��ͻ���˳���ǰѭ���������ڵ�ǰ�в����� 
			if ( res[j] == i || ( abs( res[j] - i ) == abs( K - j )  ) )	break;
		} 
//		�������Ѿ����кõĻʺ�û�г�ͻ����ô��һ��ѭ�������˳�����K - 1 == j 
		if ( K == j ) {
			res[K] = i;
//			��ǰ�ʺ�ڷ�û�����⣬�ڷ���һ�� 
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

