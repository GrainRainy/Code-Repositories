#include <bits/stdc++.h>
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
const int N = 1e2 + 10;
const int M = 5e2 + 10;
const int K = 12;
const int INF = 0x3f3f3f3f;
int n, m, k;
int head[N], idx;
struct Node { int nxt, to, w; }edge[M << 1];
int dp[1 << K][N];
bool st[N];

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

void spfa(int s) {
	queue<int> q;
	for (int i = 1; i <= n; ++ i) if (dp[s][i] != INF) q.push(i), st[i] = true;
	while (q.size()) {
		int u = q.front();
		q.pop(), st[u] = false;
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (dp[s][u] + edge[i].w < dp[s][j]) {
				dp[s][j] = dp[s][u] + edge[i].w;
				if (!st[j]) q.push(j), st[j] = true;
			}
		}
	}
}

int main() {
	input(n), input(m), input(k);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, u, v, w; i <= m; ++ i) {
		input(u), input(v), input(w);
		add(u, v, w), add(v, u, w);
	}
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1, x; i <= k; ++ i) input(x), dp[(1 << i - 1)][x] = 0;
	for (int s = 1; s < (1 << k); ++ s) {
		for (int t = (s - 1) & s; t; t = (t - 1) & s) {
			if (t < (s ^ t)) break;
			for (int i = 1; i <= n; ++ i) 
				dp[s][i] = min(dp[s][i], dp[t][i] + dp[s ^ t][i]);
		}
		spfa(s);
	}
	printf("%d\n", *min_element(dp[(1 << k) - 1] + 1, dp[(1 << k) - 1] + n + 1));
	return 0;
}
