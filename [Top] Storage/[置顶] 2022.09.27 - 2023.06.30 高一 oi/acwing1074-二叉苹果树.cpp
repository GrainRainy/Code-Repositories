#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int M = N << 1;

int h[N], idx;
struct node
{
	int to, nxt, w;
}edge[M];

int f[N][N];

int n, m;

void add(int a, int b, int c)
{
	edge[++ idx].to = b;
	edge[idx].w = c;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

void dfs(int u, int father)
{
	for (int i = h[u]; ~i; i = edge[i].nxt)
	{
		if (edge[i].to == father) continue;
		dfs(edge[i].to, u);
		for (int j = m; j >= 0; j --)
			for (int k = 0; k < j; k ++)
				f[u][j] = max(f[u][j], f[u][j - k - 1] + f[edge[i].to][k] + edge[i].w);
	}
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0; i < n - 1; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	
	dfs(1, -1);
	
	cout << f[1][m] << endl;
	return 0;
}
