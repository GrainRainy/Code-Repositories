#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using IO::rd;
using namespace std;
using LL = long long;
const int N = 40 + 10;
const int D = 1e5 + 10;
const int MOD = 1e9 + 7;
int n, d, r[N], mxr;
int fac[N + D], fav[N + D];
int f[N][N][N * N];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

inline int C(int n, int m) { return (LL)fac[n] * fav[n - m] % MOD * fav[m] % MOD; }
inline void upd(int &x, int y) { x += y; (x >= MOD) and (x -= MOD); }

int main() {
	rd(n), rd(d);
	fac[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		fac[i] = (LL)fac[i - 1] * i % MOD;
		rd(r[i]), mxr = max(mxr, r[i]);
	}
	sort(r + 1, r + n + 1);
	for (int i = n + 1; i <= n + d; ++ i)
		fac[i] = (LL)fac[i - 1] * i % MOD;
	fav[n + d] = qpow(fac[n + d], MOD - 2);
	for (int i = n + d - 1; ~i; -- i)
		fav[i] = (LL)fav[i + 1] * (i + 1) % MOD;
	f[0][0][0] = 1;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= i; ++ j)
			for (int k = 1; k <= mxr * i; ++ k) {
				if (k >= r[i]) upd(f[i][j][k], (LL)f[i - 1][j][k - r[i]] * j * 2 % MOD);
				if (k >= r[i] * 2 - 1) upd(f[i][j][k], (LL)f[i - 1][j + 1][k - r[i] * 2 + 1] * (j + 1) % MOD * j % MOD);
				upd(f[i][j][k], f[i - 1][j - 1][k - 1]);
			}
	int ans = 0;
	for (int i = 0; i <= min(mxr * n, d); ++ i)
		upd(ans, (LL)f[n][1][i] * C(n + d - i, n) % MOD);
	return printf("%d\n", ans), 0;
}
