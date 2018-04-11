#include <iostream>
using namespace std;

//const string moves[9] = {"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
int * oriClock = new int[9];

void violent_enum()
{
	for ( int i = 0; i < 9; i++ )	cin >> oriClock[i];
	int b[9] = {0};
	int Clock[9] = {0};
	for ( b[0] = 0; b[0] < 4; b[0]++ )
	for ( b[1] = 0; b[1] < 4; b[1]++ )
	for ( b[2] = 0; b[2] < 4; b[2]++ )
	for ( b[3] = 0; b[3] < 4; b[3]++ )
	for ( b[4] = 0; b[4] < 4; b[4]++ )
	for ( b[5] = 0; b[5] < 4; b[5]++ )
	for ( b[6] = 0; b[6] < 4; b[6]++ )
	for ( b[7] = 0; b[7] < 4; b[7]++ )
	for ( b[8] = 0; b[8] < 4; b[8]++ )
	{
		Clock[0] = (oriClock[0] + b[0] + b[1] + b[3]) % 4;
		Clock[1] = (oriClock[1] + b[0] + b[1] + b[2] + b[4]) % 4;
		Clock[2] = (oriClock[2] + b[1] + b[2] + b[5]) % 4;
		Clock[3] = (oriClock[3] + b[0] + b[3] + b[4] + b[6]) % 4;
		Clock[4] = (oriClock[4] + b[0] + b[2] + b[4] + b[6] + b[8]) % 4;	
		Clock[5] = (oriClock[5] + b[2] + b[4] + b[5] + b[8]) % 4;
		Clock[6] = (oriClock[6] + b[3] + b[6] + b[7]) % 4;
		Clock[7] = (oriClock[7] + b[4] + b[6] + b[7] + b[8]) % 4;
		Clock[8] = (oriClock[8] + b[5] + b[7] + b[8]) % 4;
		int temp = 0;
		for ( int i = 0; i < 9; i++ )	temp += Clock[i];
		if ( 0 == temp )	{
			for ( int i = 0; i < 9; i++ ) {
				for ( int j = 0; j < b[i]; j++ )	cout << i + 1 << " "; 
			}
			return;
		}		
	}
}

int main()
{
	freopen("F://input.txt","r",stdin);
//	_enum(oriClock);
	violent_enum();
	return 0;
}

