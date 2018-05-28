// 17:04
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int * inp;
int * res;
int index = 1;

void buildTree(int root)
{
	if ( root > N )	return;
	buildTree(root * 2);
	res[root] = inp[index++];
	buildTree(root * 2 + 1);
}

int main()
{
	freopen("F://input.txt","r",stdin);
	cin >> N;
	inp = new int[N + 1];
	res = new int[N + 1];
	inp[0] = -1;
	for ( int i = 1; i <= N; ++i ) cin >> inp[i];
	sort(inp,inp + N + 1);
	buildTree(1);
	cout << res[1];
	for ( int i = 2; i <= N; ++i )	cout << " " << res[i];
	delete[] inp;
	delete[] res;
	return 0;
}
