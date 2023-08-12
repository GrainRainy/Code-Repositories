#include <iostream>
#include <cstring>
#define lowbit(x) (x) & -(x)
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

const int N = 8e5 + 20;
int n, q;
int head[N], idx;
struct Node { int nxt, to; } edge[N << 1];
// bases 
int fa[N], dep[N], siz[N], hs[N];
int top[N], dfn[N], stamp, node[N];
// cuttings
int tree[N];
bool st[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int depth) {
	dep[u] = depth, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		dfs1(j, depth + 1);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	top[u] = Top; dfn[u] = ++ stamp; node[stamp] = u;
	if (hs[u]) dfs2(hs[u], Top);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

void modify(int pos, int val) {
	for (; pos <= n; pos += lowbit(pos)) tree[pos] += val;
}

int query(int pos) {
	int res = 0;
	for (; pos; pos -= lowbit(pos)) res += tree[pos];
	return res; 
}

int queryTree(int u) {
	return query(dfn[u] + siz[u] - 1) - query(dfn[u] - 1);
}

void solve(int u) {
	if (!queryTree(1)) return puts("0"), void();
	if (queryTree(u)) return output(u), void();
	// spj 
	while (top[u] and !queryTree(top[u])) u = fa[top[u]];
	if (!u) return output(u), void();
	
	int l = dfn[top[u]], r = dfn[u], mid;
	while (l < r) {
		mid = l + r + 1>> 1;
		if (queryTree(node[mid])) l = mid;
		else r = mid - 1;
	}
	// binary search
	return output(node[l]), void();
}

int main() {
	input(n), input(q);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 2; i <= n; ++ i) 
		input(fa[i]), add(fa[i], i);
	dfs1(1, 1);
	dfs2(1, 1);
	for (int i = 1, tmp; i <= q; ++ i) {
		input(tmp);
		if (tmp > 0 and st[tmp]) modify(dfn[tmp], -1), st[tmp] = 0;
		else if (tmp > 0 and !st[tmp]) modify(dfn[tmp], 1), st[tmp] = 1;
		else if (tmp < 0) solve(-tmp);
	}
	return 0;
}
