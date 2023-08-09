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
const int N = 1e5 + 10;
int n, m;
int head[N], idx;
struct Node { int nxt, to, w; }edge[N << 1];
int fa[N], siz[N], hs[N], dfn[N], stamp, node[N], top[N];
LL dep[N], ans, delta;
bool core[N];
set<int> st;
set<int>::iterator it;

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

void dfs1(int u, LL depth, int father) {
	dep[u] = depth, fa[u] = father, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs1(j, depth + edge[i].w, u);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	top[u] = Top, dfn[u] = ++ stamp, node[stamp] = u;
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

LL dist(int a, int b) {
	int lca = 0;
	LL res = dep[a] + dep[b];
	while (top[a] ^ top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	lca = dep[a] < dep[b] ? a : b;
	return res - (dep[lca] << 1);
}

int main() {
	input(n), input(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b, w; i < n; ++ i) {
		input(a), input(b), input(w);
		add(a, b, w), add(b, a, w);
	}
	dfs1(1, 0, 0), dfs2(1, 1);
	int x, pre, suf;
	while (m --) {
		input(x);
		if (!core[x]) st.insert(dfn[x]);
		pre = node[(it = st.lower_bound(dfn[x])) == st.begin() ? *--st.end() : *--it];
		suf = node[(it = st.upper_bound(dfn[x])) == st.end() ? *st.begin() : *it];
		if (core[x]) st.erase(dfn[x]);
		delta = dist(x, pre) + dist(x, suf) - dist(pre, suf);
		if (!core[x]) core[x] = true, ans += delta;
		else core[x] = false, ans -= delta;
		output(ans);
	}
	return 0;
}
