#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, sub;
int pre[N][N], c[N];
long double sm, a[N], f[N][N];

void solve() {
	cin >> n >> m, sm = 0;
	for (int i = 1; i <= n; ++ i) cin >> a[i], sm += a[i];
	sm /= m;
	for (int i = 0; i <= n; ++ i)
		for (int j = 0; j <= m; ++ j)
			f[i][j] = 1e10;
	f[0][0] = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = i - 1; j <= m; ++ j) {
			for (int k = 1; k + j <= m; ++ k) {
				double w = a[i] / k;
				if (f[i - 1][j] + k * (w - sm) * (w - sm) < f[i][j + k])
					f[i][j + k] = f[i - 1][j] + k * (w - sm) * (w - sm), pre[i][j + k] = j;
			}
		}
	}
//	int nw = m;
//	for (int i = n; i; -- i) c[i] = nw - pre[i][nw], nw = pre[i][nw];
//	for (int i = 1; i <= n; ++ i) cout << c[i] << ' ';
//	cout << '\n';
	printf("Case #%d: %.10Lf\n", sub, f[n][m] / m);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) ++ sub, solve();
	return 0;
}
