#include <bits/stdc++.h>
template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}
using namespace std;
using LL = long long;
const int N = 5e5 + 10;
const int L = 1e7 + 10;
const int MOD = 1e9 + 7;
int n, f[L], h[L], g[L], cb[L], mx;
unordered_map<int, int> ca;

void cps(int x) {
	for (int i = 1; i <= x / i; ++ i) {
		if (!(x % i)) {
			ca[i] ++;
			if (x / i != i) ca[x / i] ++;
		}
	}
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

inline void upd(int &x, const int &y) {
	x += y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

int main() {
	rd(n);
	for (int i = 1, tmp; i <= n; ++ i) {
		rd(tmp), cps(tmp), cb[tmp] ++;
		mx = max(mx, tmp);
		tmp = q2[i - 1], upd(tmp, tmp), upd(q2[i], tmp);
	}
	for (int i = mx, tmpa, tmpb; i; -- i) {
		f[i] = q2[ca[i]] - 1;
		for (int j = i << 1; j <= mx; j += i)
			upd(f[i], -f[j]);
		tmpa = tmpb = 0;
		for (int j = i; j <= mx; j += i)
			upd(tmpa, f[j]), upd(tmpb, cb[j]);
		h[i] = (LL)tmpa * tmpb % MOD;
		for (int j = i << 1; j <= mx; j += i)
			upd(h[i], -h[j]);
	}
	upd(h[1], (LL)-f[1] * n % MOD);
	return cout << h[1] << '\n', 0;
}
