#include <bits/stdc++.h>
#define DEBUG puts("-- DEBUG --"); 
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
const int N = 1e5 + 10;
int n, q, k;
struct Edge {
	int head[N], idx;
	struct Node { int nxt, to; }edge[N << 1];
	void add(int a, int b) {
		edge[++ idx].nxt = head[a];
		edge[head[a] = idx].to = b;
	}
}ori, vir;
int fa[N], dep[N], siz[N], hs[N], dfn[N], stamp, top[N]; // composition
int core[N], stk[N], tt; bool st[N]; // virtual tree 
bool res[N]; int ans;

void dfs1(int u, int depth, int father) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	for (int i = ori.head[u], j; ~i; i = ori.edge[i].nxt) {
		j = ori.edge[i].to;
		if (j == father) continue;
		dfs1(j, depth + 1, u);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	top[u] = Top, dfn[u] = ++ stamp;
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = ori.head[u], j; ~i; i = ori.edge[i].nxt) {
		j = ori.edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

int lca(int a, int b) {
	while (top[a] ^ top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

inline bool cmp(const int &a, const int &b) {
	return dfn[a] < dfn[b];
}

void build() {
	sort(core + 1, core + k + 1, cmp);
	stk[tt = 1] = 1, vir.head[1] = -1;
	for (int i = 1, l; i <= k; ++ i) {
		if (core[i] == 1) continue;
		l = lca(stk[tt], core[i]);
		if (l != stk[tt]) {
			while (dfn[l] < dfn[stk[tt - 1]]) {
				vir.add(stk[tt], stk[tt - 1]);
				vir.add(stk[tt - 1], stk[tt]);
				tt --;
			}
			if (l != stk[tt - 1]) {
				vir.head[l] = -1;
				vir.add(l, stk[tt]), vir.add(stk[tt], l);
				stk[tt] = l;
			} else {
				vir.add(stk[tt], l), vir.add(l, stk[tt]);
				tt --;
			}
		}
		stk[++ tt] = core[i];
		vir.head[core[i]] = -1;
	}
	for (int i = 1; i < tt; ++ i)
		vir.add(stk[i], stk[i + 1]), vir.add(stk[i + 1], stk[i]);
}

void dp(int u, int father) {
	int cnt = 0;
	for (int i = vir.head[u], j; ~i; i = vir.edge[i].nxt) {
		j = vir.edge[i].to;
		if (j == father) continue;
		dp(j, u);
		if (res[j]) cnt ++, res[j] = false;
	}
	if (st[u]) ans += cnt, res[u] = true;
	else if (cnt > 1) ans ++, res[u] = false;
	else if (cnt == 1) res[u] = true;
	else res[u] = false;
}

void solve() {
	input(k);
	ans = 0;
	for (int i = 1; i <= k; ++ i) 
		input(core[i]), st[core[i]] = true;
	for (int i = 1; i <= k; ++ i)
		if (st[fa[core[i]]]) { puts("-1"); return; }
	build();
	dp(1, 0);
	output(ans);
}

int main() {
	input(n);
	memset(ori.head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) {
		input(a), input(b);
		ori.add(a, b), ori.add(b, a);
	}
	dfs1(1, 1, 0), dfs2(1, 1);
	input(q);
	while (q --) {
		solve();
		for (int i = 1; i <= k; ++ i) st[core[i]] = false;
	}
	return 0;
}
