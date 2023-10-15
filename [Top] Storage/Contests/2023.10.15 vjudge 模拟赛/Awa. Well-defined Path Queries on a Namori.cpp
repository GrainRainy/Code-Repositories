#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
using namespace std;
const int N = 2e5 + 10;
int n, q, tmpa, tmpb, p[N], head[N], etp; 
struct Node { int nxt, to; }edge[N << 1];
int dep[N], fa[N], col[N], ctp = 1;

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
	dep[u] = depth, fa[u] = father;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == father) continue;
		dfs1(v, u, depth + 1);
	}
}

void dfs(int u, int color) {
	col[u] = color;
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if (!col[v = edge[i].to]) dfs(v, color);
}

void paint(int a, int b) {
	while (a != b) {
		if (dep[a] < dep[b]) swap(a, b);
		col[a] = 1, a = fa[a];
	}
	a = tmpa, b = tmpb;
	while (a != b) {
		if (dep[a] < dep[b]) swap(a, b);
		for (int i = head[a], v; ~i; i = edge[i].nxt)
			if (!col[v = edge[i].to]) dfs(v, ++ ctp);
		a = fa[a];
	}
}

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) p[i] = i, head[i] = -1;
	for (int i = 1, a, b, x, y; i <= n; ++ i) {
		rd(a), rd(b), x = find(a), y = find(b);
		if (x == y) tmpa = a, tmpb = b;
		else p[y] = x, add(a, b), add(b, a);
	}
	dfs1(1, 1, 0), paint(tmpa, tmpb);
	rd(q);
	int x, y;
	while (q --) {
		rd(x), rd(y);
		if (col[x] == col[y] and col[x] != 1) puts("Yes");
		else puts("No");
	}
	return 0;
}
