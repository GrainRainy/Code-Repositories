#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
int n, k, head[N], idx;
struct Node { int nxt, to, w; }edge[N << 1];


inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

void dp(int u, int fa) {
	
}

namespace sub2 {
	LL f[N], fs[N], ff[N], g[N];
	void dp(int u, int fa) {
		for (int i = head[u], v; ~i; i = edge[i].nxt) {
			if ((v = edge[i].to) == fa) continue;
			dp(v, u);
			if (f[v] + edge[i].w > f[u])
				ff[u] = f[u], fs[u] = v, f[u] = f[v] + edge[i].w;
			else if (f[v] + edge[i].w > ff[u]) ff[v] = f[v] + edge[i].w;
		}
	}
	void dpg(int u, int fa) {
		for (int i = head[u], v; ~i; i = edge[i].nxt) {
			if ((v = edge[i].to) == fa) continue;
			if (v == fs[u]) 
				g[v] = max({g[u], f[u] - edge[i].w * 2, ff[u]});
			else g[v] = max(g[u], f[u]);
			g[v] += edge[i].w;
			dpg(v, u);
		}
	}
	void solve() {
		dp(1, 0), dpg(1, 0);
		for (int i = 1; i <= n; ++ i) cout << max(f[i], g[i]) << '\n';
		return;
	}
}

int main() {
	freopen("allinone.in", "r", stdin);
	freopen("allinone.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b, c; i < n; ++ i)
		cin >> a >> b >> c, add(a, b, c), add(b, a, c);
	if (k == 1) return sub2::solve(), 0;
	else 
	return 0;
}
