// 2018-5-24
// 19：10
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct node {
	int x;
	int y;
}Cro[100];

int N,D;
bool first_jump = true;
bool res_flag = false;
int visited[100];

double diction(int a, int b)
{
	double temp_x = pow(Cro[a].x - Cro[b].x,2);
	double temp_y = pow(Cro[a].y - Cro[b].y,2);
	double dic = sqrt(temp_x + temp_y);
	return dic;
}

bool judgeSafe(int pos)
{
	if ( (50 - abs(Cro[pos].x)) <= D || (50 - abs(Cro[pos].y)) <= D )
		return true;
	else return false;
}

void dfs(int pos)
{
	if ( res_flag )	return;
	if ( judgeSafe(pos) ) {
		res_flag = true;
		return;
	}
	for ( int i = 1; i <= N; ++i ) {
		double dic = diction(pos,i);
		if ( dic <= D && 0 == visited[i] ) {
			visited[i] = 1;
			dfs(i);
//			visited[i] = 0;
		}
		if ( res_flag )	break;
	}
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N >> D;
	if ( D >= 42.5 ) {
		cout << "Yes" << endl;
		return 0;
	}
	memset(visited,0,sizeof(visited));
	Cro[0].x = Cro[0].y = 0;
	for ( int i = 1; i <= N; ++i )	cin >> Cro[i].x >> Cro[i].y;
	for ( int i = 1; i <= N; ++i ) {
		double dic = diction(i,0);
		dic -= 7.5;
		if ( dic <= D ) {
			visited[i] = 1;
			dfs(i);
//			visited[i] = 0;
		}
		if ( res_flag )	break;
	}
	if ( res_flag )	cout << "Yes";
	else	cout << "No";
	cout << endl;
	return 0;
}
