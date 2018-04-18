#include <iostream>
#include <algorithm>
using namespace std;

const double PAI = 3.141592653589;
long long N,F;
long long slice;
double * R;
double max_r;
double res;

double proportion(double r)
{
	double area = r * r * PAI;
	return area;
}

long long cut(double mid)
{
	long long sum = 0;
	for ( long long i = 0; i < N; i++ )	sum += (int)(R[i] / mid);
	return sum;
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N >> F;
	R = new double[N];
	max_r = 0;
	for ( int i = 0; i < N; i++ ) {
		double r;
		cin >> r;
		R[i] = proportion(r);
		max_r = max(R[i],max_r);
	}
	res = 0;
	while ( res + 0.00001 < max_r ) {
		double mid = ( res + max_r ) / 2.0;
		slice = cut(mid);
		if ( slice > F )	res = mid;
		else	max_r = mid - 0.00001;
	}
	printf("%.3lf\n",res);
	delete[] R;
	return 0;
}

