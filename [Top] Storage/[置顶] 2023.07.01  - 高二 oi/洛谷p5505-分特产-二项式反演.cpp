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
const int N = 1e3 + 10;
const int MOD = 1e9 + 7;
int n, m, cnt[N], mx, ans;
int fac[N << 1], fav[N << 1];

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
inline void upd(int &x, int y) { x += y; (x < 0) and (x += MOD); (x >= MOD) and (x -= MOD); }

int main() {
	input(n), input(m);
	for (int i = 1; i <= m; ++ i) input(cnt[i]), mx = max(mx, cnt[i]);
	fac[0] = 1, mx += n;
	for (int i = 1; i <= mx; ++ i) fac[i] = (LL)fac[i - 1] * i % MOD;
	fav[mx] = qpow(fac[mx], MOD - 2);
	for (int i = mx - 1; ~i; -- i) fav[i] = (LL)fav[i + 1] * (i + 1) % MOD;
	for (int i = 0, tmp; i < n; ++ i) {
		tmp = C(n, i);
		for (int j = 1; j <= m; ++ j) 
			tmp = (LL)tmp * C(cnt[j] + n - i - 1, n - i - 1) % MOD;
		upd(ans, ((i & 1) ? -1 : 1) * tmp);
	}
	return printf("%d\n", ans), 0;
}
