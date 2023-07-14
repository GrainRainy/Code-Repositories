// subtask: k == 0
#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --" << endl;
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using IO::input;
using namespace std;
using LL = long long;
const int N = 2.5e3 + 10;
const int M = 1e4 + 10;
int n, m, k;
int head[N], idx;
struct Node { int nxt, to; }edge[M << 1];
int path[N];
LL ans, w[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u, int step) {
	debug(u)
	if (step > 5) return;
	if (u == 1 and step == 5) {
		LL res = 0;
		for (int i = 1; i < 5; ++ i) res += w[path[i]];
		ans = max(ans, res);
		return;
	}
	path[step] = u;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		dfs(j, step + 1);
	}
}

int main() {
	memset(head, -1, sizeof head);
	input(n), input(m), input(k);
	for (int i = 2; i <= n; ++ i) input(w[i]);
	for (int i = 1, x, y; i <= m; ++ i) {
		input(x), input(y);
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	return printf("%lld\n", ans), 0;
}
