#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = N << 1;

int h[N], idx;
struct node
{
	int to, nxt;
}edge[M];

int n, m;
int color[N];

void add(int a, int b)
{
	edge[++ idx].to = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

bool dfs(int u, int c)
// point and color
{
	color[u] = c;
	
	for (int i = h[u]; i != -1; i = edge[i].nxt)
	{
		int t = edge[i].to;
		if (!color[t] && !dfs(t, 3 - c)) 
			return false;
		else if (color[t] == c)
			return false;
	}
	return true;
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	
	for (int i = 0; i < m; i ++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	// input
	bool judge = true;
	for (int i = 1; i <= n; i ++)
		if (!color[i] && !dfs(i, 1))
		{
			judge = false;
			break;
		}
	if (judge) puts("Yes");
	else puts("No");
	
	return 0;
}
