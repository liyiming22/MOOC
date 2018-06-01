#include <iostream>
using namespace std;

const int INF = 1000;
int N,M;
int G[105][105];
int dist[105][105];

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N >> M;
	for ( int i = 1; i < N + 1; ++i )
		for ( int j = 1; j < N + 1; ++j ) {
//			if ( i == j )	G[i][j] = 0;
			G[i][j] = INF;			
		}
	for ( int i = 1; i < N + 1; ++i ) {
		int a,b;
		cin >> a >> b;
		cin >> G[a][b];
		G[b][a] = G[a][b];
	}
	for ( int i = 1; i < N + 1; ++i )
		for ( int j = 1; j < N + 1; ++j )
			dist[i][j] = G[i][j];	
	for ( int k = 1; k < N + 1; ++k ) {
		for ( int i = 1; i < N + 1; ++i ) {
			for ( int j = 1; j < N + 1; ++j ) {
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
			} 
		}
	}
	for ( int i = 1; i < N + 1; ++i ) {
		for ( int j = 1; j < N + 1; ++j )
			cout << dist[i][j] << " ";
		cout << endl; 
	} 
	int minV = -1;
	int thisWeight = 20000;
	for ( int i = 1; i < N + 1; ++i ) {
		int max_temp = 0;
		for ( int j = 1; j < N + 1; ++j ) {
			if ( INF != dist[i][j] )	max_temp = max(max_temp,dist[i][j]);
		}
		if ( 0 != max_temp && thisWeight > max_temp ) {
			thisWeight = max_temp;
			minV = i;
		}
	}
	cout << minV << " " << thisWeight << endl;
	return 0;
}
