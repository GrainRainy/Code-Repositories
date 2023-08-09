#include <bits/stdc++.h>
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
		static short st[40], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	} 
}

using namespace IO;
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
int n, q, k;
struct Edge {
	int head[N], idx;
	struct Node { int nxt, to; } edge[N << 1];
	void add(int a, int b) {
		edge[++ idx].nxt = head[a];
		edge[head[a] = idx].to = b;
	}
}ori, vir;
int fa[N], siz[N], dep[N], hs[N], dfn[N], stamp, top[N]; // compositions
int core[N], stk[N], tt; bool st[N];
int cnt[N], mn[N], mx[N]; // dp 
int ansn, ansx; LL anss;

void dfs1(int u, int depth, int father) {
	dep[u] = depth, fa[u] = father, siz[u] = 1;
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

bool cmp(const int &a, const int &b) { return dfn[a] < dfn[b]; }
void build() {
	sort(core + 1, core + k + 1, cmp);
	stk[tt = 1] = 1, vir.head[1] = -1;
	for (int i = 1, l; i <= k; ++ i) {
		if (core[i] == 1) continue;
		l = lca(core[i], stk[tt]);
		if (l != stk[tt]) {
			while (dfn[l] < dfn[stk[tt - 1]]) {
				vir.add(stk[tt], stk[tt - 1]);
				vir.add(stk[tt - 1], stk[tt]);
				tt --;
			}
			if (l != stk[tt - 1]) {
				vir.head[l] = -1;
				vir.add(l, stk[tt]);
				vir.add(stk[tt], l);
				stk[tt] = l;
			} else {
				vir.add(l, stk[tt]);
				vir.add(stk[tt], l);
				tt --;
			}
		}
		vir.head[core[i]] = -1;
		stk[++ tt] = core[i];
	}
	for (int i = 1; i < tt; ++ i)
		vir.add(stk[i], stk[i + 1]), vir.add(stk[i + 1], stk[i]);
}

void dp(int u, int father) {
	cnt[u] = st[u], mx[u] = 0, mn[u] = st[u] ? 0 : 0x3f3f3f3f;
	for (int i = vir.head[u], j, w; ~i; i = vir.edge[i].nxt) {
		j = vir.edge[i].to, w = dep[j] - dep[u];
		if (j == father) continue;
		dp(j, u);
		anss += 1ll * (k - cnt[j]) * cnt[j] * w;
		if (cnt[u] > 0) {
			ansn = min(ansn, mn[u] + mn[j] + w);
			ansx = max(ansx, mx[u] + mx[j] + w);
		}
		cnt[u] += cnt[j];
		mn[u] = min(mn[u], mn[j] + w);
		mx[u] = max(mx[u], mx[j] + w);
	}
	st[u] = false;
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
		input(k);
		anss = ansx = 0, ansn = 0x3f3f3f3f;
		for (int i = 1; i <= k; ++ i)
			input(core[i]), st[core[i]] = true;
		build();
		dp(1, 0);
		output(anss, ' '), output(ansn, ' '), output(ansx);
	}
	return 0;
}
