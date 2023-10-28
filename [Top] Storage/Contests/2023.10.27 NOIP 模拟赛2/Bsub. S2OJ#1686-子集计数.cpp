#include <bits/stdc++.h>
using namespace std;
const int V = 1 << 17;
const int MOD = 998244353;
int n, mx, f[2][V];

void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, f[0][0] = 1;
	mx = n > 10000 ? 1 << 10 : 1 << 16;
	for (int i = 1, a, s; i <= n; ++ i) {
		cin >> a, s = 0;
		memset(f[i & 1], 0, sizeof f[i & 1]);
		for (int j = 0; j < mx; ++ j)
			if ((j & a) == j) upd(f[i & 1][j | a], f[(i - 1) & 1][j]);
		for (int j = 0; j < mx; ++ j) upd(s, f[i & 1][j]);
		cout << s << '\n';
		for (int j = 0; j < mx; ++ j) upd(f[i & 1][j], f[(i - 1) & 1][j]);
	}
//	cerr << "with time " << (double)clock() / CLOCKS_PER_SEC << '\n';
	return 0;
}
