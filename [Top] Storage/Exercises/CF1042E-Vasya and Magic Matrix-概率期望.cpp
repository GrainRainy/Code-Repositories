#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
const int MOD = 998244353;
int n, m, stx, sty;
int f[N], sx[N], sx2[N], sy[N], sy2[N], sf[N];
struct Pos {
	int val, x, y;
	bool operator < (const Pos &t) const { return val < t.val; }
}p[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int main() {
	rd(n), rd(m);
	for (int i = 1, tmp; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j) 
			rd(tmp), p[(i - 1) * m + j] = {tmp, i, j};
	rd(stx), rd(sty);
	sort(p + 1, p + n * m + 1);
	for (int i = 1, prec = 0; i <= n * m; ++ i) {
		if (p[i - 1].val != p[i].val) prec = i - 1;
		upd(f[i], (LL)p[i].x * p[i].x % MOD * prec % MOD);
		upd(f[i], (LL)p[i].y * p[i].y % MOD * prec % MOD);
		upd(f[i], add(sx2[prec], sy2[prec])), upd(f[i], sf[prec]);
		upd(f[i], MOD - 2ll * sx[prec] * p[i].x % MOD);
		upd(f[i], MOD - 2ll * sy[prec] * p[i].y % MOD);
		f[i] = (LL)f[i] * qpow(prec, MOD - 2) % MOD;
		if (p[i].x == stx and p[i].y == sty) return cout << f[i] << '\n', 0; 
		sx[i] = add(sx[i - 1], p[i].x), sy[i] = add(sy[i - 1], p[i].y);
		sx2[i] = add(sx2[i - 1], (LL)p[i].x * p[i].x % MOD);
		sy2[i] = add(sy2[i - 1], (LL)p[i].y * p[i].y % MOD);
		sf[i] = add(sf[i - 1], f[i]);
	}
	return 0;
}
