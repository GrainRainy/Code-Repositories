#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 3e5 + 10;
LL n, m, t, dt, ans[N];
char c;
struct Ant {
	LL p, d, id;
	bool operator < (const Ant &t) const { return p < t.p; }
}ori[N], nw[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; ++ i) {
		cin >> ori[i].p >> c, ori[i].id = i;
		if (c == 'L') {
			ori[i].d = nw[i].d = -1;
			nw[i].p = ((ori[i].p - t) % m + m - 1) % m + 1;
			dt = ((dt - (t + m - ori[i].p) / m) % n + n - 1) % n + 1;
		} else {
			ori[i].d = nw[i].d = 1;
			nw[i].p = (ori[i].p + t - 1) % m + 1;
			dt = (dt + (t + ori[i].p - 1) / m) % n;
		}
	}
	sort(ori + 1, ori + n + 1), sort(nw + 1, nw + n + 1);
	for (int i = 1; i <= n; ++ i) ans[ori[i].id] = nw[(i + dt - 1) % n + 1].p;
	for (int i = 1; i <= n; ++ i) cout << ans[i] << ' ';
	return cout << '\n', 0;
}
