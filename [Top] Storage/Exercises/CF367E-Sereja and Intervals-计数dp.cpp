#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 320;
const int MOD = 1e9 + 7;
int n, m, x;

inline void upd(int &x, int y) { x += y; if (x >= MOD) x -= MOD; }
int main() {
	cin >> n >> m >> x;
	if (n > m) return puts("0") & 0;
	int f[2][n + 10][n + 10];
	memset(f, 0, sizeof f);
	f[0][0][0] = 1;
	for (int i = 1; i <= m; ++ i) {
		memset(f[i & 1], 0, sizeof f[i & 1]);
		for (int j = 0; j <= n; ++ j)
			for (int k = 0; k <= j; ++ k) {
				if (i != x) upd(f[i & 1][j][k], f[i - 1 & 1][j][k]);
				upd(f[i & 1][j + 1][k], f[i - 1 & 1][j][k]);
				if (i != x and k < j) upd(f[i & 1][j][k + 1], f[i - 1 & 1][j][k]);
				upd(f[i & 1][j + 1][k + 1], f[i - 1 & 1][j][k]);
			}
	}
	for (int i = 2; i <= n; ++ i) f[m & 1][n][n] = (LL)f[m & 1][n][n] * i % MOD;
	return cout << f[m & 1][n][n] << '\n', 0;
}
