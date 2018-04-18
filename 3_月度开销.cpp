#include <iostream>
using namespace std;

long long N,M;
int * per;
int mid;
int per_min = 1e6;
int per_max = 0;

bool judge(int mid)
{
	bool res;
	int count = 0;
	int cnt = 0;
	int sum = 0;
	for ( int i = 0; i < N; i++ ) {
		if ( cnt == M || sum + per[i] > mid ) {
			cnt = sum = 0;
			count++;
		}
		else if ( sum + per[i] <= mid ) {
			sum += per[i];
			cnt++;
		}
	}
	res = count <= M? true : false;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N >> M;
	per = new int[N];
	for ( int i = 0; i < N; i++ ) {
		cin >> per[i];
		if ( per_min > per[i] )	per_min = per[i];
		if ( per_max < per[i] )	per_max = per[i];
	}
	while ( per_min <= per_max ) {
		mid = (per_min + per_max) / 2;
		bool res = judge(mid);
		if ( res )	per_min = mid + 1;
		else	per_max = mid - 1;
	}
	cout << mid << endl;
	delete[] per;
	return 0;
}

