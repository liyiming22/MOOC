#include <iostream>
using namespace std;

// 在线处理
int fun ( int *array, int N )
{
	int thisSum = 0;
	int maxSub = 0;
	for ( int i = 0; i < N; i++ ) {
		thisSum += array[i];
		if ( thisSum > maxSub )	maxSub = thisSum;
		if ( thisSum < 0 )	thisSum = 0;
	}
	return maxSub;
}

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

int main()
{
	// freopen("F://input.txt","r",stdin);
	int N;
	cin >> N;
	int array[N];
	for ( int i = 0; i < N; i++ )	cin >> array[i];
	int res = fun( array, N );
	cout << res;	
	return 0;
}

