#include <iostream>

using namespace std;

const int N = 40;
int n;
int g[N];
int col[N], dg[N], udg[N];
int cnt;

void dfs(int u)
{
	if (u == n)
	{
		cnt ++;
		if (cnt <= 3)
		{
			for (int i = 0; i < n; i ++)
				cout << g[i] << " ";
			cout << endl;
		}
		return;
	}
	
	for (int i = 1; i <= n; i ++)
	{
		if (!col[i] && !dg[u + i] && !udg[n - u + i])
		{
			g[u] = i;
			col[i] = dg[u + i] = udg[n - u + i] = true;
			dfs(u + 1);
			col[i] = dg[u + i] = udg[n - u + i] = false;
			g[u] = '.';
		}
	}
}

int main()
{
	cin >> n;
	
	dfs(0);
	
	cout << cnt << endl;
	return 0;
}
