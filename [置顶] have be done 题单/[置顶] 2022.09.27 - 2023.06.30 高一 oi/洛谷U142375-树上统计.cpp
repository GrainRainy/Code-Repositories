#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int h[N], idx;
struct node
{
	int to, nxt;
}edge[N];

int ind[N], mx[N], mn[N], f[N];

int n, ans;

void add(int x, int y)
{
	edge[++ idx].to = y;
	edge[idx].nxt = h[x];
	h[x] = idx;
}

void dfs(int u)
{
	mn[u] = mx[u] = u, f[u] = 1;
	for (int i = h[u]; i != -1; i = edge[i].nxt)
	{
		int v = edge[i].to;
		dfs(v);
		mx[u] = max(mx[u], mx[v]);
		mn[u] = min(mn[u], mn[v]);
		f[u] += f[v];
	}
	if (mx[u] - mn[u] + 1 == f[u]) ans ++;
}

int main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	
	for (int i = 1; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		ind[y] ++;
	}
	// input
	
	int rot;
	for (int i = 1; i <= n; i ++)
		if (!ind[i])
		{
			rot = i;
			break;
		}
	
	dfs(rot);
	
	cout << ans << endl;
}
