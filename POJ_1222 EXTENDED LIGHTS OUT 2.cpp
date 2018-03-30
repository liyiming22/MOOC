#include <iostream>
using namespace std;

char result[5];
char oriLights[5];

int getBit(char c, int i)
{
//	c右移i位和1相与，就得到了第i位的二进制值 
	return (c >> i) & 1;
}

//	传入c的引用 
void setBit(char & c, int i, int v)
{
//	变为1,c和左移i位的1相与 
	if ( v )	c |= ( 1 << i );
//	变为0,c和左移i位取反的1或运算	
	else	c &= ~( 1 << i );
}

void flipBit(char & c, int i)
{
	c ^= ( 1 << i );
}

void outputResult(int t, char result[])
{
	cout << "PUZZLE #" << t << endl;
	for ( int i = 0; i < 5; ++i ) {
		for ( int j = 0; j < 6; ++j ) {
			cout << getBit(result[i],j);
			if ( j < 5 )	cout << " ";	
		}
		cout << endl;
	}
}

int main()
{
//	freopen("F://input.txt","r",stdin);
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t ) {
		for ( int i = 0; i < 5; ++i ) {
			for ( int j = 0; j < 6; ++j ) {
				int s;
				cin >> s;
				setBit(oriLights[i],j,s);		
			}
		}
		for ( int n = 0; n < 64; ++n ) {
			char lights[5];
			memcpy(lights,oriLights,sizeof(oriLights));
			int switches = n;
			for ( int i = 0; i < 5; ++i ) {
				result[i] = switches;
				for ( int j = 0; j < 6; ++j ) {
					if ( getBit(switches,j) ) {
						if ( j > 0 )	flipBit(lights[i],j - 1);
						if ( j < 5 )	flipBit(lights[i],j + 1);
						flipBit(lights[i],j);
					}
				}
//				改变下一行的灯 
				if ( i < 4 )	lights[i + 1] ^= switches;
//				确定下一行的开关状态 
				switches = lights[i];
			}
//			判断第五行是否全灭
			if ( 0 == lights[4] ) {
				outputResult(t,result);
				break;
			} 
		}
	}
	return 0;
}

