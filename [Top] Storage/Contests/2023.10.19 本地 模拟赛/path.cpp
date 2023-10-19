#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PLI = pair<LL, int>;
const int N = 5e4 + 10;
const int M = 3e5 + 10;
int n, q, t, head[N], idx;
struct Node { int nxt, to, w; }edge[M];
priority_queue<PLI, vector<PLI>, greater<PLI>> heap;
int stk[N], top;
LL dis[N];
bool st[N];

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

void djikstra() {
	while (heap.size()) heap.pop();
	memset(st, 0, sizeof(bool) * (n + 10));
	memset(dis, 0x3f, sizeof(LL) * (n + 10));
	dis[1] = 0, heap.push({0, 1});
	while (heap.size()) {
		int u = heap.top().second; heap.pop();
		if (st[u]) continue;
		st[u] = true;
		for (int i = head[u], v; ~i; i = edge[i].nxt) {
			v = edge[i].to;
			if (dis[v] > dis[u] + edge[i].w) {
				dis[v] = dis[u] + edge[i].w;
				heap.push({dis[v], v});
			}
		}
	}
}

int main() {
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q >> t;
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b, c; i <= q; ++ i) {
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c), djikstra();
		if (dis[n] <= t) {
			memset(head, -1, sizeof(int) * (n + 10));
			stk[++ top] = i, idx = 0;
		}
	}
	cout << top << '\n';
	for (int i = 1; i <= top; ++ i) cout << stk[i] << ' ';
	return cout << '\n', 0;
}
