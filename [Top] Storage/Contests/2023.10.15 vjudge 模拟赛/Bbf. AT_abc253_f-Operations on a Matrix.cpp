#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10;
int n, m, q, a[N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	while (q --) {
		int op, l, r, x, i, j;
		cin >> op;
		if (op == 1) {
			cin >> l >> r >> x;
			for (int j = l; j <= r; ++ j)
				for (int i = 1; i <= n; ++ i)
					a[i][j] += x;
		} else if (op == 2) {
			cin >> i >> x;
			for (int j = 1; j <= m; ++ j)
				a[i][j] = x;
		} else if (op == 3) {
			cin >> i >> j;
			cout << a[i][j] << '\n';
		}
	}
	return 0;
}
