#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e5 + 10;
int n, m, q, tmp, w[N], head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
int dfn[N], low[N], stk[N], tp, stp, dct; 
vector<int> g[N << 1];
int siz[N << 1], hs[N << 1], fa[N << 1], dep[N << 1];
int ndfn[N << 1], nd[N << 1], top[N << 1], nstp;
multiset<int> vl[N];
int tree[N << 3];
#define l(u) ((u) << 1)
#define r(u) ((u) << 1 | 1)
char op;

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
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++ stp, stk[++ tp] = u;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if (!dfn[v = edge[i].to]) {
			tarjan(v), low[u] = min(low[u], low[v]);
			if (low[v] == dfn[u]) {
				g[++ dct].emplace_back(u);
				g[u].emplace_back(dct);
				do {
					tmp = stk[tp --];
					g[dct].emplace_back(tmp);
					g[tmp].emplace_back(dct);
				} while (tmp != v);
			}
		} else low[u] = min(low[u], dfn[v]);
	}
}

void dfs1(int u, int father, int depth) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	for (auto v : g[u]) if (v != father) {
		dfs1(v, u, depth + 1);
		if (u > n and v <= n) vl[u - n].insert(w[v]);
		siz[u] += siz[v];
		if (siz[v] > siz[hs[u]]) hs[u] = v;
	}
}

void dfs2(int u, int t) {
	ndfn[u] = ++ nstp, nd[nstp] = u, top[u] = t;
	if (hs[u]) dfs2(hs[u], t);
	for (auto v : g[u]) if (!top[v]) dfs2(v, v);
}

void build(int u, int tl, int tr) {
	if (tl == tr) {
		if (nd[tl] <= n) tree[u] = w[nd[tl]];
		else tree[u] = *vl[nd[tl] - n].begin();
		return;
	}
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
	tree[u] = min(tree[l(u)], tree[r(u)]);
}

int qry(int u, int tl, int tr, int l, int r) {
	if (tl > r or tr < l) return 0x3f3f3f3f;
	if (l <= tl and tr <= r) return tree[u];
	int mid = tl + tr >> 1;
	return min(qry(l(u), tl, mid, l, r), qry(r(u), mid + 1, tr, l, r));
}

void mdy(int u, int tl, int tr, int p, int v) {
	if (tl == tr) return tree[u] = v, void();
	int mid = tl + tr >> 1;
	if (p <= mid) mdy(l(u), tl, mid, p, v);
	else mdy(r(u), mid + 1, tr, p, v);
	tree[u] = min(tree[l(u)], tree[r(u)]);
}

int main() {
	rd(n), rd(m), rd(q), dct = n;
	for (int i = 1; i <= n; ++ i) head[i] = -1, rd(w[i]);
	for (int i = 1, a, b; i <= m; ++ i) rd(a), rd(b), add(a, b), add(b, a);
	tarjan(1), dfs1(1, 0, 1), dfs2(1, 1), build(1, 1, dct);
	for (int i = 1, a, b; i <= q; ++ i) {
		do op = getchar(); while (op != 'C' and op != 'A');
		rd(a), rd(b);
		if (op == 'C') {
			if (fa[a] > n) {
				vl[fa[a] - n].erase(w[a]), vl[fa[a] - n].insert(b);
				mdy(1, 1, dct, ndfn[fa[a]], *vl[fa[a] - n].begin());
			}
			w[a] = b, mdy(1, 1, dct, ndfn[a], b);
		} else {
			int res = 0x3f3f3f3f;
			while (top[a] != top[b]) {
				if (dep[top[a]] < dep[top[b]]) swap(a, b);
				res = min(res, qry(1, 1, dct, ndfn[top[a]], ndfn[a]));
				a = fa[top[a]];
			}
			if (dep[a] < dep[b]) swap(a, b);
			res = min(res, qry(1, 1, dct, ndfn[b], ndfn[a]));
			if (b > n and b != 1) res = min(res, w[fa[b]]);
			ot(res, '\n');
		}
	}
	return 0;
}
