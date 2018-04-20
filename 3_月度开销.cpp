#include <iostream>
using namespace std;

long long N,M;
int * per;
int mid;
long long per_min = 0;
long long per_max = 0;

bool judge(int mid)
{
	bool res;
	int count = 1;
	int sum = 0;
	for ( int i = 0; i < N; i++ ) {
		if ( sum + per[i] <= mid )	sum += per[i];
//		else if ( per[i] <= mid ) {
		else {
			sum = per[i];
			count++;
		}	
// 		else return false;
	}
	res = count <= M? true : false;
	return res;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N >> M;
	per = new int[N];
	for ( int i = 0; i < N; i++ ) {
		cin >> per[i];
		if ( per_min < per[i] )	per_min = per[i];
		per_max += per[i];
	}
	while ( per_min < per_max ) {
		mid = (per_min + per_max) / 2;
		bool res = judge(mid);
		if ( res )	per_max = mid;
		else	per_min = mid + 1;
	}
	cout << per_min << endl;
	delete[] per;
	return 0;
}
