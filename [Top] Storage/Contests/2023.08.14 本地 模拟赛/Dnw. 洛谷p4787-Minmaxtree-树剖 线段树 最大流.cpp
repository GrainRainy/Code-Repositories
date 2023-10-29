#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
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
}

using namespace IO;
using namespace std;
using PII = pair<int, int>;
const int N = 7e4 + 10;
const int INF = 1e9 + 7;
int n, m, w[N]; char op[3];
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int ans[N];
map<int, int> mp;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

struct TreeDecomposition {
	int siz[N], dep[N], fa[N], dfn[N], top[N], hs[N], stamp;
	
	void dfs1(int u, int father, int depth) {
		fa[u] = father, dep[u] = depth, siz[u] = 1;
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (j == father) continue;
			dfs1(j, u, depth + 1);
			siz[u] += siz[j];
			if (siz[j] > siz[hs[u]]) hs[u] = j;
		}
	}
	
	void dfs2(int u, int t) {
		dfn[u] = ++ stamp, top[u] = t;
		if (!hs[u]) return;
		dfs2(hs[u], t);
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (!top[j]) dfs2(j, j);
		}
	}
}td;

struct SegmentTree {
	struct Node {
		int mxv, mnv, mxt, mnt;
		#define l(u) ((u) << 1)
		#define r(u) ((u) << 1 | 1)
		#define mxv(u) tree[u].mxv
		#define mnv(u) tree[u].mnv
		#define mxt(u) tree[u].mxt
		#define mnt(u) tree[u].mnt
	}tree[N << 2];
	
	inline void updx(int &x, int y) { (x < y) and (x = y); }
	inline void updn(int &x, int y) { (x > y) and (x = y); }
	inline void pushUp(int u) {
		mxv(u) = min(mxv(l(u)), mxv(r(u)));
		mnv(u) = max(mnv(l(u)), mnv(r(u)));
	}
	
	inline void pushDown(int u) {
		if (mnt(u) >= 0) {
			updx(mnv(l(u)), mnt(u)), updx(mnv(r(u)), mnt(u));
			updx(mnt(l(u)), mnt(u)), updx(mnt(r(u)), mnt(u));
			mnt(u) = -1;
		}
		if (mxt(u) <= INF) {
			updn(mxv(l(u)), mxt(u)), updn(mxv(r(u)), mxt(u));
			updn(mxt(l(u)), mxt(u)), updn(mxt(r(u)), mxt(u));
			mxt(u) = INF;
		}
	}
	
	void build(int u, int tl, int tr) {
		mnt(u) = -1, mxt(u) = INF;
		if (tl == tr) return mnv(u) = -1, mxv(u) = INF, void();
		int mid = tl + tr >> 1;
		build(l(u), tl, mid), build(r(u), mid + 1, tr);
		pushUp(u);
	} 
	
	PII query(int u, int tl, int tr, int pos) {
		if (tl == tr) return {mnv(u), mxv(u)};
		pushDown(u);
		int mid = tl + tr >> 1;
		if (pos <= mid) return query(l(u), tl, mid, pos);
		else return query(r(u), mid + 1, tr, pos);
	}
	
	void modifyRange(int u, int tl, int tr, int l, int r, int val, bool op) {
		if (tl >= l and tr <= r) {
			if (op) updx(mnv(u), val), updx(mnt(u), val);
			else updn(mxv(u), val), updn(mxt(u), val);
			return;
		}
		pushDown(u);
		int mid = tl + tr >> 1;
		if (l <= mid) modifyRange(l(u), tl, mid, l, r, val, op);
		if (r > mid) modifyRange(r(u), mid + 1, tr, l, r, val, op);
		pushUp(u);
	}
	
	void modifyPath(int u, int v, int val, bool op) {
		while (td.top[u] != td.top[v]) {
			if (td.dep[td.top[u]] < td.dep[td.top[v]]) swap(u, v);
			modifyRange(1, 1, n, td.dfn[td.top[u]], td.dfn[u], val, op);
			u = td.fa[td.top[u]];
		}
		if (td.dep[u] < td.dep[v]) swap(u, v);
		modifyRange(1, 1, n, td.dfn[v] + 1, td.dfn[u], val, op);
	}
}st;

struct NetworkFlow {
	int s, t, now[N << 1], head[N << 1], dis[N << 1], idx = 1;
	struct Node { int nxt, to, f; }edge[N << 3];
	inline void add(int a, int b, int c) {
		edge[++ idx].nxt = head[a];
		edge[idx].f = c;
		edge[head[a] = idx].to = b;
	}
	
	bool bfs() {
		for (int i = 1; i <= t; ++ i) dis[i] = INF;
		queue<int> q;
        q.push(s), dis[s] = 0, now[s] = head[s];
        while (q.size()) {
			auto u = q.front(); q.pop();
			for (int i = head[u], j; ~i; i = edge[i].nxt) {
				j = edge[i].to;
				if (edge[i].f and dis[j] == INF) {
					q.push(j), dis[j] = dis[u] + 1, now[j] = head[j];
					if (j == t) return true;
				}
			} 
		}
		return false;
	}

	int dfs(int u, int limit) {
		if (u == t) return limit;
		int tmp, res = limit;
		for (int i = now[u], j; ~i and res; i = edge[i].nxt) {
			now[u] = i, j = edge[i].to;
			if (edge[i].f and dis[j] == dis[u] + 1) {
				tmp = dfs(j, min(res, edge[i].f));
				if (!tmp) dis[j] = INF;
				edge[i].f -= tmp;
				edge[i ^ 1].f += tmp;
				res -= tmp;
			}
		}
		return limit - res;
	}
}nf;

int main() {
	rd(n);
	memset(head, -1, sizeof head);
	memset(nf.head, -1, sizeof nf.head);
	for (int i = 1, a, b; i < n; ++ i)
		rd(a), rd(b), add(a, b), add(b, a);
	td.dfs1(1, 0, 1), td.dfs2(1, 1);
	st.build(1, 1, n);
	rd(m);
	nf.s = n + m + 1, nf.t = nf.s + 1;
	for (int i = 1, x, y; i <= m; ++ i) {
		nf.add(nf.s, i, 1), nf.add(i, nf.s, 0);
		scanf("%s", op), rd(x), rd(y), rd(w[i]);
		st.modifyPath(x, y, w[i], *op == 'm');
		mp[w[i]] = i;
	}
	for (int i = 2; i <= n; ++ i) {
		ans[i] = -1;
		nf.add(i + m, nf.t, 1), nf.add(nf.t, i + m, 0);
		auto t = st.query(1, 1, n, td.dfn[i]);
		if (t.first >= 0) {
			nf.add(mp[t.first], i + m, 1);
			nf.add(i + m, mp[t.first], 0);
		}
		if (t.second <= 1e9) {
			nf.add(mp[t.second], i + m, 1);
			nf.add(i + m, mp[t.second], 0);
		}
	}
	while (nf.bfs()) nf.dfs(nf.s, INF);
	for (int u = 1; u <= m; ++ u)
		for (int i = nf.head[u], j; ~i; i = nf.edge[i].nxt) {
			j = nf.edge[i].to;
			if (j > m and j <= m + n and !nf.edge[i].f) {
				ans[j - m] = w[u];
				break;
			}
		}
	for (int i = 2; i <= n; ++ i) {
		ot(td.fa[i], ' '), ot(i, ' ');
		if (!(~ans[i])) {
			auto t = st.query(1, 1, n, td.dfn[i]);
			ot(t.first == -1 ? 0 : t.first, '\n');
		} else ot(ans[i], '\n');
	}
	return 0;
}
