#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e5 + 10;
int n, m, head[N], etp;
struct Node { int nxt, to; }edge[N << 2];
int dfn[N], low[N], stp, stk[N], top, dcc, cnt;
int siz[N << 1], w[N << 1];
vector<int> g[N << 1];
long long ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ stp, stk[++ top] = u, cnt ++;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if (!dfn[v = edge[i].to]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				w[++ dcc] = 1; int tmp;
				g[dcc].emplace_back(u);
				g[u].emplace_back(dcc);
				do {
					tmp = stk[top --], w[dcc] ++;
					g[dcc].emplace_back(tmp);
					g[tmp].emplace_back(dcc);
				} while (tmp != v);
			}
		} else low[u] = min(low[u], dfn[v]);
	}
}

void dp(int u, int fa) {
	siz[u] = (u <= n);
	for (auto v : g[u]) if (v != fa) {
		dp(v, u);
		ans += w[u] * 2ll * siz[u] * siz[v];
		siz[u] += siz[v];
	}
	ans += w[u] * 2ll * siz[u] * (cnt - siz[u]);
}

int main() {
	rd(n), rd(m), dcc = n;
	memset(head, -1, sizeof(int) * (n + 10));
	memset(w, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i <= m; ++ i)
		rd(a), rd(b), add(a, b), add(b, a);
	for (int i = 1; i <= n; ++ i) 
		if (!dfn[i]) cnt = 0, tarjan(i, 0), top = 0, dp(i, 0);
	return cout << ans << '\n', 0;
}
