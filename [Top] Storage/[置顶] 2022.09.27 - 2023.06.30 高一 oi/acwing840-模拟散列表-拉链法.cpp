#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 3;

int h[N], e[N], ne[N], idx;

void insert(int x)
// 头插法 
{
	int k = (x % N + N) % N;
	// 将所有数映射到 0 ~ N，保证取得正数 
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx ++;
}

bool find(int x)
{
	int k = (x % N + N) % N;
	
	for (int i = h[k]; i != -1; i = ne[i])
		if (e[i] == x) return true;
		// 找到
	
	return false; 
}


int main()
{
	int n;
	cin >> n;
	
	memset(h, -1, sizeof(h));
	
	while (n --)
	{
		char op[2];
		int x;
		cin >> op >> x;
		
		if (*op == 'I') insert(x);
		else
		{
			if (find(x)) puts("Yes");
			else puts("No");
		}
	}
	
	return 0;
}
