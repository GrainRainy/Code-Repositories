#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e3 + 10;
const double eps = 1e-11;
int n, mid = 1, l, r;
struct Dot { long double x, y, id; }a[N];
struct Sit { int l, r, p; }pre[N][N][2], nw;
long double dp[N][N][2], ans = 1e10;
int stk[N], top;

inline int ex(int x) { return x > n ? x - n : x < 0 ? x + n : x; }
inline long double dis(int i, int j) {
	return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
}

int main() {
//	freopen("tree3.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) 
		cin >> a[i].x >> a[i].y, a[i].id = i;
	for (int i = 1; i <= n; ++ i) if (a[i].y > a[mid].y) mid = i;
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < n; ++ j)
			dp[i][j][0] = dp[i][j][1] = 1e10;
	dp[0][0][0] = dp[0][0][1] = 0;
	for (int len = 1; len < n; ++ len)
		for (int l = 0, r; l <= len; ++ l) {
			r = len - l;
			if (l and dp[l - 1][r][0] + dis(ex(mid + l), ex(mid + l - 1)) < dp[l][r][0])
				dp[l][r][0] = dp[l - 1][r][0] + dis(ex(mid + l), ex(mid + l - 1)), pre[l][r][0] = {l - 1, r, 0};
			if (l and dp[l - 1][r][1] + dis(ex(mid - r), ex(mid + l)) < dp[l][r][0])
				dp[l][r][0] = dp[l - 1][r][1] + dis(ex(mid - r), ex(mid + l)), pre[l][r][0] = {l - 1, r, 1};
			if (r and dp[l][r - 1][0] + dis(ex(mid + l), ex(mid - r)) < dp[l][r][1])
				dp[l][r][1] = dp[l][r - 1][0] + dis(ex(mid + l), ex(mid - r)), pre[l][r][1] = {l, r - 1, 0};
			if (r and dp[l][r - 1][1] + dis(ex(mid - r + 1), ex(mid - r)) < dp[l][r][1])
				dp[l][r][1] = dp[l][r - 1][1] + dis(ex(mid - r + 1), ex(mid - r)), pre[l][r][1] = {l, r - 1, 1};
		}
	for (int i = 0; i < n; ++ i) {
		if (dp[i][n - i - 1][0] < ans) ans = dp[i][n - i - 1][0], nw = {i, n - i - 1, 0};
		if (dp[i][n - i - 1][1] < ans) ans = dp[i][n - i - 1][1], nw = {i, n - i - 1, 1};
	}
	while (nw.l or nw.r) {
		stk[++ top] = nw.p ? ex(mid - nw.r) : ex(mid + nw.l);
		nw = pre[nw.l][nw.r][nw.p];
	}
	cout << mid << ' ';
	while (top) cout << stk[top --] << ' ';
	return cout << '\n', 0;
}
