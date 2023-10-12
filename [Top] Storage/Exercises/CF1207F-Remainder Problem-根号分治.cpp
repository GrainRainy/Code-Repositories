#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int SN = 707;
int n = 5e5, q, op, x, y, a[N], sm[SN + 10][SN + 10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> q;
	while (q --) {
		cin >> op >> x >> y;
		if (op == 1) {
			a[x] += y;
			for (int i = 1; i <= SN; ++ i)
				sm[i][x % i] += y;
		} else {
			if (x <= SN) cout << sm[x][y] << '\n';
			else {
				int res = 0;
				for (int i = y; i <= n; i += x)
					res += a[i];
				cout << res << '\n'; 
			}
		}
	}
	return 0;
} 
