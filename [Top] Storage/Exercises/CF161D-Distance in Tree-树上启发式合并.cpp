#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
const int K = 5e2 + 10;
int n, k, head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
int siz[N], fa[N], dep[N], hs[N], dfn[N], node[N], stamp;
int ans, buc[N + K];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b) {
	edge[++ etp].nxt = head[a];
	edge[head[a] = etp].to = b;
}

void dfs1(int u, int father, int depth) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	dfn[u] = ++ stamp, node[stamp] = u;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == father) continue;
		dfs1(v, u, depth + 1);
		siz[u] += siz[v];
		if (siz[v] > siz[hs[u]]) hs[u] = v;
	}
}

void dfs2(int u, bool kp) {
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if ((v = edge[i].to) != fa[u] and v != hs[u]) dfs2(v, 0);
	if (hs[u]) dfs2(hs[u], 1);
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) != hs[u] and v != fa[u]) {
			for (int j = dfn[v]; j < dfn[v] + siz[v]; ++ j) 
				if (dep[node[j]] - dep[u] < k) ans += buc[k - dep[node[j]] + (dep[u] << 1)];
			for (int j = dfn[v]; j < dfn[v] + siz[v]; ++ j)
				buc[dep[node[j]]] ++;
		}
	}
	buc[dep[u]] ++, ans += buc[dep[u] + k];
	if (!kp) for (int i = dfn[u]; i < dfn[u] + siz[u]; ++ i)
		buc[dep[node[i]]] --;
}

int main() {
	rd(n), rd(k);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i)
		rd(a), rd(b), add(a, b), add(b, a);
	dfs1(1, 0, 1), dfs2(1, 1);
	return cout << ans << '\n', 0;
}
