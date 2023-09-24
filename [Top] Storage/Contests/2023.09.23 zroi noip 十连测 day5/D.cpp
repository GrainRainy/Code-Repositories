#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
int n, head[N], idx, ttp;
struct Node { int nxt, to; }edge[N];
int dep[N], fa[N], t[N];
LL ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int father, int depth) {
	dep[u] = depth, t[depth] ++, fa[u] = father;
	for (int i = head[u]; ~i; i = edge[i].nxt)
		if (edge[i].to != fa[u]) dfs1(edge[i].to, u, depth + 1);
}

int main() {
//	freopen("test.in", "r", stdin);
	rd(n); memset(head, -1, sizeof head);
	for (int i = 2; i <= n; ++ i) 
		rd(fa[i]), add(fa[i], i), add(i, fa[i]);
	for (int i = 1; i <= n; ++ i) {
		memset(t, 0, sizeof(int) * (n + 10));
		dfs1(i, 0, 0);
		for (int j = 1; j <= n and t[j]; ++ j)
			if (t[i] >= 3) ans += (LL)t[j] * (t[j] - 1) / 2 * (t[j] - 2) / 3;
	}
	return cout << ans << '\n', 0;
}
