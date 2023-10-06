#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e3 + 10;
const int MOD = 1e9 + 7;
int n, m, head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int f[N][N];

inline void upd(int &x, int &y) { x += y; if (x >= MOD) x -= MOD; }
inline int ad(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dp(int u, int fa) {
	for (int i = head[u], v, tot; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == fa) continue;
		tot = 0, dp(v, u);
		for (int i = 1; i <= m; ++ i) upd(tot, f[v][i]);
		for (int i = 1; i <= m; ++ i)	
			f[u][i] = (LL)f[u][i] * ad(tot, MOD - f[v][i]) % MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, tc; i <= n; ++ i) {
		cin >> tc;
		for (int j = 1, tmp; j <= tc; ++ j) cin >> tmp, f[i][tmp] = 1;
	}
	for (int i = 1, a, b; i < n; ++ i) cin >> a >> b, add(a, b), add(b, a);
	dp(1, 0);
	int res = 0;
	for (int i = 1; i <= m; ++ i) upd(res, f[1][i]);
	return cout << res << '\n', 0;
}
