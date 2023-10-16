#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, m, head[N], idx;
struct Node { int nxt, to, w; }edge[N * N];
int f[N][1 << N], ans = 0xcfcfcfcf;

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(f, 0xcf, sizeof f), memset(head, -1, sizeof head);
	for (int i = 1, a, b, w; i <= m; ++ i)
		cin >> a >> b >> w, add(a + 1, b + 1, w);
	f[1][1] = 0;
	for (int s = 1; s < 1 << n; ++ s) {
		for (int u = 1; u <= n; ++ u)
			for (int i = head[u], v; ~i; i = edge[i].nxt) {
				if ((s >> (v = edge[i].to) - 1) & 1) continue;
				f[v][s | (1 << v - 1)] = max(f[v][s | (1 << v - 1)], f[u][s] + edge[i].w);
			}
	}
	for (int s = 1; s < 1 << n; ++ s)
		if ((s >> n - 1) & 1) ans = max(ans, f[n][s]);
	return cout << ans << '\n', 0;
}
