#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctime>

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
using PII = pair<int, int>;

const int N = 1e5 + 10;
int n, m;
int rt[N], rTop;
vector<PII> q[N]; // vertex and kth 
// basis 
int head[N], nTop;
struct Node {
	int nxt, to;
}edge[N];
// graph
int fa[N], dep[N], siz[N], hs[N], top[N], dfn[N], stamp;
int node[N];
// cuttings 
int cnt[N], ans[N];
// dsu on tree 

inline void add(int a, int b) {
	edge[++ nTop].nxt = head[a];
	edge[head[a] = nTop].to = b;
}

inline void add(int u) { cnt[dep[u]] ++; }
inline void del(int u) { cnt[dep[u]] --; }

void dfs1(int u, int depth) {
	dep[u] = depth, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		dfs1(j, depth + 1);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
	return;
}

void dfs2(int u, int Top) {
	dfn[u] = ++ stamp, top[u] = Top, node[stamp] = u;
	if (!hs[u]) return; dfs2(hs[u], Top);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
	return;
}

void dfs3(int u, bool kp) {
//	output(u);
	for (int i = head[u]; ~i; i = edge[i].nxt)
		if (edge[i].to != hs[u]) dfs3(edge[i].to, false);
	if (hs[u]) dfs3(hs[u], true);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to; if (j == hs[u]) continue;
		for (int k = dfn[j]; k <= dfn[j] + siz[j] - 1; ++ k) add(node[k]);
	}
	add(u);
	for (auto t : q[u]) {
		ans[t.second] = cnt[t.first + dep[u]];
	}
	if (!kp) for (int i = dfn[u]; i <= dfn[u] + siz[u] - 1; ++ i) del(node[i]);
	return;
}

int query(int u, int kth) {
	while (kth >= dfn[u] - dfn[top[u]] + 1 and u) {
		kth -= dfn[u] - dfn[top[u]] + 1;
		u = fa[top[u]];
	}
	return node[dfn[u] - kth];
}

int main() {
//	freopen("test.in", "r", stdin);
	memset(head, -1, sizeof head);
	input(n);
	for (int i = 1; i <= n; ++ i) {
		input(fa[i]);
		if (fa[i]) add(fa[i], i);
		else rt[++ rTop] = i;
	}
	
	for (int i = 1; i <= rTop; ++ i) dfs1(rt[i], 1), dfs2(rt[i], rt[i]);
	
	input(m);
	for (int i = 1, x, y, z; i <= m; ++ i) {
		input(x), input(y);
		z = query(x, y);
		q[z].push_back({y, i});
	}
	for (int i = 1; i <= rTop; ++ i) dfs3(rt[i], 0);
	for (int i = 1; i <= m; ++ i) output(max(ans[i] - 1, 0), " \n"[i == m]);
	return 0;
}
