#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, q, ary[N], op, l, r;
int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> ary[i];
	for (int i = 1; i <= m; i ++) {
		cin >> op >> l >> r;
		if (!op) sort(ary + l + 1, ary + r + 1);
		else sort(ary + l + 1, ary + r + 1, greater<int>());
	}
	cin >> q;
	cout << ary[q] << endl;
	return 0;
}
