#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n, d[N], dg[N];
struct Edge { int a, b, w; }sv[N];
int ans;

bool check(int s) {
	memset(dg, 0, sizeof(int) * (n + 10));
	for (int i = 1; i < n; ++ i) {
		if ((s >> i - 1) & 1) dg[sv[i].a] ++, dg[sv[i].b] ++;
	}
	for (int i = 1; i <= n; ++ i)
		if (dg[i] > d[i]) return false;
	return true;
}

signed main() {
//	freopen("c.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> d[i];
	for (int i = 1; i < n; ++ i)
		cin >> sv[i].a >> sv[i].b >> sv[i].w;
	for (int s = 1; s < (1 << n - 1); ++ s)
		if (check(s)) {
			int res = 0;
			for (int i = 1; i < n; ++ i)
				if ((s >> i - 1) & 1) res += sv[i].w;
			ans = max(ans, res);
		}
	cout << ans << '\n';
	return 0;
}
