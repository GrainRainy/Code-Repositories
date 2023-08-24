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
const int N = 500 + 10;
const int H = 1e6 + 10;
const int MOD = 1e9 + 7;
int n, k, h[N];
int fav[H], fac[H], mx;
int stk[N], top;
struct CartesianTree {
	int s[2];
	#define l(x) tree[x].s[0]
	#define r(x) tree[x].s[1]
}tree[N];
int f[N][N];

void build() {
	for (int i = 1; i <= n; ++ i) {
		while (top and h[stk[top]] > h[i]) l(i) = stk[top --];
		if (top) r(stk[top]) = i;
		stk[++ top] = i;
	}
}

void init() {
	fac[0] = fac[1] = fav[0] = fav[1] = 1;
	for (int i = 2; i <= mx; ++ i) 
		fav[i] = (LL)(MOD - MOD / i) * fav[MOD % i] % MOD;
	for (int i = 2; i <= mx; ++ i) {
		fac[i] = (LL)fac[i - 1] * i % MOD;
		fav[i] = (LL)fav[i - 1] * fav[i] % MOD;
	}
}

int C(int n, int m) {
	return (LL)fac[n] * fav[n - m] % MOD * fav[m] % MOD;
}

int dfs(int u, int lw) {
	f[u][0] = 1;
	int siz = 1, tmpsiz;
	for (int s = 0, v; s < 2; ++ s) {
		v = tree[u].s[s];
		if (!v) continue;
		siz += tmpsiz = dfs(v, h[u]);
		for (int i = min(siz, k); i; i --) 
			for (int j = 1; j <= min(tmpsiz, i); ++ j)
				f[u][i] = (f[u][i] + (LL)f[u][i - j] * f[v][j] % MOD) % MOD;
	}
	for (int i = min(siz, k); i; -- i)
		for (int j = 1; j <= min(h[u] - lw, i); ++ j)
			f[u][i] = (f[u][i] + (LL)f[u][i - j] * fac[j] % MOD * C(h[u] - lw, j) % MOD * C(siz - (i - j), j) % MOD) % MOD;
	return siz;
}

int main() {
	input(n), input(k);
	for (int i = 1; i <= n; ++ i) 
		input(h[i]), mx = max(mx, h[i]);
	mx = max(mx, n);
	build();
	init();
	dfs(stk[1], 0);
	return printf("%d\n", f[stk[1]]), 0;
}
