#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 10;
int n, m, res, dfn[N], siz[N], stp;
pair<int, int> p[N];
vector<int> g[N];
int ans[N];

void dfs(int u, int fa) {
	siz[u] = 1, dfn[u] = ++ stp;
	for (auto t : g[u])
		if (t != fa) dfs(t, u), siz[u] += siz[t];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, x, y; i < n; ++ i) {
		cin >> x >> y;
		g[x].emplace_back(y), g[y].emplace_back(x);
	}
	for (int i = 1; i <= m; ++ i) cin >> p[i].fi >> p[i].se;
	for (int i = 1; i <= n; ++ i) {
		stp = res = 0, dfs(i, 0);
		for (int j = 1; j <= m; ++ j) {
			if (dfn[p[j].se] >= dfn[p[j].fi] and dfn[p[j].se] < dfn[p[j].fi] + siz[p[j].fi])
				res ++;
			else if (dfn[p[j].fi] >= dfn[p[j].se] and dfn[p[j].fi] < dfn[p[j].se] + siz[p[j].se])
				res ++;
			ans[j] = max(ans[j], res);
		}
	}
	for (int i = 1; i <= m; ++ i) cout << ans[i] << '\n';
	return 0;
}
