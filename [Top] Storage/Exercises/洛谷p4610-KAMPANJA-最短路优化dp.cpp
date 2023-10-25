#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 10;
int n, m, dis[N][N], dp[N][N];
struct Node {
	int a, b, v;
	bool operator > (const Node &t) const { return v > t.v; }
};
bool st[N][N];

void djikstra() {
	priority_queue<Node, vector<Node>, greater<Node>> q;
	memset(dp, 0x3f, sizeof dp);
	dp[1][1] = 1, q.push({1, 1, 1});
	while (q.size()) {
		int a = q.top().a, b = q.top().b; q.pop();
		if (st[a][b]) continue;
		st[a][b] = true;
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j) {
				if (i == a and j == b) continue;
				if (dp[i][j] > dp[a][b] + dis[b][i] + dis[i][j] + dis[j][a] - 1) {
					dp[i][j] = dp[a][b] + dis[b][i] + dis[i][j] + dis[j][a] - 1;
					q.push({i, j, dp[i][j]});
				}
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) 
		for (int j = 1; j <= n; ++ j)
			dis[i][j] = i == j ? 0 : 1e4 + 10;
	for (int i = 1, a, b; i <= m; ++ i)
		cin >> a >> b, dis[a][b] = 1;
	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	djikstra();
	return cout << dp[2][2] << '\n', 0;
}
