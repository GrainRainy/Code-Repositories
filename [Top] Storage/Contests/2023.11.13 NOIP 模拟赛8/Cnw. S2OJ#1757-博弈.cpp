#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 5e5 + 10;
const int base = 13331;
int n, head[N], etp = -1, stk[N], stp;
struct Node { int nxt, to; ULL w; }edge[N << 1];
ULL pw[N] = {1}, ptp = 1, dis[N];
map<ULL, int> mp;
LL ans;

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
	mp[dis[u]] ++;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == fa) continue;
		dis[v] = dis[u] ^ edge[i].w;
		dfs(v, u);
	}
}

void solve() {
	rd(n), ans = stp = 0, etp = -1, mp.clear();
	memset(head, -1, sizeof(int) * (n + 10));
	memset(dis, 0, sizeof(int) * (n + 10));
	for (int i = 1, u, v, w; i < n; ++ i) {
		rd(u), rd(v), rd(w), stk[++ stp] = w;
		add(u, v, w), add(v, u, w);
	}
	while (ptp <= n) pw[ptp] = pw[ptp - 1] * base, ptp ++;
	sort(stk + 1, stk + stp + 1);
	stp = unique(stk + 1, stk + stp + 1) - stk - 1;
	for (int i = 0; i <= etp; i += 2) 
		edge[i].w = edge[i ^ 1].w = pw[lower_bound(stk + 1, stk + stp + 1, edge[i].w) - stk];
	dfs(1, 0);
	for (auto t : mp) ans += (LL)t.second * (t.second - 1) / 2;
	return cout << (LL)n * (n - 1) / 2 - ans << '\n', void();
}

int main() {
	int t; rd(t);
	while (t --) solve();
	return 0;
}
