#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 3e5 + 10;
int n, m, head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int siz[N], dep[N], dfn[N], stamp;
LL ans[N];

struct Point {
	int dfn, dep, w;
	bool operator < (const Point &t) const { return dep < t.dep; }
}p[N];

struct Query {
	int l, r, dr, id;
	bool operator < (const Query &t) const { return dr < t.dr; }
}q[N << 1];

struct Bit {
	LL tr[N];
	inline void modify(int p, int v) { while (p <= n) tr[p] += v, p += p & -p; }
	LL query(int p) { LL res = 0; while (p) res += tr[p], p -= p & -p; return res; }
}tr;

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

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u, int father, int depth) {
	dfn[u] = ++ stamp, dep[u] = depth, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) 
		if ((j = edge[i].to) != father) dfs(j, u, depth + 1), siz[u] += siz[j];
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) rd(a), rd(b), add(a, b), add(b, a); 
	dfs(1, 0, 0);
	for (int i = 1; i <= n; ++ i) p[i] = { dfn[i], dep[i], siz[i] - 1 };
	for (int i = 1, p, k; i <= m; ++ i) {
		rd(p), rd(k);
		ans[i] = (LL)(siz[p] - 1) * min(dep[p], k);
		q[i << 1] = { dfn[p], dfn[p] + siz[p] - 1, dep[p], -i };
		q[(i << 1) - 1] = { dfn[p], dfn[p] + siz[p] - 1, dep[p] + k, i };
	}
	sort(p + 1, p + n + 1), sort(q + 1, q + (m << 1) + 1);
	for (int i = 1, j = 1; i <= m << 1; ++ i) {
		while (j <= n and p[j].dep <= q[i].dr) tr.modify(p[j].dfn, p[j].w), j ++;
		if (q[i].id > 0) ans[q[i].id] += tr.query(q[i].r) - tr.query(q[i].l);
		else ans[-q[i].id] -= tr.query(q[i].r) - tr.query(q[i].l);
	}
	for (int i = 1; i <= m; ++ i) ot(ans[i]);
	return 0;
}
