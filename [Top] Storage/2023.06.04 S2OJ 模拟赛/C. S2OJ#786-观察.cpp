#include <bits/stdc++.h>

#define __DEBUG__ puts("__DEBUG__"); 

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) 
			f |= (c == '-');
		for (; isdigit(c); c = getchar())
			x = x * 10 + (c ^ '0');
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

const int N = 8e5 + 10;
int n, q;
bool col[N];
int head[N], idx;
struct Node {
	int nxt, to;
}edge[N << 1];
// graph
int fa[N], dep[N], siz[N], top[N], hs[N];

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
	top[u] = Top;
	if (!hs[u]) return;
	dfs2(hs[u], Top);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

int lca(int a, int b) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	if (dep[a] < dep[b]) swap(a, b);
	return b;
}

void query(int u) {
	int mx = 0, id = 0, tmp;
	bool judge = false;
	for (int i = 1; i <= n; ++ i) {
		if (col[i]) {
			judge = true;
			tmp = lca(u, i);
			if (mx < dep[tmp]) {
				mx = dep[tmp];
				id = tmp;
			}
		}
	}
	if (!judge) puts("0");
	else output(id);
}

int main() {
	input(n), input(q);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 2; i <= n; ++ i) {
		input(fa[i]), add(fa[i], i);
	}
	
	dfs1(1, 1);
	dfs2(1, 1);
	
	int x;
	while (q --) {
		input(x);
		if (x > 0) col[x] ^= 1;
		else query(-x);
	}
	return 0;
}
