#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e3 + 10;
const int MOD = 1e9 + 7;
LL n, m, ans = 1;
char g[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		cin >> g[i] + 1;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j) {
			bool f = true;
			if (i > 1) f &= (g[i - 1][j] == g[i][j]);
			if (j > 1) f &= (g[i][j - 1] == g[i][j]);
			if (i < n) f &= (g[i + 1][j] == g[i][j]);
			if (j < m) f &= (g[i][j + 1] == g[i][j]);
			if (f) ans = (ans + ans) % MOD; 
		}
	return cout << ans << '\n', 0;
}
