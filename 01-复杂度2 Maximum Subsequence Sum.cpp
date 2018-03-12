#include <iostream>
using namespace std;

// 笨方法
// int fun ( int *array, int N )
// {
// 	// int thisSum = 0;
// 	int maxSub = 0;
// 	for ( int i = 0; i < N; i++ ) {
// 		int thisSum = array[i];
// 		for ( int j = i + 1; j < N; j++ ) {
// 			thisSum += array[j];
// 			if ( thisSum > maxSub )	maxSub = thisSum;
// 		}
// 	}
// 	return maxSub;
// }

// 在线处理
void fun ( int *array, int N )
{
	//int maxSub = 0;
	float maxSub = -0.5;
	int thisSum = 0;
	int ini = array[0];
	int first = ini;
	int last = array[N - 1];
	int flag = 0;
	for ( int i = 0; i < N; i++ )	{
		thisSum += array[i];
		if ( maxSub < thisSum ) {
			maxSub = thisSum;
			last = array[i];
			first = ini;
			flag = 1;
		}
		if ( thisSum < 0 )	{
			thisSum = 0;
			ini = array[i + 1];
		}
	}
//	if ( 0 == maxSub && flag ) {
//		first = 0;
//		last = 0;
//	}
	if ( -0.5 == maxSub )	maxSub = 0;
	cout << maxSub << " " << first << " " << last;
}

int main()
{
//	freopen("F://input.txt","r",stdin);
	int N;
	cin >> N;
	int array[N];
	for ( int i = 0; i < N; i++ )	cin >> array[i];
	fun(array, N);
	// int res = fun( array, N );
	// cout << res;
	return 0;
}
