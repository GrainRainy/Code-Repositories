#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 40 + 10;
const int M = 2e6 + 10;
LL n, m, w[N], res[M], top, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> w[i];
	for (int s = 0; s < 1 << (n >> 1); ++ s) {
		LL sm = 0;
		for (int i = 1; i <= n >> 1; ++ i)
			if ((s >> i - 1) & 1) sm += w[i];
		if (sm > m) continue;
		res[++ top] = sm;
	}
	sort(res + 1, res + top + 1);
	for (int s = 0; s < 1 << (n - (n >> 1)); ++ s) {
		LL sm = 0;
		for (int i = 1; i <= n - (n >> 1); ++ i)
			if ((s >> i - 1) & 1) sm += w[(n >> 1) + i];
		ans += upper_bound(res + 1, res + top + 1, m - sm) - res - 1;
	}
	return cout << ans << '\n', 0;
}
