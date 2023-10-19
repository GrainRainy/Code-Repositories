#include <bits/stdc++.h>
using namespace std;
const int N = 40 + 5;
const int M = 250 + 10;
int n, m, c[2][2], f[N][N][N][N];
char g[M][M];

int dfs(int a, int b, int c, int d) {
	if (~f[a][b][c][d]) return f[a][b][c][d];
	int ans = 0x3f3f3f3f, pos;
	for (int i = b, tmp; i < d; ++ i) {
		if ((tmp = max(dfs(a, b, c, i), dfs(a, i + 1, c, d))) < ans)
			ans = tmp, pos = i;
	}
	for (int j = a, tmp; j < c; ++ j) {
		if ((tmp = max(dfs(a, b, j, d), dfs(j + 1, b, c, d))) < ans)
			ans = tmp, pos = -j;
	}
	if (!ans) {
		if (pos > 0 and g[c][pos] == g[a][pos + 1]) return f[a][b][c][d] = 0;
		if (pos < 0 and g[-pos][d] == g[-pos + 1][b]) return f[a][b][c][d] = 0;
	} 
	return f[a][b][c][d] = ans + 1;
}

namespace sub2 {
	void solve() {
		int ans = 0;
		while (n != 1) n = n - (n >> 1), ans ++;
		while (m != 1) m = m - (m >> 1), ans ++;
		return cout << ans << '\n', void();
	}
}

int main() {
	freopen("painting.in", "r", stdin);
	freopen("painting.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> g[i] + 1;
	for (int i = 1; i <= n; ++ i) 
		for (int j = 1; j <= m; ++ j)
			c[(i + j) & 1][g[i][j] == '#' ? 0 : 1] ++;
	if (c[0][0] + c[1][1] == n * m or c[0][1] + c[1][0] == n * m)
		return sub2::solve(), 0;
	memset(f, -1, sizeof f);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			f[i][j][i][j] = 0;
	cout << dfs(1, 1, n, m) << '\n';
	return 0;
}
