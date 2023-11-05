#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 10;
int n, m, ad, ml, w[N], nbs[N], f[N][N], g[N][N][N][N];

void upd(int &x, int y) { x = x < y ? x : y; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> ad >> ml;
	for (int i = 1; i <= n; ++ i) cin >> w[i], nbs[i] = w[i];
	sort(nbs + 1, nbs + n + 1), m = unique(nbs + 1, nbs + n + 1) - nbs - 1;
	memset(g, 0x3f, sizeof g), memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; ++ i) 
		w[i] = lower_bound(nbs + 1, nbs + m + 1, w[i]) - nbs, g[i][i][w[i]][w[i]] = 0;
	for (int len = 1; len <= n; ++ len) 
		for (int l = 1, r = len; r <= n; l ++, r ++)
			for (int a = 1; a <= m; ++ a)
				for (int b = 1; b <= m; ++ b) {
					for (int k = l; k < r; ++ k) upd(g[l][r][a][b], g[l][k][a][b] + f[k + 1][r]);
					upd(f[l][r], g[l][r][a][b] + ad + ml * (nbs[a] - nbs[b]) * (nbs[a] - nbs[b]));
					upd(g[l][r + 1][min(a, w[r + 1])][max(b, w[r + 1])], g[l][r][a][b]);
				}
	return cout << f[1][n] << '\n', 0;
}
