#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int LN = 20;
int n, tp, mn[LN][N], mx[LN][N];
LL ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, tp = log2(n) + 1;
	for (int i = 1; i <= n; ++ i) {
		cin >> mn[0][i], mx[0][i] = mn[0][i];
	}
	for (int i = 1; i <= tp; ++ i)
		for (int j = 1; j + (1 << i) - 1 <= n; ++ j) {
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << i - 1)]);
			mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << i - 1)]);
		}
	for (int i = 1; i <= n; ++ i)
		for (int j = i; j <= n; ++ j) {
			int len = j - i + 1, k = log2(j - i + 1);
			ans = max(ans, (LL)len * min(mn[k][i], mn[k][j - (1 << k) + 1])
								 * max(mx[k][i], mx[k][j - (1 << k) + 1]));
		}
	return cout << ans << '\n', 0;
}

