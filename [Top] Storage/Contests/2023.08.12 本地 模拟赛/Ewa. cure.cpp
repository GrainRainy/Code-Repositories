#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ', output(x);

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = __int128;
const int N = 5e5 + 10;
const int MOD = 998244353;
LL n, u, v, a[N], p, np, f[N];

LL qpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	freopen("cure.in", "r", stdin);
	freopen("cure.out", "w", stdout);
	input(n), input(u), input(v);
	p = u * qpow(v, MOD - 2) % MOD;
	np = (v - u) * qpow(v, MOD - 2) % MOD;
	for (int i = 1; i <= n; ++ i) input(a[i]);
	for (int i = 1; i <= n; ++ i) {
		f[i] = (f[i] + a[i]) % MOD;
		for (int j = 1; j <= i; ++ j) {
//			cout << i << ' ' << j << ' ';
//			output(tmp, ' ');
//			f[i] = tmp;
			f[i] = (f[i] + qpow(p, j) * qpow(np, i - j) % MOD * f[i - j] % MOD) % MOD;
//			output(f[i]);
		}
//		debug(i)
//		debug(f[i])
		f[i] = f[i] * qpow((1 - qpow(np, i) % MOD + MOD) % MOD, MOD - 2) % MOD;
//		debug(f[i])
	}
	output(f[n]);
//	output(f[3]);
//	LL tmp = (a[3] + p * p % MOD * np % MOD * f[1] + p * np % MOD * np * f[2] % MOD) % MOD;
//	output(tmp);
//	output(tmp * qpow((1 - qpow(np, 3) + MOD) % MOD, MOD - 2) % MOD);
	return 0;
}
