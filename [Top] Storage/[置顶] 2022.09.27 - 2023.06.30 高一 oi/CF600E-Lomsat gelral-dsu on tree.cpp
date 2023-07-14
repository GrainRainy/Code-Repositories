#include <iostream>
#include <cstring>

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
int n;
int col[N], cnt[N];
LL mxC, vC;
// basis 
int head[N], idx;
struct Node { int nxt, to; } edge[N << 1];
// graph
int siz[N], hs[N], dfn[N], stamp, node[N];
LL ans[N]; 

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
} 

inline void modify(int u) {
	cnt[col[u]] ++;
	if (cnt[col[u]] == mxC) vC += col[u];
	if (cnt[col[u]] > mxC) mxC = cnt[col[u]], vC = col[u];
}

inline void del(int u) { cnt[col[u]] --; }

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
	LL tmpmxC = mxC, tmpvC = vC;
	if (hs[u]) dfs(hs[u], u, true);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j != fa and j != hs[u])
			for (int k = dfn[j]; k <= dfn[j] + siz[j] - 1; k ++)
				modify(node[k]);
	}
	modify(u);
	ans[u] = vC;
	if (!kp) {
		for (int i = dfn[u]; i <= dfn[u] + siz[u] - 1; i ++)
			del(node[i]);
		mxC = tmpmxC, vC = tmpvC;
	}
}

int main() {
	input(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= n; ++ i) input(col[i]);
	for (int i = 1, u, v; i < n; ++ i) {
		input(u), input(v);
		add(u, v), add(v, u);
	}
	init(1, 0);
	dfs(1, 0, true);
	for (int i = 1; i <= n; ++ i) output(ans[i], " \n"[i == n]);
	return 0;
}
