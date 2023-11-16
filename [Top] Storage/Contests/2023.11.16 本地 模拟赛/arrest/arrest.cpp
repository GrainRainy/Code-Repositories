#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 3e2 + 10;
int n, m, k;
LL w[N][N], dis[N][N], c[N];
double kl[N][N], ans;

double dfs(int u, double p, LL sm) {
	int dg = 0; double res = p * kl[u][c[u]];
	for (int i = 1; i <= n; ++ i)
		if (sm + w[u][i] == dis[1][i]) dg ++;
	for (int i = 1; i <= n; ++ i)
		if (sm + w[u][i] == dis[1][i])
			res += dfs(i, (1 - kl[u][c[u]]) * p / dg, sm + w[u][i]);
	return res;
}

void cat(int pos, int sm) {
	if (pos == n) return c[n] = k - sm, ans = max(ans, dfs(1, 1, 0)), void();
	for (int i = 0; i + sm <= k; ++ i) c[pos] = i, cat(pos + 1, sm + i);
}

int main() {
	freopen("arrest.in", "r", stdin);
	freopen("arrest.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	memset(w, 0x3f, sizeof w), memset(dis, 0x3f, sizeof dis);
	for (int i = 1, a, b, c; i <= m; ++ i) {
		cin >> a >> b >> c;
		dis[a][b] = dis[b][a] = w[a][b] = w[b][a] = min(w[a][b], (LL)c);
	}
	for (int i = 1; i <= n; ++ i) {
		dis[i][i] = 0;
		for (int j = 1; j <= k; ++ j) cin >> kl[i][j];
	}
	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	cat(1, 0);
	return printf("%.6lf\n", ans), 0;
}
