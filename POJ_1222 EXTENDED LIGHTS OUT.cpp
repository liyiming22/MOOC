#include <iostream>
#include <stack>
using namespace std;

void showPuzzle(int puzzle[6][8])
{
	for ( int i = 1; i <= 5; i++ ) {
		for ( int j = 1; j <= 6; j++ ) {
			printf("%s%d",1 == j? "" : " ",puzzle[i][j]);
		}
		cout << endl;
	}
}

void transform(int N, int press[6][8])
{
	if (!N)	return;
	int len = 0;
	stack <int> s;
	while ( N ) {
		s.push(N % 2);
		N /= 2;
		len++;	
	}
	for ( int i = 6 - len + 1; i <= 6; i++ ) {
		press[1][i] = s.top();
		s.pop();
	}
}

void Guss(int pu[6][8],int pr[6][8])
{
	int puzzle[6][8],press[6][8];
	for ( int N = 0; N <= 63; N++ ) {
//		恢复原先亮灯情况 
		for ( int i = 0; i < 6; i++ ) {
			for ( int j = 0; j < 8; j++ ) {
				puzzle[i][j] = pu[i][j];
				press[i][j] = pr[i][j];
			}
		}
//		第一行按键转换为二进制 
		transform(N,press);
		for ( int i = 1; i <= 4; i++ ) {
			for ( int j = 1; j <= 6; j++ ) {
//				改变第一行到第四行当前行的亮灯情况
				puzzle[i][j] = (puzzle[i][j] + press[i][j] + press[i][j - 1] + press[i][j + 1] + press[i - 1][j]) % 2;
//				根据当前行状态确定下一行的按键 
				press[i + 1][j] =  puzzle[i][j] % 2;
			}
		}
//		判断第五行是否全部熄灭
		bool flag = true;
		for ( int i = 1; i <= 6; i++ ) {
			puzzle[5][i] = (puzzle[5][i] + press[5][i] + press[5][i - 1] + press[5][i + 1] + press[4][i]) % 2;
			if (puzzle[5][i]) {
				flag = false;
				break;
			}
		}
		if (flag)	showPuzzle(press);
	}
}

int main()
{
	freopen("F://input.txt","r",stdin);
	int N;
	cin >> N;
	int count = 0;
	int puzzle[6][8];
	int press[6][8];
	while( count < N ) {
		for ( int i = 0; i < 6; i++ )
		for ( int j = 0; j < 8; j++ )
			press[i][j] = 0;
		for ( int i = 1; i <= 5; i++ )
		for ( int j = 1; j <= 6; j++ )
			cin >> puzzle[i][j];
			cout << "PUZZLE #" << ++count << endl; 
		Guss(puzzle,press);
	}
	return 0;
}
