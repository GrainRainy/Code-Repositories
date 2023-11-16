#include <bits/stdc++.h>
#define fi first
#define se second
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 5e3 + 10;
const int M = 2e5 + 10;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
int n, m, q, col, lv, ans;
vector<vector<int>> dn, dr;
vector<vector<pair<int, int>>> g;
bool st[N][N], vis[N][N];
char s[M];

inline bool abl(int x, int y) {
	bool fa = x and x <= n;
	bool fb = y and y <= m;
	return fa & fb;
}

inline int nwop(int x, int y, int dir) {
	return !dir ? dn[x - 1][y] : dir == 1 ? dr[x][y - 1] : dir == 2 ? dn[x][y] : dr[x][y];
}

void dfs(int x, int y) {
	vis[x][y] = true;
	for (int i = 0, nx, ny; i < 4; ++ i) {
		if (nwop(x, y, i) != 3 or !abl(nx = x + dx[i], ny = y + dy[i])) continue;
		if (!(~g[nx][ny].fi) and !vis[nx][ny]) ans += !st[nx][ny], st[nx][ny] = true, dfs(nx, ny);
		else if (g[nx][ny].fi == (col ^ 1) and g[nx][ny].se <= lv) 
			ans += !st[nx][ny], st[nx][ny] = true;
	}
}

void fsp(int x, int y, int dir) {
	int nx = x + dx[dir], ny = y + dy[dir], opt = nwop(x, y, dir);
	if (opt == 1) {
		if (abl(nx, ny) and (!(~g[nx][ny].fi) or g[nx][ny].fi == (col ^ 1) and g[nx][ny].se <= lv))
			return ans += !st[nx][ny], st[nx][ny] = true, void();
	} else if (opt == 2) {
		while (nwop(x, y, dir) == 2 and !(~g[nx][ny].fi)) {
			ans += !st[nx][ny], st[nx][ny] = true;
			x = x + dx[dir], y = y + dy[dir], nx = x + dx[dir], ny = y + dy[dir];
		}
		if (nwop(x, y, dir) == 2 and g[nx][ny].fi == (col ^ 1) and g[nx][ny].se <= lv)
			return ans += !st[nx][ny], st[nx][ny] = true, void();
	} else if (opt == 3) dfs(x, y);
}

namespace sub2 {
	bool jg = true;
	void solve() {
		for (int i = 1, x, y, nx, ny; i <= q; ++ i) {
			cin >> col >> lv >> x >> y, ans = 0, g[x][y] = {col, lv};
			for (int j = 0; j < 4; ++ j) {
				nx = x + dx[j], ny = y + dy[j];
				if (!nwop(x, y, j)) continue;
				ans += (!(~g[nx][ny].fi) or g[nx][ny].fi != col and g[nx][ny].se <= lv);
			}
			cout << ans << '\n';
		}
	}
}

void solve() {
	cin >> n >> m >> q;
	dn.resize(n + 10), dr.resize(n + 10), g.resize(n + 10);
	dn[0].resize(m + 10), dr[0].resize(m + 10), g[0].resize(m + 10);
	for (int i = 1; i <= n; ++ i) {
		cin >> s + 1, 
		g[i].resize(m + 10), dn[i].resize(m + 10), dr[i].resize(m + 10);
		for (int j = 1; j < m; ++ j) dr[i][j] = s[j] - '0', sub2::jg &= dn[i][j] <= 1;
		dr[i][m] = 0;
	}
	for (int i = 1; i < n; ++ i) {
		cin >> s + 1;
		for (int j = 1; j <= m; ++ j) dn[i][j] = s[j] - '0', sub2::jg &= dn[i][j] <= 1;
	}
	for (int j = 1; j <= m; ++ j) dn[n][j] = 0;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			g[i][j] = {-1, 0};
	if (sub2::jg) return sub2::solve();
	for (int i = 1, x, y; i <= q; ++ i) {
		cin >> col >> lv >> x >> y, ans = 0;
		for (int i = 0; i <= n + 1; ++ i)
			for (int j = 0; j <= m + 1; ++ j)
				st[i][j] = vis[i][j] = false;
		st[x][y] = true, g[x][y] = {col, lv};
		for (int j = 0; j < 4; ++ j) fsp(x, y, j);
		cout << ans << '\n';
	}
	return void();
}

int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
