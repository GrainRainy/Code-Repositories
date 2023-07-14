#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;

int g[N][N];
int dist[N];
bool st[N];

int n ,m;

int prime()
{
	memset(dist, 0x3f, sizeof dist);
	int ans = 0;
	for (int i = 0; i < n; i ++)
	{
		int t = -1;
		for (int j = 1; j <= n; j ++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		if (i && dist[t] == INF) return INF;
		if (i) ans += dist[t];
		for (int j = 1; j <= n; j ++)
			dist[j] = min(dist[j], g[t][j]);
		st[t] = true;
	}
	return ans;
}

int main()
{
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	while (m --)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[v][u], w);
	}
	int t = prime();
	if (t == INF) puts("impossible");
	else cout << t << endl;
	return 0;
}
