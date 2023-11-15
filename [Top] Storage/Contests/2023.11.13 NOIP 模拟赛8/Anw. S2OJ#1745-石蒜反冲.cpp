#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e4 + 10;
const int M = 2e3 + 10;
const int MOD = 993244353;
int n, f[N][M];
string s, a, b;

bool jga(int l) {
	for (int i = 0; i < 6; ++ i)
		if (s[l + i] != '?' and s[l + i] != a[i]) return false;
	return true;
}

bool jgb(int l) {
	for (int i = 0; i < 9; ++ i)
		if (s[l + i] != '?' and s[l + i] != b[i]) return false;
	return true;
}

void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> s, a = "sakana", b = "chinanago", s = ' ' + s, f[0][n / 9 + 1] = 1;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n / 9 + i / 6 + 1; ++ j)
			upd(f[i][j], s[i] == '?' ? 1ll * f[i - 1][j] * 26 % MOD : f[i - 1][j]);
		if (i >= 6 and jga(i - 5)) 
			for (int j = 1; j <= n / 9 + i / 6 + 1; ++ j)
				upd(f[i][j], (f[i - 6][j - 1] - f[i - 6][j] + MOD) % MOD);
		if (i >= 9 and jgb(i - 8))
			for (int j = 1; j <= n / 9 + i / 6 + 1; ++ j)
				upd(f[i][j], (f[i - 9][j + 1] - f[i - 9][j] + MOD) % MOD);
	}
	return cout << f[n][n / 9 + 1] << '\n', 0;
}
