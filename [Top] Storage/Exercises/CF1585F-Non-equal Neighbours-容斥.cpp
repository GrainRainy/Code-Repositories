#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
const int MOD = 998244353;
int n, a[N], stk[N], top;
int f[N][2], g[N][2];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline int upd(const int &x, const int &y) {
	return x + y >= MOD ? x + y - MOD : x + y < 0 ? x + y + MOD : x + y;
}
int main() {
	rd(n);
	f[0][0] = g[0][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		rd(a[i]);
		while (top and a[stk[top]] >= a[i]) top --;
		if (top) for (int j : {0, 1}) 
			f[i][j] = upd(f[stk[top]][j], (LL)(g[i - 1][j ^ 1] - g[stk[top] - 1][j ^ 1]) * a[i] % MOD);
		else for (int j : {0, 1}) f[i][j] = (LL)g[i - 1][j ^ 1] * a[i] % MOD;
		for (int j : {0, 1}) g[i][j] = upd(g[i - 1][j], f[i][j]);
		stk[++ top] = i;
	}
	return cout << upd((f[n][0] - f[n][1]) * (n & 1 ? -1 : 1) % MOD, MOD) << '\n', 0;
}
