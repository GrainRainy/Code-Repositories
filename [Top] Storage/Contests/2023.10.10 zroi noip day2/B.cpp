#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PLI = pair<LL, int>;
const int N = 2e3 + 10;
bool Mst;
int n, m, head[N * N], idx;
struct Node { int nxt, to; LL w; }edge[N * N];
priority_queue<PLI, vector<PLI>, greater<PLI>> q;
LL dis[N * N];
bool st[N * N];
bool Med;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b, LL w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void djikstra() {
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0, q.push({0, 1});
	while (q.size()) {
		int u = q.top().second; q.pop();
		if (st[u]) continue;
		st[u] = true;
		for (int i = head[u], v; ~i; i = edge[i].nxt) {
			if (dis[v = edge[i].to] > max(dis[u], edge[i].w)) {
				dis[v] = max(dis[u], edge[i].w);
				q.push({dis[v], v});
			}
		}
	}
}

int main() {
//	cerr << fabs(&Med - &Mst) / 1048576 << '\n';
//	freopen("ex_b4.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	rd(n), rd(m);
	memset(head, -1, sizeof head);
	for (int i = 1, a, b, w; i <= m; ++ i) {
		rd(a), rd(b), rd(w);
		for (int j = 0; j < m - 1; ++ j)
			add(j * n + a, (j + 1) * n + b, (LL)w * (j + 1));
	}
	djikstra();
	LL res = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= m; ++ i) res = min(res, dis[i * n]);
	return cout << res << '\n', 0;
}
