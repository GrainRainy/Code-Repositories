#include <bits/stdc++.h>
#define fi first
#define se second
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
using PLL = pair<long long, long long>;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());
const int N = 1e5 + 10;
LL c, subt, n, m, k, d;
double lim = 1.8;
struct Range {
	bool st;
	LL l, r, v;
	bool operator < (const Range &t) const { return r < t.r; }
}p[N];
PLL stk[N];
LL tp, ans;

namespace subb {
	void solve() {
		ans = 0;
		for (int i = 1; i <= m; ++ i)
			if (p[i].st) ans += -(p[i].r - p[i].l + 1) * d + p[i].v;
		return cout << ans << '\n', void();
	}
}

LL calc() {
	LL res = 0; tp = 0;
	for (int i = 1; i <= m; ++ i)
		if (p[i].st) res += p[i].v, stk[++ tp] = {p[i].l, p[i].r};
	sort(stk + 1, stk + tp + 1);
	LL l = 0, r = -1, len = 0;
	for (int i = 1; i <= tp; ++ i) {
		if (stk[i].fi > r) len += r - l + 1, r = stk[i].se, l = stk[i].fi;
		else r = stk[i].se;
		if (r - l + 1 > k) return -1e10;
	}
	len += r - l + 1, ans = max(ans, res - len * d);
	return res - len * d;
}

void simulate() {
	for (double t = 1e5; t >= 1e-8; t *= 0.98) {
		LL ori = calc();
		int pos = mt() % m + 1;
		p[pos].st ^= 1;
		LL nw = calc();
		if (nw == -1e10) continue;
		LL delta = nw - ori;
		if (exp(-delta / t) > (double)mt() / mt19937::max()) 
			p[pos].st ^= 1;
	}
}

namespace sub1 {
	void solve() {
		int sm[N];
		for (int s = 1; s <= 1 << n; ++ s) {
			long long res = 0;
			for (int i = 1; i <= n; ++ i) sm[i] = 0;
			for (int i = 1; i <= n; ++ i)
				sm[i] = (s >> i - 1) & 1;
			bool b = true;
			for (int i = 1; i <= n; ++ i) {
				sm[i] += sm[i - 1];
				if (i > k and sm[i] - sm[i - k] == k)
					b = false;
			}
			if (!b) continue;
			for (int i = 1; i <= m; ++ i) {
				if (sm[p[i].r] - sm[p[i].l - 1] == p[i].r - p[i].l + 1)
					res += p[i].v;
			}
			ans = max(ans, res - sm[n] * d);
		}
		return cout << ans << '\n', void();
	}
}

void solve() {
	double subst = clock();
	cin >> n >> m >> k >> d, ans = 0;
	for (int i = 1; i <= m; ++ i) {
		cin >> p[i].r >> p[i].l >> p[i].v;
		p[i].l = p[i].r - p[i].l + 1;
		p[i].st = (p[i].r - p[i].l + 1) <= k and (p[i].r - p[i].l + 1) * d <= p[i].v;
	}
	if (c <= 2) return sub1::solve();
	if (c == 17 or c == 18) return subb::solve();
	while (true) {
		double st = clock();
		simulate();
		double len = clock() - st;
		if (clock() - subst + len > CLOCKS_PER_SEC * lim) break;
	}
	return cout << ans << '\n', void();
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> subt, lim /= subt;
	while (subt --) solve();
	return 0;
}
