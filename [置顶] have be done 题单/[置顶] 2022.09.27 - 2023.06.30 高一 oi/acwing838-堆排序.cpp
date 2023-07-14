#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], siz;

void down(int u)
{
	int t = u;
	// t 表示当前节点和两个子节点中最小值的下标 
	if (u * 2 <= siz && h[u * 2] < h[t])
		t = u * 2; 
	if (u * 2 + 1 <= siz && h[u * 2 + 1] < h[t])
		t = u * 2 + 1;
	if (u != t)
	{
		swap(h[u], h[t]);
		down(t);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> h[i];
	
	siz = n;
	
	for (int i = n / 2; i; i --)
		down(i);
	// 堆的输入及初始化
	
	while (m --)
	{
		cout << h[1] << " ";
		h[1] = h[siz --];
		down(1);
	}
	
	
	return 0;
}

