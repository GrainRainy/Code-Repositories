#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 12 + 3;
int n, m, g[N][N];
LL dp[N][1 << N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	for (int i = 1, a, b, w; i <= m; ++ i) {
		cin >> a >> b >> w;
		g[a][b] = g[b][a] = min(g[a][b], w);
	}
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= n; ++ i) dp[0][1 << i - 1] = 0;
	for (int s = 1; s < 1 << n; ++ s) {
		for (int t = s; t; t = (t - 1) & s) {
			LL res = 0;
			for (int i = 1; i <= n; ++ i) {
				if (!((s >> i - 1) & 1) or (t >> i - 1) & 1) continue;
				LL dis = 0x3f3f3f3f;
				for (int j = 1; j <= n; ++ j)
					if ((t >> j - 1) & 1) dis = min(dis, (LL)g[i][j]);
				res += dis;
			}
			for (int i = 1; i < n; ++ i) dp[i][s] = min(dp[i][s], dp[i - 1][t] + res * i);
		}
	}
	LL ans = 0x3f3f3f3f;
	for (int i = 0; i < n; ++ i) ans = min(ans, dp[i][(1 << n) - 1]);
	return cout << ans << '\n', 0;
}
