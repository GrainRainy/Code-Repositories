#include <iostream>
#include <cstring>

using namespace std;

const int NULLX = 0x3f3f3f3f;
const int N = 2e5 + 3;

int h[N];

int find(int x)
{
	int k = (x % N + N) % N;
	
	while (h[k] != NULLX && h[k] != x)
	{
		k ++;
		if (k == N) k = 0;
	}
	
	return k;
}


int main()
{
	int n;
	cin >> n;
	
	memset(h, 0x3f, sizeof h);
	
	while (n --)
	{
		char op[2];
		int x;
		
		cin >> op >> x;
		int k = find(x);
		
		if (*op == 'I') h[k] = x;
		else
		{
			if (h[x] != NULLX) puts("Yes");
			else puts("No");
		}
	}
	
	return 0;
}
