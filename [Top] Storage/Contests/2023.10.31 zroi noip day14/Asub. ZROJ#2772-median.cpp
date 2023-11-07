#include <bits/stdc++.h>
#define fi first
#define se second
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int MOD = 998244353;
int n, ary[7][N], ans;
vector<int> rs[7];
vector<pair<int, int>> tmp;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void upd(int &x, const int &y) { if ((x += y) >= MOD) x -= MOD; }
int dfs(int pos, int lim, int mn, int mx, int cn, int cx) {
	if (pos == 4) {
		if (lim or cn or cx) return 0;
//		cout << mn << ' ' << mx << ' ' << cn << ' ' << cx << '\n';
		return (LL)mn * mx;
	}
	int res = 0;
	if (lim) upd(res, dfs(pos + 1, lim - 1, mn, mx, cn, cx));
	if (cn) upd(res, dfs(pos + 1, lim, (LL)mn * tmp[pos].fi % MOD, mx, cn - 1, cx));
	if (cx) upd(res, dfs(pos + 1, lim, mn, (LL)mx * tmp[pos].se % MOD, cn, cx - 1));
	return res;
}

namespace sub1 {
	int mid(int a, int b, int c, int d, int e) {
		vector<int> res;
		res.emplace_back(a), res.emplace_back(b), res.emplace_back(c);
		res.emplace_back(d), res.emplace_back(e);
		sort(res.begin(), res.end());
		return res[2];
	}
	void solve() {
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				for (int k = 1; k <= n; ++ k)
					for (int l = 1; l <= n; ++ l)
						for (int m = 1; m <= n; ++ m)
							upd(ans, mid(ary[1][i], ary[2][j], ary[3][k], ary[4][l], ary[5][m])); 
		cout << ans << '\n';
	}
}

int main() {
	rd(n);
	for (int i = 1; i <= 5; ++ i)
		for (int j = 1; j <= n; ++ j)
			rd(ary[i][j]), rs[i].emplace_back(ary[i][j]);
	if (n <= 100) return sub1::solve(), 0;
	for (int i = 1; i <= 5; ++ i) sort(rs[i].begin(), rs[i].end());
	for (int i = 1; i <= 5; ++ i)
//	for (int i = 1; i <= 1; ++ i)
		for (int j = 1, c; j <= n; ++ j) {
//		for (int j = 2, c; j <= 2; ++ j) {
			tmp.clear(), c = 0;
			for (int k = 1; k <= 5; ++ k) {
				if (k == i) continue;
				auto itl = lower_bound(rs[k].begin(), rs[k].end(), ary[i][j]);
				auto itr = upper_bound(rs[k].begin(), rs[k].end(), ary[i][j]);
				c += itl != itr;
				tmp.push_back({itl - rs[k].begin(), rs[k].end() - itr});
			}
			for (int a = 0; a <= c; ++ a) {
				for (int b = 0; b + c < 5 and b <= 2; ++ b) {
//					LL tmpans = dfs(0, a, 1, 1, b, 4 - b - a);
//					cout << a << ' ' << tmpans << '\n';
//					upd(ans, (LL)tmpans * ary[i][j] % MOD);
					upd(ans, (LL)dfs(0, a, 1, 1, b, 4 - b - a) * ary[i][j] % MOD);
				}
			}
		}
	return cout << ans << '\n', 0;
}
