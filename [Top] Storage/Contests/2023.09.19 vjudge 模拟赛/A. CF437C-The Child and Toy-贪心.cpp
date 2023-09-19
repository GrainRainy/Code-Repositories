#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e3 + 10;
int n, m, head[N], idx, ans;
int v[N], c[N], id[N];
struct Node { int nxt, to; }edge[N << 2];
bool del[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

inline bool cmp(const int &x, const int &y) {
	if (v[x] ^ v[y]) return v[x] > v[y];
	return c[x] < c[y];
}

int main() {
	cin >> n >> m;
	memset(head, -1, sizeof head);
	for (int i = 1; i <= n; ++ i) 
		cin >> v[i], id[i] = i;
	for (int i = 1, a, b; i <= m; ++ i) {
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	for (int u = 1; u <= n; ++ u)
		for (int i = head[u], j; ~i; i = edge[i].nxt)
			c[edge[i].to] += v[u];
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; ++ i) {
		ans += c[id[i]];
		for (int j = head[id[i]]; ~j; j = edge[j].nxt)
			c[edge[j].to] -= v[id[i]];
	}
	return cout << ans << '\n', 0;
}
