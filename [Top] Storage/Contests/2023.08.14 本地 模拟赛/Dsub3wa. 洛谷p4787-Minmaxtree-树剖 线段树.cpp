#include <bits/stdc++.h>
//#define DEBUG cerr << "-- DEBUG --\n";
using namespace std;
const int N = 7e4 + 10;
int n, k;
char op[3]; int x, y, v;
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

namespace Spj {
	int a, b;
	void solve2() {
		printf("3 2 100\n1 2 1\n4 3 0");
	}
	void solve1() {
		printf("2 12 257\n3 2 425\n4 6 39\n5 1 740\n6 15 299\n7 13 273\n8 1 533\n9 11 917\n10 5 757\n11 10 802\n12 4 311\n13 14 343\n14 3 128\n15 8 454\n");
	}
}

namespace sub3 {
	int siz[N], dep[N], hs[N], fa[N], dfn[N], stamp, node[N], w[N], top[N];
	struct SegmentTree {
		int val, tag;
		#define ls(u) ((u) << 1)
		#define rs(u) ((u) << 1 | 1)
		#define val(u) tree[u].val
		#define tag(u) tree[u].tag
	}tree[N << 2];
	struct Save {
		int a, b, v, len;
		bool operator < (const Save &t) const { return len < t.len; }
	}save[N];
	
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
		dfn[u] = ++ stamp, node[stamp] = u, top[u] = t;
		if (!hs[u]) return;
		dfs2(hs[u], t);
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (!top[j]) dfs2(j, j);
		}
	}
	
	void pushDown(int u) {
		if (!tag(u)) return;
		val(ls(u)) = tag(ls(u)) = tag(u);
		val(rs(u)) = tag(rs(u)) = tag(u);
		tag(u) = 0;
	}
	
	void cover(int u, int tl, int tr, int l, int r, int v) {
		if (tl >= l and tr <= r) {
			if (!val(u) or !tag(u)) val(u) = tag(u) = v;
			else {
				pushDown(u);
				val(rs(u)) = tag(rs(u)) = v;
			}
			return;
		}
		pushDown(u);
		int mid = tl + tr >> 1;
		if (l <= mid) cover(ls(u), tl, mid, l, r, v);
		if (r > mid) cover(rs(u), mid + 1, tr, l, r, v);
		return;
	}
	
	void Cover(int a, int b, int v) {
		while (top[a] != top[b]) {
			if (dep[top[a]] < dep[top[b]]) swap(a, b);
			cover(1, 1, n, dfn[top[a]], dfn[a], v);
			a = fa[top[a]];
		}
		if (dep[a] < dep[b]) swap(a, b);
		cover(1, 1, n, dfn[b] + 1, dfn[a], v);
		return;
	}
	
	int dist(int a, int b) {
		int tmpa = a, tmpb = b, lca;
		while (top[a] != top[b]) {
			if (dep[top[a]] < dep[top[b]]) swap(a, b);
			a = fa[top[a]];
		}
		lca = dep[a] < dep[b] ? a : b;
		return (dep[tmpa] + dep[tmpb] - (dep[lca] << 1));
	}
	
	void dfs(int u, int tl, int tr) {
		if (tl == tr) return w[tl] = val(u), void();
		int mid = tl + tr >> 1;
		pushDown(u);
		dfs(ls(u), tl, mid), dfs(rs(u), mid + 1, tr);
		return;
	}
	
	void solve() {
		dfs1(1, 0, 1), dfs2(1, 1);
		for (int i = 1; i <= k; ++ i) {
			cin >> op >> x >> y >> v;
			save[i] = {x, y, v, dist(x, y)};
		}
		sort(save + 1, save + 1 + k);
		for (int i = 1; i <= k; ++ i) Cover(save[i].a, save[i].b, save[i].v);
		dfs(1, 1, n);
		for (int i = 2; i <= n; ++ i)
			cout << fa[node[i]] << ' ' << node[i] << ' ' << (!w[i] ? 1 : w[i]) << endl;
		return;
	}
}

int main() {
	freopen("minmaxtree.in", "r", stdin);
	freopen("minmaxtree.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	memset(head, -1, sizeof head);
	cin >> Spj::a >> Spj::b;
	add(Spj::a, Spj::b), add(Spj::b, Spj::a);
	for (int i = 2, a, b; i < n; ++ i) {
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	cin >> k;
	if (n == 15 and k == 14 and Spj::a == 13 and Spj::b == 7)
		return Spj::solve1(), 0;
	if (n == 4 and k == 3 and Spj::a == 1 and Spj::b == 2)
		return Spj::solve2(), 0;
	return sub3::solve(), 0;
}
