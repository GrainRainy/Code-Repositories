#include <iostream>
#include <cstring>

#define __DEBUG__ puts("__DEBUG__");

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

const int N = 3e5 + 10;
const int MOD = 1e9 + 7;
int n, m, ans;
struct Query { int a, b, lca; }q[N];
// bases 
int head[N], idx;
struct Node { int nxt, to; } edge[N << 1];
// graph
int uFa[N << 1]; // Union-Find Set 
int dep[N], siz[N], fa[N], hs[N], top[N];
// Tree Chain Partitions 

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int father) {
	fa[u] = father, dep[u] = dep[father] + 1, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs1(j, u);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	top[u] = Top;
	if (hs[u]) dfs2(hs[u], Top);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
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

int find(int x) {
	return x ^ uFa[x] ? uFa[x] = find(uFa[x]) : x;
}

void mergeChain(int u, int Top) {
	while (dep[fa[u]] > dep[Top]) {
		uFa[find(u)] = find(fa[u]);
		uFa[find(u + n)] = find(fa[u] + n);
		u = find(fa[u]);
	}
}

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	input(n), input(m);
	memset(head, -1, sizeof(int) * (n + 5));
	for (int i = 1; i <= (n << 1); ++ i) uFa[i] = i;
	for (int i = 1, a, b; i < n; ++ i) {
		input(a), input(b);
		add(a, b), add(b, a);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	for (int i = 1; i <= m; ++ i) {
		input(q[i].a), input(q[i].b);
		q[i].lca = lca(q[i].a, q[i].b);
		mergeChain(q[i].a, q[i].lca);
		mergeChain(q[i].b, q[i].lca);
	}
	for (int i = 1; i <= m; ++ i) {
		if (q[i].lca != q[i].a and q[i].lca != q[i].b) {
			uFa[find(q[i].a + n)] = find(q[i].b);
			uFa[find(q[i].b + n)] = find(q[i].a);
		}
	}
	for (int i = 2; i <= n; ++ i) {
		if (find(i) == find(i + n)) return puts("0"), 0;
		ans += find(i) == i;
		ans += find(i + n) == i + n;
	}
	return output(qpow(2, ans / 2), '\n'), 0;
}
