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
		static short st[100], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

const int N = 2e5 + 10;
int n, q;
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int sum[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

int dfs(int u, int fa) {
	bool f = false;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		f = true;
		sum[u] += dfs(j, u);
	}
	if (!f) return sum[u] = 1;
	return sum[u];
}

void solve() {
	input(n);
	memset(head, -1, sizeof(int) * (n + 10)); idx = 0;
	memset(sum, 0, sizeof(int) * (n + 10));
	for (int i = 1, x, y; i < n; ++ i)
		input(x), input(y), add(x, y), add(y, x);
	dfs(1, 0);
	input(q);
	for (int i = 1, x, y; i <= q; ++ i) {
		input(x), input(y);
		output((LL)sum[x] * sum[y]);
	}
	return;
}

int main() {
	int t; input(t);
	while (t -- ) solve();
	return 0;
}
