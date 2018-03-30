#include <iostream>
using namespace std;

char result[5];
char oriLights[5];

int getBit(char c, int i)
{
//	c����iλ��1���룬�͵õ��˵�iλ�Ķ�����ֵ 
	return (c >> i) & 1;
}

//	����c������ 
void setBit(char & c, int i, int v)
{
//	��Ϊ1,c������iλ��1���� 
	if ( v )	c |= ( 1 << i );
//	��Ϊ0,c������iλȡ����1������	
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
//				�ı���һ�еĵ� 
				if ( i < 4 )	lights[i + 1] ^= switches;
//				ȷ����һ�еĿ���״̬ 
				switches = lights[i];
			}
//			�жϵ������Ƿ�ȫ��
			if ( 0 == lights[4] ) {
				outputResult(t,result);
				break;
			} 
		}
	}
	return 0;
}

