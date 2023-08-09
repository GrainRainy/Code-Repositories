#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
const int MC = 1e3 + 10;
int n, m, C, T;
int s, q, d;
int p[N], c[N];
int dp[N][MC];

inline void upd(int &x, int y) {
	(x > y) and (x = y);
	return;
}

void solve() {
	cin >> s >> q >> d;	
	if (s + d > n) return cout << "-1\n", void();
	memset(dp, 0x3f, sizeof dp);
	dp[s][0] = 0;
	for (int i = s; i <= n; ++ i) {
		for (int j = 0; j <= C; ++ j) {
			if (dp[i][j] == 0x3f3f3f3f) continue;
			for (int a = i + 1; a <= min(n, i + c[i] + j); ++ a) {
						/* 写挂了, 这里应该是 max(c[i], j) */
				if (j - a + i >= 0) upd(dp[a][j - a + i], dp[i][j]);
				if (j < c[i]) upd(dp[a][c[i] - a + i], dp[i][j] + p[i]);
			}
		}
	}
	int mn = 0x3f3f3f3f;
	for (int i = s + d; i <= n; ++ i)
		for (int j = 0; j <= C; ++ j)
			upd(mn, dp[i][j]);
	if (mn > q) cout << "-1\n";
	else cout << q - mn << '\n';
	return;
}

int main() {
	freopen("trip.in", "r", stdin);
	freopen("trip.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> C >> T;
	for (int i = 1; i <= n; ++ i) cin >> p[i] >> c[i], upd(c[i], C);
	for (int i = 1, a, b, l; i <= m; ++ i) cin >> a >> b >> l;
	while (T --) solve();
	return 0;
}
