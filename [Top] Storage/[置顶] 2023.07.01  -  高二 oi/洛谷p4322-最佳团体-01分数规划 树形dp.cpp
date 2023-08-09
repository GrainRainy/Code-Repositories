#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
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
const int N = 2.5e3 + 10;
const double eps = 1e-4;
const double INF = 1e9;
int k, n, s[N], p[N], siz[N];
int head[N], idx;
struct Node { int nxt, to; }edge[N];
double l = 0, r, mid, dp[N][N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u) {
	siz[u] = 1;
	dp[u][1] = p[u] - s[u] * mid;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		dfs(j);
		siz[u] += siz[j];
		for (int a = min(siz[u], k + 1); a; -- a) 
			for (int b = 1; b < a and b <= siz[j]; ++ b)
				dp[u][a] = max(dp[u][a], dp[u][a - b] + dp[j][b]);
	}
}

int main() {
	input(k), input(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, fa; i <= n; ++ i) {
		input(s[i]), input(p[i]), input(fa);
		add(fa, i);
		r += s[i];
	}
	while (r - l > eps) {
		mid = (l + r) / 2;
		for (int i = 0; i <= n; ++ i)
			for (int j = 1; j <= k + 1; ++ j)
				dp[i][j] = -INF;
		dfs(0);
		if (dp[0][k + 1] - 0 > eps) l = mid;
		else r = mid;
	}
	return printf("%.3lf", l), 0;
}
