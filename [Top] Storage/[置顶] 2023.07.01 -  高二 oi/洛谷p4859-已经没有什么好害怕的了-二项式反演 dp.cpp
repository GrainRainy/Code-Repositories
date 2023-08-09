#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using IO::input;
using namespace std;
using LL = long long;
const int N = 2e3 + 10;
const int MOD = 1e9 + 9;
int n, k, a[N], b[N], cnt[N];
int fac[N], fav[N], dp[N][N], ans;

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
	input(n), input(k);
	if ((n + k) & 1) return puts("0"), 0;
	for (int i = 1; i <= n; ++ i) input(a[i]);
	for (int i = 1; i <= n; ++ i) input(b[i]);
	sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
	dp[0][0] = fac[0] = 1;
	for (int i = 1; i <= n; ++ i) fac[i] = (LL)fac[i - 1] * i % MOD;
	fav[n] = qpow(fac[n], MOD - 2);
	for (int i = n - 1; ~i; -- i) fav[i] = (LL)fav[i + 1] * (i + 1) % MOD;
	for (int i = 1, pos = 0; i <= n; ++ i) {
		dp[i][0] = 1;
		while (b[pos + 1] <= a[i] and pos < n) pos ++;
		for (int j = 1; j <= i; ++ j) upd(dp[i][j], dp[i - 1][j]), upd(dp[i][j], (LL)dp[i - 1][j - 1] * (pos - j + 1) % MOD);
	}
	for (int i = n + k >> 1; i <= n; ++ i)
		upd(ans, ((LL)C(i, n + k >> 1) * dp[n][i] % MOD * fac[n - i] % MOD * ((i - (n + k) / 2) & 1 ? -1 : 1) + MOD) % MOD);
	return printf("%d\n", ans), 0;
}
