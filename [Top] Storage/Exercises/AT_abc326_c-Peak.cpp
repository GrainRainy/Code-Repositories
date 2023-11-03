#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m, a[N], q[N], hd = 1, tl, ans;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) {
		while (hd <= tl and q[hd] < a[i] - m + 1) hd ++;
		q[++ tl] = a[i], ans = max(ans, tl - hd + 1);
	}
	return cout << ans << '\n', 0;
}
