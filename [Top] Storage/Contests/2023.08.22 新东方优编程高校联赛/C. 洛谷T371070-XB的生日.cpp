#include <bits/stdc++.h>
using namespace std;
const int N = 25 + 5;
const int M = 5e2 + 10;
const int T = 1e5 + 10;
const int MOD = 5557;
int n, m, t;
string s;
int head[N], idx;
struct Node { int nxt, to, w; }edge[M];
int dp[T][N][1 << 4];

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

inline void upd(int &x, int y) { x += y; (x >= MOD) and (x -= MOD); }

int hsh(string s) {
	int res = 0;
	for (auto c : s) {
		if (c == 'B') res |= 1 << 3;
		if (c == 'J') res |= 1 << 2;
		if (c == 'M') res |= 1 << 1;
		if (c == 'P') res |= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(head, -1, sizeof head);
	for (int i = 1, u, v; i <= m; ++ i)
		cin >> u >> v >> s, add(u, v, hsh(s));
	cin >> t;
	dp[0][1][0] = 1;
	for (int i = 0; i <= t; ++ i)
		for (int j = 1; j <= n; ++ j)
			for (int s = 0; s < 1 << 4; ++ s)
				for (int a = head[j], b; ~a; a = edge[a].nxt) {
					b = edge[a].to;
					upd(dp[i + 1][b][s], dp[i][j][s]);
					upd(dp[i + 2][b][s | edge[a].w], dp[i][j][s]);
				}
	int res = 0;
	for (int i = 1; i <= t; ++ i)
		upd(res, dp[i][1][15]);
	cout << res << endl;
	return 0;
}
