#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 50 + 5;
const int INF = 0x3f3f3f3f;
int n, sa, sb, ta, tb, la, lb, s, t;
bool ans;
char str[N];
struct NODE {
	int head[N], now[N], idx = 1;
	struct Node { int nxt, to, w; }edge[N * N << 1];
	inline void add(int a, int b, int w) {
		edge[++ idx].nxt = head[a];
		edge[idx].w = w;
		edge[head[a] = idx].to = b;
	}
}nw, save;
int dis[N];

bool bfs() {
	for (int i = 1; i <= n + 2; ++ i) dis[i] = INF;
	dis[s] = 0, nw.now[s] = nw.head[s];
	queue<int> q; q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = nw.head[u], j; ~i; i = nw.edge[i].nxt) {
			j = nw.edge[i].to;
			if (nw.edge[i].w and dis[j] == INF) {
				dis[j] = dis[u] + 1, q.push(j), nw.now[j] = nw.head[j];
				if (j == t) return true;
			}
		}
	}
	return false;
}

int dfs(int u, int limit) {
	if (u == t) return limit;
	int res = limit, tmp;
	for (int i = nw.now[u], j; ~i and res; i = nw.edge[i].nxt) {
		nw.now[u] = i, j = nw.edge[i].to;
		if (nw.edge[i].w and dis[j] == dis[u] + 1) {
			tmp = dfs(j, min(res, nw.edge[i].w));
			if (!tmp) dis[j] = INF;
			nw.edge[i].w -= tmp;
			nw.edge[i ^ 1].w += tmp;
			res -= tmp;
		}
	}
	return limit - res;
}

int dinic() {
	int res = 0;
	while (bfs()) res += dfs(s, INF);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (cin >> n >> sa >> ta >> la >> sb >> tb >> lb) {
		ans = true; save.idx = 1;
		memset(save.head, -1, sizeof(int) * (n + 10));
		sa ++, sb ++, ta ++, tb ++, s = n + 1, t = n + 2;
		for (int i = 1; i <= n; ++ i) {
			cin >> str + 1;
			for (int j = 1; j <= n; ++ j) {
				if (str[j] == 'N') save.add(i, j, INF), save.add(j, i, 0);
				if (str[j] == 'O') save.add(i, j, 1), save.add(j, i, 0);
			}
		}
		save.add(s, sa, la), save.add(sa, s, 0), save.add(ta, t, la), save.add(t, ta, 0);
		nw = save;
		nw.add(s, sb, lb), nw.add(sb, s, 0), nw.add(tb, t, lb), nw.add(t, tb, 0);
		ans &= dinic() == la + lb;
		nw = save;
		nw.add(s, tb, lb), nw.add(tb, s, 0), nw.add(sb, t, lb), nw.add(t, sb, 0);
		ans &= dinic() == la + lb;
		ans ? cout << "Yes\n" : cout << "No\n";
	}
	return 0;
}
