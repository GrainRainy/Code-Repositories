#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 5e3 + 10;
int n, head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int siz[N], hs[N], dep[N], fa[N], top[N], stamp;
long long ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u) {
	dep[u] = dep[fa[u]] + 1, siz[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
		dfs1(j);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	top[u] = Top;
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int j = edge[i].to;
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

int check(int i, int j, int k) {
	int a = dep[i] + dep[j] - dep[lca(i, j)] * 2;
	int b = dep[j] + dep[k] - dep[lca(j, k)] * 2;
	int c = dep[i] + dep[k] - dep[lca(i, k)] * 2;
	return (a == b) and (b == c);
}

int main() {
//	freopen("test.in", "r", stdin);
	rd(n); memset(head, -1, sizeof head);
	for (int i = 2; i <= n; ++ i) rd(fa[i]), add(fa[i], i);
	dfs1(1), dfs2(1, 1);
	for (int i = 1; i <= n; ++ i)
		for (int j = i + 1; j <= n; ++ j)
			for (int k = j + 1; k <= n; ++ k) 
				if (check(i, j, k)) {
					ans ++;
//					cout << i << ' ' << j << ' ' << k << '\n';
				}
	return cout << ans << '\n', 0;
}
