#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, head[N], etp, stk[N], tp;
struct Node { int nxt, to, w; }edge[N << 1];
long long c, ans;
bool t[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b, int w) {
	edge[++ etp] = {head[a], b, w};
	head[a] = etp;
}

void dfs(int u, int fa) {
	if (fa and !c) ans ++;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == fa) continue;
		if (t[edge[i].w] ^= 1) c ++;
		else c --;
		dfs(v, u);
		if (t[edge[i].w] ^= 1) c ++;
		else c --;
	}
}

void solve() {
	rd(n), ans = tp = etp = 0;
	memset(t, 0, sizeof(bool) * (n + 10));
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, u, v, w; i < n; ++ i) {
		rd(u), rd(v), rd(w), stk[++ tp] = w;
		add(u, v, w), add(v, u, w);
	}
	sort(stk + 1, stk + tp + 1);
	tp = unique(stk + 1, stk + tp + 1) - stk - 1;
	for (int i = 1; i <= etp; ++ i)
		edge[i].w = lower_bound(stk + 1, stk + tp + 1, edge[i].w) - stk;
	for (int i = 1; i <= n; ++ i) dfs(i, 0);
	return cout << (long long)n * (n - 1) / 2 - ans / 2 << '\n', void();
}

int main() {
	int t; rd(t);
	while (t --) solve();
	return 0;
}
