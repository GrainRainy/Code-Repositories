#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;

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
}

using namespace IO;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int N = 1e6 + 10;
int n;
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
PII dep[N];
bool ans[N];
LL sum;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u, int depth, int fa) {
	dep[u] = {depth, u};
	sum += depth;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j != fa) dfs(j, depth + 1, u);
	}
}

int main() {
	input(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) {
		input(a), input(b);
		add(a, b), add(b, a);
	}
	dfs(1, 1, 0);
	if (sum & 1) return puts("-1"), 0;
	sort(dep + 1, dep + n + 1, greater<PII>());
	sum >>= 1;
	for (int i = 1; i <= n; ++ i) {
		if (sum >= dep[i].fi)
			sum -= dep[i].fi, ans[dep[i].se] = true;
		if (!sum) break;
	}
	if (sum) return puts("-1"), 0;
	for (int i = 1; i <= n; ++ i) {
		if (ans[i]) putchar('1'), putchar(' ');
		else putchar('0'), putchar(' ');
	}
	puts("");
	return 0;
}
