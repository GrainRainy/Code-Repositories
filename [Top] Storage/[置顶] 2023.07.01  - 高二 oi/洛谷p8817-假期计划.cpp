#include <bits/stdc++.h>
#define fi first
#define se second 
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using IO::input;
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int N = 2.5e3 + 10;
const int M = 1e4 + 10;
int n, m, k;
int head[N], idx;
struct Node { int nxt, to; }edge[M << 1];
bitset<N> av[N];
int f[N][5];
LL w[N], ans;
int dist[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

inline void update(int f[], LL u) {
	if (w[u] >= w[f[1]]) f[3] = f[2], f[2] = f[1], f[1] = u;
	else if (w[u] >= w[f[2]]) f[3] = f[2], f[2] = u;
	else if (w[u] > w[f[3]]) f[3] = u;
	return;
}

void bfs(int st) {
	memset(dist, -1, sizeof(int) * (n + 10));
	queue<int> q;
	q.push(st); dist[st] = 0;
	while (q.size()) {
		auto u = q.front(); q.pop();
		if (u != st) av[st][u] = true;
		if (u != st and av[1][u]) update(f[st], u);
		if (dist[u] == k + 1) continue;
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (!(~dist[j])) dist[j] = dist[u] + 1, q.push(j);
		}
	}
}

int main() {
	input(n), input(m), input(k);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 2; i <= n; ++ i) input(w[i]);
	for (int i = 1, x, y; i <= m; ++ i) {
		input(x), input(y);
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= n; ++ i) bfs(i);
	for (int i = 2; i <= n; ++ i) {
		for (int j = 2; j <= n; ++ j) {
			if (i == j or !av[i][j]) continue;
			for (int a = 1; a <= 3 and f[i][a]; ++ a) 
				for (int b = 1; b <= 3 and f[j][b]; ++ b) 
					if (f[i][a] != f[j][b] and i != f[j][b] and j != f[i][a]) 
						ans = max(ans, w[i] + w[j] + w[f[i][a]] + w[f[j][b]]);
		}
	}
	return printf("%lld\n", ans), 0;
}
