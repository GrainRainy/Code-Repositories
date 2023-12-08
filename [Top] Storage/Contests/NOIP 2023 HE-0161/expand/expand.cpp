#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c, n, m, q, a[N], sva[N], b[N], svb[N];
bool ans[N];

namespace sub3 {
	int cnt[N];
	bool dfs(int pos, int res) {
		if (pos == n + 1) {
			bool tp = a[1] < b[1];
			for (int np = 1, nc = 0, bp = 1; np <= n; nc ++) {
				if (nc > cnt[np]) np ++, nc = 1;
				if (np > n) break;
				bool nt = a[np] < b[bp];
				if (nt != tp) return false;
				if (bp != m) bp ++;
			}
			return true;
		}
		for (int i = 1; i <= res; ++ i) {
			cnt[pos] = i;
			if (dfs(pos + 1, res - i)) return true;
		}
		return false;
	}
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; ++ i) cin >> a[i], sva[i] = a[i];
	for (int i = 1; i <= m; ++ i) cin >> b[i], svb[i] = b[i];
	if (c == 1) ans[0] = a[1] != b[1];
	if (c == 2) ans[0] = (a[1] != b[1] and ((a[1] < b[1]) ^ (a[2] < b[2]) ^ 1));
	if (c == 3 or c == 4) ans[0] = sub3::dfs(1, m << 1); 
	else ans[0] = 0;
	for (int i = 1, kx, ky, p, v; i <= q; ++ i) {
		cin >> kx >> ky;
		for (int j = 1; j <= kx; ++ j) cin >> p >> v, a[p] = v;
		for (int j = 1; j <= ky; ++ j) cin >> p >> v, b[p] = v;
		if (a[1] == b[1]) continue;
		if (c == 1) ans[i] = true;
		else if (c == 2) ans[i] = (a[1] < b[1]) ^ (a[2] < b[2]) ^ 1;
		else if (c == 3 or c == 4) ans[i] = sub3::dfs(1, m << 1); 
		else ans[i] = 0;
		for (int j = 1; j <= n; ++ j) a[j] = sva[j];
		for (int j = 1; j <= m; ++ j) b[j] = svb[j];
	}
	for (int i = 0; i <= q; ++ i) cout << ans[i];
	return cout << '\n', 0;
}
