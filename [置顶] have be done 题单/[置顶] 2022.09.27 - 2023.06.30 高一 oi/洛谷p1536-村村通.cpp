#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int father[N];

int idx;
int n, m;

int ans = -1;

int find(int u)
{
	if (father[u] != u) father[u] = find(father[u]);
	return father[u];
}

void add(int a, int b)
{
	father[find(a)] = find(b);
}

void solve(int n, int m)
{
	if (m == 0)
	{
		cout << n - 1 << endl;
		return;
	}
	
	for (int i = 1; i <= n; i ++)
		father[i] = i;
	
	int x, y;
	for (int i = 1; i <= m; i ++)
	{
		cin >> x >> y;
		add(x, y);
	}
	
	for (int i = 1; i <= n; i ++)
		if (father[i] == i)
		{
//			cout << i << endl;
			ans ++;
		}
	
	cout << ans << endl;
	
	ans = -1;
}

int main()
{
	int x, y;
	while ((cin >> x) && x)
	{
		cin >> y;
		solve(x, y);
	}
	return 0;
}
