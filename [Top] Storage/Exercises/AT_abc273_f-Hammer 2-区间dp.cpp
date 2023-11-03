#include <bits/stdc++.h>
#define fi first
#define se second
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 1.5e3 + 10;
int n, x, st, ed, ky[N], tp;
pair<int, int> rg[N << 1];
LL f[N << 1][N << 1][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> x;
	for (int i = 1, p; i <= n; ++ i) cin >> p, rg[++ tp] = {p, i};
	for (int i = 1; i <= n; ++ i) cin >> ky[i], rg[++ tp] = {ky[i], 0};
	rg[++ tp] = {0, 0}, rg[++ tp] = {x, 0}, sort(rg + 1, rg + tp + 1);
	for (int i = 1; i <= tp; ++ i) {
		!rg[i].fi ? st = i : rg[i].fi == x ? ed = i : 0;
		if (st and ed) break;
	}
	memset(f, 0x3f, sizeof f), f[st][st][0] = f[st][st][1] = 0;
	for (int len = 1; len <= tp; ++ len)
		for (int l = 1, r; l <= tp - len + 1; ++ l) {
			r = l + len - 1;
			if (l > 1 and (!rg[l - 1].se or ky[rg[l - 1].se] >= rg[l].fi and ky[rg[l - 1].se] <= rg[r].fi))
				f[l - 1][r][0] = min({f[l - 1][r][0], f[l][r][0] + rg[l].fi - rg[l - 1].fi, f[l][r][1] + rg[r].fi - rg[l - 1].fi});
			if (r < tp and (!rg[r + 1].se or ky[rg[r + 1].se] >= rg[l].fi and ky[rg[r + 1].se] <= rg[r].fi))
				f[l][r + 1][1] = min({f[l][r + 1][1], f[l][r][0] + rg[r + 1].fi - rg[l].fi, f[l][r][1] + rg[r + 1].fi - rg[r].fi});
		}
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for (int l = 1; l <= ed; ++ l)
		for (int r = ed; r <= tp; ++ r)
			ans = min({ans, f[l][r][0], f[l][r][1]});
	return cout << (ans == 0x3f3f3f3f3f3f3f3f ? -1 : ans) << '\n', 0;
}
