#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
int n, a, b, v[N], mxv;
LL ans[N];

namespace sub1 {
	void solve() {
		LL cl, cu, sl, su;
		for (int i = 1; i <= n; ++ i) {
			cl = cu = sl = su = 0;
			for (int j = 1; j <= n; ++ j) {
				if (v[j] < v[i]) cl ++, sl += v[j];
				if (v[j] > v[i]) cu ++, su += v[j];
				ans[j] = min(ans[j], (cl * v[i] - sl) * a + (su - cu * v[i]) * b);
			}
		}
	}
}

namespace sub2 {
	void solve() {
		LL cl, cu, sl, su;
		for (int i = 1; i <= mxv; ++ i) {
			cl = cu = sl = su = 0;
			for (int j = 1; j <= n; ++ j) {
				if (v[j] < i) cl ++, sl += v[j];
				if (v[j] > i) cu ++, su += v[j];
				ans[j] = min(ans[j], (cl * i - sl) * a + (su - cu * i) * b);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++ i) {
		cin >> v[i];
		mxv = max(mxv, v[i]);
		ans[i] = 0x3f3f3f3f3f3f3f3f;
	}
	if (mxv <= 100) sub2::solve();
	else sub1::solve();
	for (int i = 1; i <= n; ++ i) cout << ans[i] << '\n';
	return 0;
}
