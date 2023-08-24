#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar()) ;
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
	template <typename T> inline void ot(T x, char ed = '\n') {
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using UI = unsigned int;
using LL = long long;
const int N = 5e5 + 10;
const int LOGN = 19;
UI s; LL ans;
int n, q, rt, head[N], idx, pre;
struct Node { int nxt, to; }edge[N];
int fa[N][LOGN + 5], mxl[N], dep[N], ls[N], top[N];
vector<int> up[N], dn[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u) {
	mxl[u] = 1, dep[u] = dep[fa[u][0]] + 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		for (int k = 0; fa[j][k]; ++ k)
			fa[j][k + 1] = fa[fa[j][k]][k];
		dfs1(j);
		if (mxl[j] + 1 > mxl[u]) mxl[u] = mxl[j] + 1, ls[u] = j;
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	if (u == t) {
		for (int i = 0, p = u; i <= mxl[u]; ++ i) 
			up[u].push_back(p), p = fa[p][0];
		for (int i = 0, p = u; i <= mxl[u]; ++ i)
			dn[u].push_back(p), p = ls[p];
	}
	if (ls[u]) dfs2(ls[u], t);
	for (int i = head[u]; ~i; i = edge[i].nxt)
		if (!top[edge[i].to]) dfs2(edge[i].to, edge[i].to);
}

int query(int u, int k) {
	if (!k) return u;
	u = fa[u][(int)log2(k)], k -= 1 << (int)log2(k);
	k -= dep[u] - dep[top[u]], u = top[u];
	return k >= 0 ? up[u][k] : dn[u][-k];
}

UI get(UI x) { return x ^= x << 13, x ^= x >> 17, x ^= x << 5, s = x; }
int main() {
	rd(n), rd(q), rd(s);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= n; ++ i) 
		rd(fa[i][0]), add(fa[i][0], i);
	dfs1(rt = edge[head[0]].to);
	dfs2(rt, rt);
	for (int i = 1, x, k; i <= q; ++ i) {
		x = (get(s) ^ pre) % n + 1;
		k = (get(s) ^ pre) % dep[x];
		ans ^= (LL)i * (pre = query(x, k));
	}
	ot(ans, '\n');
	return 0;
}
