#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
int n, m, q, mx, inv[N] = {0, 1}, p[N], ans[N], top;
pair<int, int> tmp[N];
inline void upd(int &x, const int &y) { x += y; if (x >= MOD) x -= MOD;}
inline int add(const int &x, const int &y) { return x + y >= MOD ? x + y - MOD : x + y; }
struct BIT {
	int tr[N];
	inline void add(int p, int v) { while (p <= n) upd(tr[p], v), p += p & -p; }
	int query(int r) { int res = 0; while (r) upd(res, tr[r]), r -= r & -r; return res; }
}t; 
struct Dots {
	int x, y, v, id;
	bool operator < (const Dots &t) const { return x ^ t.x ? x < t.x : id < t.id; }
}d[N * 5];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (c < '0' or c > '9') c = getchar();
	for (; c >= '0' and c <= '9'; c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int main() {
	rd(n), rd(m), rd(q);
	for (int i = 1; i <= n; ++ i) rd(tmp[i].first), rd(tmp[i].second), mx = max({mx, tmp[i].first, tmp[i].second});
	for (int i = 2; i <= mx; ++ i) inv[i] = (LL)(MOD - MOD / i) * inv[MOD % i] % MOD;
	for (int i = 1; i <= n; ++ i) p[i] = (LL)tmp[i].first * inv[tmp[i].second] % MOD, upd(p[i], p[i - 1]);
	for (int i = 1, u, v; i <= m; ++ i) rd(u), rd(v), d[++ top] = {u, v, (LL)(add(p[u], MOD - p[u - 1])) * (add(p[v], MOD - p[v - 1])) % MOD, 0};
	for (int i = 1, l, r; i <= q; ++ i) {
		rd(l), rd(r), ans[i] = add(p[r], MOD - p[l - 1]);
		d[++ top] = {r, r, -1, i}, d[++ top] = {l - 1, l - 1, -1, i}, d[++ top] = {l - 1, r, 1, i}, d[++ top] = {r, l - 1, 1, i};
	}
	sort(d + 1, d + top + 1);
	for (int i = 1; i <= top; ++ i) 
		d[i].id ? upd(ans[d[i].id], add(MOD, d[i].v * t.query(d[i].y))) : t.add(d[i].y, d[i].v);
	for (int i = 1; i <= q; ++ i) ot(ans[i]);
	return 0;
}
