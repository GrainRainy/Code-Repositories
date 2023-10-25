#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int N = 1e5 + 10;
const int M = 5e3 + 10;
const int MOD = 1e9 + 7;
LL n, m, fac[N * 3] = {1}, fav[N * 3], f[M], ans;
struct Dots {
	int a, b, c;
	bool operator < (const Dots &t) const {
		if (a ^ t.a) return a < t.a;
		if (b ^ t.b) return b < t.b;
		return c < t.c;
	}
}p[M];

LL qpow(LL a, LL b) {
	LL res = 1;
	for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
	return res;
}

LL C(int n, int m) { return fac[n] * fav[m] % MOD * fav[n - m] % MOD; }
void upd(LL &x, LL y) { if ((x += y) >= MOD) x -= MOD; }
LL ulim(int a, int b, int c, int x = 0, int y = 0, int z = 0) {
	int dx = a - x, dy = b - y, dz = c - z;
	return C(dx + dy + dz, dx) * C(dy + dz, dy) % MOD;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * 3; ++ i) fac[i] = fac[i - 1] * i % MOD;
	fav[n * 3] = qpow(fac[n * 3], MOD - 2);
	for (int i = n * 3; i; -- i) fav[i - 1] = fav[i] * i % MOD;
	for (int i = 1; i <= m; ++ i) cin >> p[i].a >> p[i].b >> p[i].c;
	p[++ m] = {n, n, n}, sort(p + 1, p + m + 1);
	for (int i = 1; i <= m; ++ i) {
		f[i] = ulim(p[i].a, p[i].b, p[i].c);
		for (int j = 1; j < i; ++ j)
			if (p[i].a >= p[j].a and p[i].b >= p[j].b and p[i].c >= p[j].c)
				upd(f[i], MOD - f[j] * ulim(p[i].a, p[i].b, p[i].c, p[j].a, p[j].b, p[j].c) % MOD);
	}
	return cout << f[m] << '\n', 0;
}
