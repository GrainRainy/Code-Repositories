#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10;
int t, n, m, f[M], pc[20][60];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> t >> m;
	for (int j = 1; j <= n; ++ j)
		for (int i = 1; i <= t; ++ i) 
			cin >> pc[i][j];
	for (int i = 1; i < t; ++ i) {
		memset(f, 0, sizeof(int) * (m + 10)); 
		for (int j = 1; j <= n; ++ j) 
			for (int k = pc[i][j]; k <= m; ++ k) 
				f[k] = max(f[k], f[k - pc[i][j]] + pc[i + 1][j] - pc[i][j]);
		m += f[m];
	}
	return cout << m << '\n', 0;
}
