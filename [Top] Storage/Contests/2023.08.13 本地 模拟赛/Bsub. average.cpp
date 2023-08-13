#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 150 + 10;
const int K = 100 + 10;
const int MOD = 998244353;
int k, q, n, x;

namespace ke1 { // k equals to 1 
	int f[N][N * N];
	void upd(int &x, int y) { x += y; (x > MOD) and (x -= MOD); }
	void solve() {
		memset(f, 0, sizeof f);
		cin >> n >> x;
		for (int i = 1; i <= n; ++ i) {
			for (int j = i - 1; j; -- j) {
				for (int k = 1; k <= (1 + i) * i >> 1; ++ k)
					upd(f[j + 1][k + i], f[j][k]);
			}
			upd(f[1][i], 1);
		}
		int ans = 0;
		for (int i = 1; i * x <= (1 + n) * n >> 1; ++ i)
			upd(ans, f[i][i * x]);
		cout << ans << '\n';
	}
}

int main() {
	freopen("average.in", "r", stdin);
	freopen("average.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> k >> q;
	if (k == 1) while (q --) ke1::solve();
	return 0;
}
