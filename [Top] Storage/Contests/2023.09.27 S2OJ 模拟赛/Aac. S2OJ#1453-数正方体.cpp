#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
const int MX = 1e6;
const int MOD = 998244353;
int t, a, b;
LL p[N] = {1}, fac[N] = {1}, fav[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void ot(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

LL qpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

inline LL C(int n, int m) { return fac[n] * fav[n - m] % MOD * fav[m] % MOD; }
int main() {
	rd(t);
	for (int i = 1; i <= MX; ++ i) {
		fac[i] = fac[i - 1] * i % MOD;
		p[i] = p[i - 1] << 1;
		if (p[i] >= MOD) p[i] -= MOD;
	}
	fav[MX] = qpow(fac[MX], MOD - 2);
	for (int i = MX - 1; ~i; -- i) fav[i] = fav[i + 1] * (i + 1) % MOD;
	while (t --) {
		rd(a), rd(b);
		ot(C(a, a - b) * p[a - b] % MOD);
	}
	return 0;
}
