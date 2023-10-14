#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PLI = pair<long long, int>;
const int N = 1e5 + 10;
const int K = 50;
int n, m, q, head[N], etp;
struct Save {
	int a, b, w;
	bool operator < (const Save &t) const { return w < t.w; }
}sv[N];
struct Edge { int nxt, to, w; }edge[N << 1];
int dep[N], siz[N], fa[N], hs[N], top[N], dfn[N], stamp; 
int dsu[N], stk[N], stp;
LL dis[K][N], dist[N], ans;
bool st[N];

long long cnt = 0;

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

inline void add(int a, int b, int c) {
	cnt ++;
	edge[++ etp].nxt = head[a];
	edge[etp].w = c;
	edge[head[a] = etp].to = b;
} 

int find(int x) { return x == dsu[x] ? x : dsu[x] = find(dsu[x]); }
void Kruskal() {
	sort(sv + 1, sv + m + 1);
	for (int i = 1, a, b; i <= m; ++ i) {
		a = find(sv[i].a), b = find(sv[i].b);
		if (a != b) {
			dsu[b] = a, add(sv[i].a, sv[i].b, sv[i].w);
			add(sv[i].b, sv[i].a, sv[i].w);
		} else st[i] = true, stk[++ stp] = sv[i].a, stk[++ stp] = sv[i].b;
	}
}

void dfs1(int u, int father, int depth, LL d) {
	fa[u] = father, dep[u] = depth, dist[u] = d, siz[u] = 1;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == father) continue;
		dfs1(v, u, depth + 1, d + edge[i].w);
		siz[u] += siz[v];
		if (siz[v] > siz[hs[u]]) hs[u] = v;
	}
}

void dfs2(int u, int t) {
	dfn[u] = ++ stamp, top[u] = t;
	if (hs[u]) dfs2(hs[u], t);
	for (int i = head[u], v; ~i; i = edge[i].nxt) 
		if (!top[v = edge[i].to]) dfs2(v, v);
}

int lca(int a, int b) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

void djikstra(int u) {
	priority_queue<PLI, vector<PLI>, greater<PLI>> q;
	for (int i = 0; i <= n; ++ i) 
		dis[u][i] = 0x3f3f3f3f3f3f3f3f, st[i] = false;
	dis[u][stk[u]] = 0, q.push({0, stk[u]});
	while (q.size()) {
		int t = q.top().second; q.pop();
		if (st[t]) continue;
		st[t] = true;
		for (int i = head[t], v; ~i; i = edge[i].nxt) 
			if (dis[u][v = edge[i].to] > dis[u][t] + edge[i].w)
				dis[u][v] = dis[u][t] + edge[i].w, q.push({dis[u][v], v});
	}
}

int main() {
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i) head[i] = -1, dsu[i] = i;
	for (int i = 1; i <= m; ++ i)
		rd(sv[i].a), rd(sv[i].b), rd(sv[i].w);
	Kruskal(), dfs1(1, 0, 1, 0), dfs2(1, 1);
	for (int i = 1; i <= m; ++ i) if (st[i]) 
		add(sv[i].a, sv[i].b, sv[i].w), add(sv[i].b, sv[i].a, sv[i].w);
	for (int i = 1; i <= stp; ++ i) djikstra(i);
	rd(q);
	for (int i = 1, a, b; i <= q; ++ i) {
		rd(a), rd(b);
		ans = dist[a] + dist[b] - (dist[lca(a, b)] << 1);
		for (int j = 1; j <= stp; ++ j)
			ans = min(ans, dis[j][a] + dis[j][b]);
		ot(ans);
	}
	return 0;
}
