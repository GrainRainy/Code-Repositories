#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, ary[N];
int op, l, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> ary[i];
	for (int i = 1; i <= m; ++ i) {
		cin >> op >> l >> r; l ++, r ++;
		if (op == 0) for (int j = l; j <= r; ++ j) ary[j] = 0;
		if (op == 1) for (int j = l; j <= r; ++ j) ary[j] = 1;
		if (op == 2) for (int j = l; j <= r; ++ j) ary[j] ^= 1;
		if (op == 3) {
			int cnt = 0;
			for (int j = l; j <= r; ++ j) cnt += ary[j];
			cout << cnt << '\n';
		} if (op == 4) {
			int cnt = 0, mx = 0;
			for (int j = l; j <= r; ++ j) {
				if (!ary[j]) {
					mx = max(mx, cnt);
					cnt = 0;
				} else cnt ++;
			}
			mx = max(mx, cnt);
			cout << mx << '\n';
		}
		
		for (int j = 1; j <= n; ++ j)
			cout << ary[j] << ' ';
		cout << '\n';
		
	}
	return 0;
}
