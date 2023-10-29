#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 5e5 + 10;
int n, m, w[N], dg[N], head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
LL dp[N][2];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

void dfs(int u, int fa) {
	priority_queue<LL, vector<LL>, greater<LL>> q;
	LL lim = 0, nl = 0;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == fa) continue;
		dfs(v, u);
		LL a = max(dp[v][0] + min(w[u], w[v]), dp[v][1] + w[u]);
		LL b = max(dp[v][0] + w[v], dp[v][1] + m) - a;
		nl += a;
		if (q.size() < dg[u] - 1 >> 1) q.push(b);
		else if (q.size() and q.top() < b) q.pop(), q.push(b);
	}
	if (!q.size()) return dp[u][0] = nl, void();
	lim += q.top(), q.pop();
	while (q.size()) nl += q.top(), q.pop();
	dp[u][0] = lim + nl, dp[u][1] = nl;
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * (n + 10));
	memset(dp, 0xcf, sizeof dp);
	for (int i = 1; i <= n; ++ i) rd(w[i]);
	for (int i = 1, a, b; i < n; ++ i) {
		rd(a), rd(b), add(a, b), add(b, a);
		dg[a] ++, dg[b] ++;
	}
	dfs(1, 0);
	return cout << dp[1][0] << '\n', 0;
}
