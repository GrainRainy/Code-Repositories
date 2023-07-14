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
const int K = 50 + 10;
const int MOD = 998244353;

int n, m;
int head[N], idx;
struct Node { int nxt, to; } edge[N << 1];
// graph 
int fa[N], siz[N], hs[N];
int dfn[N], top[N], stamp, node[N];
// partions 
LL dep[N][K], sum[N][K];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int depth, int father) {
	siz[u] = dep[u][0] = 1, fa[u] = father;
	for (int i = 1; i <= 50; ++ i) 
		dep[u][i] = dep[u][i - 1] * depth % MOD;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs1(j, depth + 1, u);
		siz[u] += siz[j];
		if (siz[j] > siz[hs[u]]) hs[u] = j;
	}
}

void dfs2(int u, int Top) {
	dfn[u] = ++ stamp, top[u] = Top, node[stamp] = u;
	if (hs[u]) dfs2(hs[u], Top);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!top[j]) dfs2(j, j);
	}
}

void init() {
	for (int i = 1; i <= n; ++ i) 
		for (int j = 1; j <= 50; ++ j) 
			sum[i][j] = (sum[i - 1][j] + dep[node[i]][j]) % MOD;
}

LL query(int a, int b, int k) {
	LL res = 0;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		res = (res + sum[dfn[a]][k] - sum[dfn[top[a]] - 1][k]) % MOD;
		a = fa[top[a]];
	}
	if (dep[a] < dep[b]) swap(a, b);
	res = (res + sum[dfn[a]][k] - sum[dfn[b] - 1][k]) % MOD;
	res = (res % MOD + MOD) % MOD;
	return res;
}

int main() {
	input(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) {
		input(a), input(b);
		add(a, b), add(b, a);
	}
	
	dfs1(1, 0 ,0);
	dfs2(1, 1);
	init();
	
	input(m);
	for (int i = 1, x, y, z; i <= m; ++ i) {
		input(x), input(y), input(z);
		output(query(x, y, z));
	}
	return 0;
}
