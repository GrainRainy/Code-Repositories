#include <bits/stdc++.h>

#define __DEBUG__ puts("__DEBUG__");
#define enter putchar('\n')
#define endl '\n'
#define fi first
#define se second

namespace IO {
	#ifdef __LINUX__
	#define getchar() getchar_unlocked()
	#define putchar(a) putchar_unlocked(a)
	#endif
	
	#ifdef __WINDOWS__
	#define getchar() _getchar_nolock()
	#define putchar(a) _putchar_nolock()
	#endif
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar(); bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T, typename... Args> 
	void input(T &x, Args&... args) {
		input(x), input(args...);
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
	template <typename T, typename ...Args>
	void output(T x, char ch = ' ', Args... args) {
		output(x, ch);
		output(args...);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

const int N = 1e5 + 10;
int n, q, k, x, y;
int head[N], idx;
struct Node { int nxt, to, w; } edge[N << 1];
int dep[N], siz[N], fa[N], hs[N], top[N];
int impact;
int stk[N];

void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int depth, int father) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs1(j, depth + edge[i].w, u);
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
	while (top[a] ^ top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

int dis(int a, int b) { return dep[a] + dep[b] - 2 * dep[lca(a, b)]; }

int main() {
	input(n, q, k);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, x, y, w; i < n; ++ i) {
		input(x, y, w);
		add(x, y, w), add(y, x, w);
	}
	dfs1(1, 0, 0); 
	dfs2(1, 1);
	if (k == n) {
		for (int i = 1, tmp; i <= k; ++ i) input(tmp);
		while (q --) {
			input(x, y);
			output(dis(x, y), '\n');
		}
	} else if (k == 1) {
		input(impact);
		while (q --) {
			input(x, y);
			output(dis(x, impact) + dis(impact, y), '\n');
		}
	} else if (q == 1) {
		for (int i = 1; i <= k; ++ i) input(stk[i]);
		int ans = 1e9 + 10;
		input(x, y);
		for (int i = 1; i <= k; ++ i) {
			ans = min(ans, dis(x, stk[i]) + dis(stk[i], y));
		}
		output(ans);
	} else puts("0");
	return 0;
}
