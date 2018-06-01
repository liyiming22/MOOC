// 21:22
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1000;
int N,M;
int weight[105][105];
int collected[105];
int dist[105];

int findMinDist()
{
	int minV;
	int temp = INF;
	for ( int i = 1; i < N + 1; ++i ) {
		if ( !collected[i] && dist[i] < temp ) {
			temp = dist[i];
			minV = i;
		}
	}
	if ( INF == temp )	return -1;
	else	return minV;
}

int Dijkstra(int pos)
{
	memset(collected,0,sizeof(collected));
	for ( int i = 1; i < N + 1; ++i ) {
		dist[i] = weight[pos][i];
	}
	dist[pos] = 0;
	collected[pos] = 1;
	while ( true ) {
		int v = findMinDist();
		if ( -1 == v )	break;
		collected[v] = 1;
		for ( int w = 1; w < N + 1; ++w ) {
			if ( !collected[w] && dist[w] > dist[v] + weight[v][w] )
				dist[w] = dist[v] + weight[v][w];
		}
	}
	int maxWeight = 0;
	for ( int i = 1; i < N + 1; ++i ) {
		if ( INF == dist[i] )	return -1;
		maxWeight = maxWeight > dist[i]? maxWeight : dist[i];
	}
	return maxWeight;
}

int main()
{
	int minV = -1;
	int thisWeight = 20000;
	freopen("F://input.txt","r",stdin);
	cin >> N >> M;
	for ( int i = 1; i < N + 1; ++i ) {
		for ( int j = 1; j < N + 1; ++j ) {
			weight[i][j] = INF;
		}
	}
	for ( int i = 0; i < M; ++i ) {
		int a,b;
		cin >> a >> b;
		cin >> weight[a][b];
		weight[b][a] = weight[a][b];
	}
	for ( int i = 1; i < N + 1; ++i ) {
		int temp = Dijkstra(i);
		if ( -1 != temp && temp < thisWeight ) {
			thisWeight = temp;
			minV = i;
		}
	}
	if ( -1 == minV )	cout << 0 << endl;
	else	cout << minV << " " << thisWeight << endl;
	return 0;
}
