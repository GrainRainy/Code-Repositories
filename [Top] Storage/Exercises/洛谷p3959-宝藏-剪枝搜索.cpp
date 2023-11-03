#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 12 + 3;
int n, m, w[N][N], g[N][N], dg[N];
int cnt, rt, lev[N], stk[N], tp;
LL ans = 0x3f3f3f3f, res, lim;

bool cmp(const int &a, const int &b) { return w[rt][a] < w[rt][b]; }

void dfs(int nw, int trg) {
	for (int i = nw; i <= cnt; ++ i) {
		if (res + lim * lev[stk[i]] > ans) return;
		for (int j = trg; j <= dg[stk[i]]; ++ j) {
			if (lev[g[stk[i]][j]]) continue;
			stk[++ cnt] = g[stk[i]][j];
			lim -= w[stk[cnt]][g[stk[cnt]][1]];
			res += w[stk[i]][stk[cnt]] * lev[stk[i]];
			lev[stk[cnt]] = lev[stk[i]] + 1;
			dfs(i, trg + 1);
			lim += w[stk[cnt]][g[stk[cnt]][1]];
			res -= w[stk[i]][stk[cnt]] * lev[stk[i]];
			lev[stk[cnt --]] = 0;
		}
		trg = 1;
	}
	if (cnt == n) return ans = min(ans, res), void();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(w, 0x3f, sizeof w);
	for (int i = 1, a, b, cw; i <= m; ++ i) {
		cin >> a >> b >> cw;
		if (w[a][b] == 0x3f3f3f3f)
			g[a][++ dg[a]] = b, g[b][++ dg[b]] = a;
		w[a][b] = w[b][a] = min(w[a][b], cw);
	}
	for (int i = 1; i <= n; ++ i) {
		rt = i, sort(g[i] + 1, g[i] + dg[i] + 1, cmp);
		lim += w[i][g[i][1]];
	}
	for (int i = 1; i <= n; ++ i) {
		lim -= w[i][g[i][1]], stk[cnt = 1] = i, lev[i] = 1;
		dfs(1, 1), lim += w[i][g[i][1]], lev[i] = 0;
	}
	return cout << ans << '\n', 0;
}
