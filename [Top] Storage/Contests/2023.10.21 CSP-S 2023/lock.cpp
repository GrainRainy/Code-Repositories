#include <bits/stdc++.h>
using namespace std;
const int N = 10 + 5;
int n, a[N][N], m[N], c, ans;
bool st[N];

int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	if (n == 1) return cout << 81 << '\n', 0;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= 5; ++ j)
			cin >> a[i][j];
	for (int j = 1; j <= 5; ++ j) {
		c = 0;
		for (int i = 0; i < 10; ++ i) st[i] = 0;
		for (int i = 1; i <= n; ++ i) st[a[i][j]] = true;
		for (int i = 0; i < 10; ++ i) if (!st[i]) c ++;
		if (c != 9) ans += c;
	}
	if (!ans) ans = 81;
	cout << ans << '\n';
	return 0;
}
