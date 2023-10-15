#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 3e5 + 10;
int n, d[N], head[N], idx;
struct Node { int nxt, to; LL w; }edge[N << 1];
LL f[N][2], ans;
bool vis[N];

inline void add(int a, int b, LL w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void dp(int u, int fa) {
	vis[u] = true;
	if (!d[u]) return;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == fa) f[u][1] += edge[i].w;
		else {
			dp(v, u);
			f[u][0] += f[v][0], f[u][1] += f[v][0];
			if (q.size() < d[u]) q.push(f[v][1] - f[v][0]);
			else if (q.size() and q.top() < f[v][1] - f[v][0]) {
				q.pop();
				q.push(f[v][1] - f[v][0]);
			}
		}
	}
	while (q.size() and q.top() < 0) q.pop();
	if (q.size() and q.size() == d[u]) f[u][0] += q.top(), q.pop();
	while (q.size()) f[u][0] += q.top(), f[u][1] += q.top(), q.pop();
}

int main() {
//	freopen("c.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) head[i] = -1, cin >> d[i];
	for (int i = 1, a, b, w; i < n; ++ i) {
		cin >> a >> b >> w;
		if (w > 0) add(a, b, w), add(b, a, w);
	}
	for (int i = 1; i <= n; ++ i) 
		if (!vis[i]) dp(i, 0), ans += f[i][0];
	return cout << ans << '\n', 0;
}
