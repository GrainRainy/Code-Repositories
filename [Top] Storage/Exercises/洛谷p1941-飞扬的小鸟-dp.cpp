#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar()) ;
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
}

using IO::rd;
using namespace std;
const int N = 1e4 + 10;
const int M = 1e3 + 10;
const int INF = 0x3f3f3f3f;
int n, m, k, x[N], y[N];
int pos = 1;
struct Pipes { 
	int p, u, d;
	bool operator < (const Pipes &t) const { return p < t.p; }
}p[N];
int dp[2][M << 1], ans;

inline void upd(int &x, int y) { (x > y) and (x = y); }
int main() {
	rd(n), rd(m), rd(k);
	for (int i = 1; i <= n; ++ i) rd(x[i]), rd(y[i]);
	for (int i = 1; i <= k; ++ i) rd(p[i].p), rd(p[i].d), rd(p[i].u);
	sort(p + 1, p + k + 1);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j <= m + x[i]; ++ j) dp[i & 1][j] = INF;
		for (int j = x[i] + 1; j <= m + x[i]; ++ j)
			dp[i & 1][j] = min(dp[i & 1][j - x[i]], dp[i - 1 & 1][j - x[i]]) + 1;
		for (int j = m + 1; j <= m + x[i]; ++ j) upd(dp[i & 1][m], dp[i & 1][j]);
		for (int j = 1; j <= m - y[i]; ++ j) upd(dp[i & 1][j], dp[i - 1 & 1][j + y[i]]);
		if (i == p[pos].p) {
			for (int j = 1; j <= p[pos].d; ++ j) dp[i & 1][j] = INF;
			for (int j = p[pos].u; j <= m; ++ j) dp[i & 1][j] = INF;
			ans = INF;
			for (int j = p[pos].d + 1; j < p[pos].u; ++ j) upd(ans, dp[i & 1][j]);
			if (ans == INF) return printf("%d\n%d\n", 0, pos - 1), 0;
			pos ++;			
		}
	}
	ans = INF;
	for (int i = 1; i <= m; ++ i) upd(ans, dp[n & 1][i]);
	return printf("%d\n%d\n", 1, ans), 0;
}
