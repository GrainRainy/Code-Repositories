#include <iostream>
#include <cstring>
#include <algorithm>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f|= (c == '-');
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

const int N = 1e5 + 10;
int n, m;
int col[N], cnt[N], tCol;
int ans[N];
// basis
int head[N], idx;
struct Node { int nxt, to; } edge[N << 1];
// graph 
int siz[N], hs[N], node[N], dfn[N], stamp;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

inline void modify(int u) {
	if (!cnt[col[u]]) tCol ++;
	cnt[col[u]] ++;
}

inline void del(int u) {
	cnt[col[u]] --;
	if (!cnt[col[u]]) tCol --;
}

void init(int u, int fa) {
	dfn[u] = ++ stamp, siz[u] = 1, node[stamp] = u;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		init(j, u);
		siz[u] += siz[j];
		if (siz[hs[u]] < siz[j]) hs[u] = j;
	}
}

void dfs(int u, int fa, bool kp) {
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j != fa and j != hs[u]) dfs(j, u, false);
	}
	if (hs[u]) dfs(hs[u], u, true);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa or j == hs[u]) continue;
		for (int k = dfn[j]; k <= dfn[j] + siz[j] - 1; k ++) 
			modify(node[k]);
	}
	modify(u);
	ans[u] = tCol;
	if (!kp) for (int i = dfn[u]; i <= dfn[u] + siz[u] - 1; i ++) 
		del(node[i]);
}

int main() {
	input(n);
	memset(head, -1, sizeof (int) * (n + 10));
	for (int i = 1, u, v; i < n; ++ i) {
		input(u), input(v);
		add(u, v), add(v, u);
	} 
	for (int i = 1; i <= n; ++ i) input(col[i]);
	
	init(1, 0);
	dfs(1, 0, true);
	
	input(m);
	for (int i = 1, tmp; i <= m; ++ i) 
		input(tmp), output(ans[tmp]);
	return 0;
}

