#include <bits/stdc++.h>
#define enter putchar('\n')
#define endl '\n'
#define fi first
#define se second
#define DEBUG puts("__DEBUG__");
#define debug(x) cout << #x << ' ' << x << endl;

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
const int N = 2e5 + 10;
int n, m;
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int st[N], col[N], step[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

bool dfs(int u, int fa, int tarCol) {
	if (u == 1 and fa) return true;
	st[u] = true, step[u] = step[fa] ^ 1;
	col[u] ^= 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa or col[j] != tarCol) continue;
		if (st[j] and col[1] ^ col[j] ^ step[j]) return true;
		if (dfs(j, u, tarCol ^ 1)) return true;
	}
	return false;
}

int main() {
	input(n), input(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i <= m; ++ i) {
		input(a), input(b);
		add(a, b), add(b, a);
	}
	for (int i = 1; i <= n; ++ i) input(col[i]);
	step[1] = 1;
	if (dfs(1, 0, col[1] ^ 1)) puts("Yes");
	else puts("No");
	return 0;
}
