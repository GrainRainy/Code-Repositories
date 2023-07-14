#include <bits/stdc++.h>

using namespace std;

const int N = 1600;
const int M = N << 1;

int h[N], idx;
struct node
{
	int to, nxt;
}edge[M];

int f[N][2], n;

void dfs(int u, int father)
{
	f[u][1] = 1, f[u][0] = 0; 
	for (int i = h[u]; ~i; i = edge[i].nxt)
	{
		if (edge[i].to == father) continue;
		int v = edge[i].to;
		dfs(v, u);
		f[u][0] += f[v][1];
		f[u][1] += min(f[v][1], f[v][0]);
	}
}

void add(int a, int b)
{
	edge[++ idx].to = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

int main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	for (int aba = 1; aba <= n; aba ++)
	{
		int i, k;
		cin >> i >> k;
		for (int j = 1; j <= k; j ++)
		{
			int t;
			cin >> t;
			add(i, t), add(t, i);
		}
	}
	
	dfs(0, -1);
	
	cout << min(f[0][0], f[0][1]) << endl;
	
	return 0;
}
