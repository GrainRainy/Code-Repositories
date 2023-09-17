#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, x[N], e[N], head[N], idx, ans;
struct Node { int nxt, to; }edge[N * N];
int dfn[N], low[N], stk[N], top, id[N], stamp, tmp, cnt_scc;
bool st[N], mg[N][N], dg[N];

namespace sub1 {
	bool f = true;
	unordered_map<int, bool> mp;
	void solve() {
		for (int i = 1; i <= n; ++ i) mp[x[i]] = true;
		cout << mp.size() << '\n';
	}
}

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void tarjan(int u) {
	stk[++ top] = u, st[u] = true;
	dfn[u] = ++ stamp, low[u] = dfn[u];
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (!dfn[j]) tarjan(j), low[u] = min(low[u], low[j]);
		else if (st[j]) low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u]) {
		cnt_scc ++;
		do {
			tmp = stk[top --], st[tmp] = false;
			id[tmp] = cnt_scc;
		} while (tmp != u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	memset(head, -1, sizeof head);
	for (int i = 1; i <= n; ++ i) {
		cin >> x[i] >> e[i];
		sub1::f &= (e[i] == e[1]);
	}
	if (sub1::f) return sub1::solve(), 0;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			if (abs(x[i] - x[j]) <= e[i] - e[j] and i != j) add(i, j);
	for (int i = 1; i <= n; ++ i) if (!dfn[i]) tarjan(i);
	for (int u = 1; u <= n; ++ u)
		for (int i = head[u], j; ~i; i = edge[i].nxt)
			if (!mg[id[u]][id[j = edge[i].to]]) 
				mg[id[u]][j] = dg[id[j]] = true;
	for (int i = 1; i <= cnt_scc; ++ i) if (!dg[i]) ans ++;
	return cout << ans << '\n', 0;
}
