#include <iostream>
#include <stack>
using namespace std;

int main()
{
//	freopen("F://input.txt","r",stdin);
	int M,N,K;
	cin >> M >> N >> K;
	while ( K-- ) {
		bool flag = true;
		int ptr = 1;
		stack <int> s;
		int length = 0;
		int inp[N + 1];
		for ( int i = 1; i <= N; i++ )	cin >> inp[i];
		int i = 1;
		while ( ptr <= N ) {
			bool do_flag = false;
			if ( inp[ptr] == i ) {
//				do_flag = true;
				ptr++;
			}
			else if ( inp[ptr] == s.top() ) {
				s.pop();
				length--;
				ptr++;
//				s.push(i);
				do_flag = true;
			}
			else if ( length >= M ) {
				flag = false;
				break;
			}
			else {
				s.push(i);
				length++;
			}
			if ( !do_flag && i < N && length < M )
//			if ( i < N && length < M )
				i++;
		}
		cout << (flag? "YES" : "NO") << endl; 
	}
	return 0;
}

