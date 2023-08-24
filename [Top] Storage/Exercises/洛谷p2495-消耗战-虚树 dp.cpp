#include <bits/stdc++.h>
#define DEBUG puts("--DEBUG--");
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
using LL = long long;
const int N = 2.5e5 + 100;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k;
struct Edge {
	int head[N], idx;
	struct Node { int nxt, to, w; }edge[N << 1];
	void add(int a, int b, int c = 0) {
		edge[++ idx].nxt = head[a];
		edge[idx].w = c;
		edge[head[a] = idx].to = b;
	}  
}ori, vir;
int siz[N], dep[N], fa[N], hs[N], top[N], dfn[N], stamp; // compositions 
int core[N], stk[N], stkTop; // virtual tree 
bool isc[N]; LL f[N], mnw[N]; // dp 

void dfs1(int u, int depth, int father) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	for (int i = ori.head[u], j; ~i; i = ori.edge[i].nxt) {
		j = ori.edge[i].to;
		if (j == father) continue;
		mnw[j] = min(mnw[u], (LL)ori.edge[i].w);
		dfs1(j, depth + ori.edge[i].w, u);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	dfn[u] = ++ stamp, top[u] = Top;
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = ori.head[u], j; ~i; i = ori.edge[i].nxt) {
		j = ori.edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

int lca(int u, int v) {
	while (top[u] ^ top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

inline bool cmp(int a, int b) { return dfn[a] < dfn[b]; }
void build() {
	sort(core + 1, core + 1 + k, cmp);
	stk[stkTop = 1] = 1, vir.head[1] = -1;
	for (int i = 1, tmplca; i <= k; ++ i) {
		if (core[i] == 1) continue;
		tmplca = lca(core[i], stk[stkTop]);
		if (tmplca != stk[stkTop]) {
			while (dfn[tmplca] < dfn[stk[stkTop - 1]]) {
				vir.add(stk[stkTop], stk[stkTop - 1]);
				vir.add(stk[stkTop - 1], stk[stkTop]);
				stkTop --;
			}
			if (dfn[tmplca] != dfn[stk[stkTop - 1]]) {
				vir.head[tmplca] = -1;
				vir.add(tmplca, stk[stkTop]);
				vir.add(stk[stkTop], tmplca);
				stk[stkTop] = tmplca;
			} else {
				vir.add(tmplca, stk[stkTop]);
				vir.add(stk[stkTop], tmplca);
				stkTop --;
			}
		}
		vir.head[core[i]] = -1;
		stk[++ stkTop] = core[i];
	}
	for (int i = 1; i < stkTop; ++ i) {
		vir.add(stk[i], stk[i + 1]);
		vir.add(stk[i + 1], stk[i]);
	}
	return;
}

LL dp(int u, int father) {
	if (isc[u]) return f[u] = mnw[u];
	LL res = 0;
	for (int i = vir.head[u], j; ~i; i = vir.edge[i].nxt) {
		j = vir.edge[i].to;
		if (j == father) continue;
		res += dp(j, u);
	}
	return f[u] = min((LL)mnw[u], res);
}

int main() {
	input(n);
	memset(ori.head, -1, sizeof(int) * (n + 10));
	for (int i = 1, u, v, w; i < n; ++ i) {
		input(u), input(v), input(w);
		ori.add(u, v, w), ori.add(v, u, w);
	}
	mnw[1] = INF;
	dfs1(1, 1, 0), dfs2(1, 1);
	input(m);
	while (m --) {
		input(k);
		vir.idx = 0;
		for (int i = 1; i <= k; ++ i)
			input(core[i]), isc[core[i]] = true;
		build();
		dp(1, 0);
		output(f[1]);
		for (int i = 1; i <= k; ++ i) isc[core[i]] = false;
	}
	return 0;
}
