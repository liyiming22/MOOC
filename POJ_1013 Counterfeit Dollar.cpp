#include <iostream>
#include <cstring>
using namespace std;

char Left[3][7];
char Right[3][7];
char res[3][7];
const bool light = true;
const bool heavy = false;

bool judge(char coin, bool light_flag)
{
	for ( int i = 0; i < 3; i++ ) {
		char *pLeft,*pRight;
		pLeft = light_flag? Left[i] : Right[i];
		pRight = light_flag? Right[i] : Left[i];
		switch( res[i][0] ) {
			case 'u':
				if ( strchr(pRight,coin) == NULL )
					return false;
				break;
			case 'e':
				if ( strchr(pRight,coin) || strchr(pLeft,coin) )
					return false;
				break;
			case 'd':
				if ( strchr(pLeft,coin) == NULL )
					return false;
				break;	
		}
	}
	return true;
}

int main()
{
//	freopen("F://input.txt","r",stdin);
	int N;
	cin >> N;
	while ( N-- ) {
		for ( int i = 0; i < 3; i++ )	cin >> Left[i] >> Right[i] >> res[i];
		for ( char coin = 'A'; coin <= 'L'; coin++ ) {
			if ( judge(coin,light) ) {
				printf("%c is the counterfeit coin and it is %s\n",coin,"light.");
				break;				
			}
			else if ( judge(coin,heavy) ) {
				printf("%c is the counterfeit coin and it is %s\n",coin,"heavy.");
				break;
			}
		}
	}
	return 0;
}

