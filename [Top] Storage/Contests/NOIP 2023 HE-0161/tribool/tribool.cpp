#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int c, t, n, m, tp[N];
char op;
int ans;

namespace sub2 {
	int t[N];
	void dfs(int pos) {
		if (pos == n + 1) {
			int cnt = 0;
			for (int i = 1; i <= n; ++ i) {
				cnt += t[i] == 3;
				if (tp[i] > n) {
					if (tp[i] - n != t[i]) return;
				} else if (tp[i] > 0) {
					if (t[i] != t[tp[i]]) return;
				} else {
					if (t[-tp[i]] == 1 and t[i] != 2) return;
					if (t[-tp[i]] == 2 and t[i] != 1) return;
					if (t[-tp[i]] == 3 and t[i] != 3) return;
				}
			}
			ans = min(ans, cnt);
			return;
		}
		for (int i = 1; i <= 3; ++ i)
			t[pos] = i, dfs(pos + 1);
	}
}

namespace sub3 {
	int head[N], etp, dfn[N], low[N], stamp;
	int stk[N], stp, scc;
	struct Node { int nxt, to; }edge[N << 1];
	vector<int> g[N];
	inline void add(int a, int b) {
		edge[++ etp] = {head[a], b};
		head[a] = etp;
	}
	
	void tarjan(int u) {
		dfn[u] = low[u] = ++ stamp;
		for (int i = head[u], v; ~i; i = edge[i].nxt) {
			if (!dfn[v = edge[i].to]) {
				tarjan(v);
				low[u] = min(low[u], low[v]);
			} else low[u] = min(low[u], dfn[v]);
		}
		if (dfn[u] == low[u]) {
			++ scc;
			
		}
	}
	
	void solve() {
		stamp = 0;
	}
}

void solve() {
	cin >> n >> m, ans = n;
	memset(tp, 0, sizeof(int) * (n + 10));
	for (int i = 1, x, y; i <= m; ++ i) {
		cin >> op >> x;
		if (op == 'T') tp[x] = n + 1;
		if (op == 'F') tp[x] = n + 2;
		if (op == 'U') tp[x] = n + 3;
		if (op == '+') cin >> y, tp[x] = y;
		if (op == '-') cin >> y, tp[x] = -y;
	}
	if (c <= 2) sub2::dfs(1);
	else {
		ans = 0;
		for (int i = 1; i <= n; ++ i)
			ans += tp[i] == n + 3;
	}
	cout << ans << '\n';
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t --) solve();
	return 0;
}
