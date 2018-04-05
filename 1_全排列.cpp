#include <iostream>
using namespace std;

void permutation(string inp, int start, int end)
{
	if ( start == end )	cout << inp << endl;
	else {
		for ( int i = start; i <= end; i++ ) {
			swap(inp[start],inp[i]);
			permutation(inp,start + 1, end);
//			swap(inp[start],inp[i]);
		}
	}
}

int main()
{
	freopen("F://input.txt","r",stdin);
	string inp;
	cin >> inp;
	int end = inp.length() - 1;
	int start = 0;
	permutation(inp,start,end);
	return 0;
}

