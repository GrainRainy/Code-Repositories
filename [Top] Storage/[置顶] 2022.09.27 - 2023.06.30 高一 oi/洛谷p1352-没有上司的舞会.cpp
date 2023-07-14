#include <bits/stdc++.h>

using namespace std;

const int N = 6e3 + 10;

int h[N], idx;
struct node
{
	int to, nxt, w;
}edge[N];

int f[N][2], r[N], ind[N];

int n;

void add(int x, int y)
{
	edge[++ idx].to = y;
	edge[idx].nxt = h[x];
	h[x] = idx;
}

void dfs(int u)
{
	f[u][1] = r[u], f[u][0] = 0;
	
	for (int i = h[u]; i != -1; i = edge[i].nxt)
	{
		int v = edge[i].to;
		dfs(v);
		f[u][1] += f[v][0];
		f[u][0] += max(f[v][1], f[v][0]);
	}
}

int main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i ++)
		cin >> r[i];
	for (int i = 1; i < n; i ++)
	{
		int l, k;
		cin >> l >> k;
		add(k, l);
		ind[l] ++;
	}
	
	int rot; 
	for (int i = 1; i <= n; i ++)
		if (!ind[i])
		{
			rot = i;
			break;
		}
		
	dfs(rot);
	
	cout << max(f[rot][0], f[rot][1]) << endl;
	
	return 0;
}
