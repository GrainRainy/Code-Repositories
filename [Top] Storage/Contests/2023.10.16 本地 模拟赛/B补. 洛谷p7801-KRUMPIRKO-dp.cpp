#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
const int A = 5e2 + 10;
int n, l, a[N], c[N], sa, sc, f[N][A], g[N][A];
long double ans = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> l;
	for (int i = 1; i <= n; ++ i) cin >> a[i], sa += a[i];
	for (int i = 1; i <= n; ++ i) cin >> c[i], sc += c[i];
	memset(f, 0x3f, sizeof f), memset(g, 0xcf, sizeof g), f[0][0] = g[0][0] = 0;
	for (int i = 1; i <= n; ++ i)
		for (int j = min(i, l); j; -- j)
			for (int k = a[i]; k <= sa; k ++) {
				f[j][k] = min(f[j][k], f[j - 1][k - a[i]] + c[i]);
				g[j][k] = max(g[j][k], g[j - 1][k - a[i]] + c[i]);
			}
	for (int i = 1; i < sa; ++ i) {
		if (f[l][i] == 0x3f3f3f3f) continue;
		ans = min(ans, ((long double)f[l][i] * sc - (long double)f[l][i] * f[l][i]) / (i * sa - i * i));
		ans = min(ans, ((long double)g[l][i] * sc - (long double)g[l][i] * g[l][i]) / (i * sa - i * i));
	}
	return printf("%.3Lf\n", ans), 0;	
}
