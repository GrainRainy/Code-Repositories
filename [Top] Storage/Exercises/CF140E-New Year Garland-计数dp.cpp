#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
const int L = 5e3 + 10;
int n, m, mod, l[N], f[L][L], g[L][L], nw[L], pre[L], presm, ans;
inline int upd(const int &x, const int &y) { return x + y > mod ? x + y - mod : x + y; }
int main() {
	rd(n), rd(m), rd(mod);
	for (int i = 1; i <= n; ++ i) rd(l[i]), l[0] = max(l[0], l[i]);
	f[1][1] = m, g[1][1] = 1;
	for (int i = 1; i <= l[0]; ++ i) 
		for (int j = 1; j <= i and j <= m; ++ j) {
			f[i + 1][j] = upd(f[i + 1][j], (LL)f[i][j] * (j - 1) % mod);
			f[i + 1][j + 1] = upd(f[i + 1][j + 1], (LL)f[i][j] * (m - j) % mod);
			g[i + 1][j] = upd(g[i + 1][j], (LL)g[i][j] * (j - 1) % mod);
			g[i + 1][j + 1] = upd(g[i + 1][j + 1], (LL)g[i][j] * (j + 1) % mod);
		}
	for (int i = 1; i <= l[1]; ++ i) pre[i] = f[l[1]][i];
	for (int i = 2; i <= n; ++ i) {
		presm = 0;
		for (int j = 1; j <= l[i - 1]; ++ j) 
			presm = upd(presm, pre[j]), nw[j] = (LL)pre[j] * upd(f[l[i]][j], mod - g[l[i]][j]) % mod;
		for (int j = 1; j <= l[i]; ++ j)
			nw[j] = upd(nw[j], (LL)upd(presm, mod - pre[j]) * f[l[i]][j] % mod);
		for (int j = 1; j <= l[i]; ++ j) pre[j] = nw[j], nw[j] = 0;
		for (int j = l[i] + 1; j <= l[i - 1]; ++ j) pre[j] = 0;
	}
	for (int i = 1; i <= l[n]; ++ i) ans = upd(ans, pre[i]);
	return cout << ans << '\n', 0;
}
