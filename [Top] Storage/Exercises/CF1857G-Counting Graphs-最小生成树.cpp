#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
const int MOD = 998244353;
int n, s, fa[N], siz[N];
map<LL, LL> mp;
struct Edge {
	int a, b, w;
	bool operator < (const Edge &t) const { return w < t.w; }
}e[N];
LL ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int qpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void solve() {
	rd(n), rd(s); mp.clean(), ans = 1;
	for (int i = 1; i < n; ++ i) {
		fa[i] = i, siz[i] = 1;
		rd(e[i].a), rd(e[i].b), rd(e[i].w);
	}
	fa[n] = n, siz[n] = 1;
	sort(e + 1, e + n);
	for (int i = 1, a, b; i < n; ++ i)
		if ((a = find(e[i].a)) != (b = find(e[i].b))) {
			mp[e[i].w] += (LL)siz[a] * siz[b] - 1;
			fa[b] = a, siz[a] += siz[b];
		}
	for (auto t : mp) {
		ans = ans * qpow(s - t.first + 1, t.second) % MOD;
	}
	ot(ans);
}

int main() {
	int t; rd(t);
	while (t --) solve();
	return 0;
}
