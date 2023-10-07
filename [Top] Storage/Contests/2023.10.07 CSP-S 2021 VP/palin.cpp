#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int t, n, a[N << 1], na[N << 1];

namespace sub2 {
	bool jg = true;
	void solve() {
		for (int i = 1; i <= n << 1; ++ i) cout << 'L';
		cout << '\n';
		return;
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n << 1; ++ i) cin >> a[i];
	for (int i = n + 1; i <= n << 1; ++ i)
		if (a[i] != a[n * 2 - i + 1]) sub2::jg = false;
	if (sub2::jg) return sub2::solve();
	for (int s = 0; s <= 1 << (n << 1); ++ s) {
		int l = 1, r = n << 1;
		for (int i = 1; i <= n; ++ i) {
			if ((s >> n * 2 - i + 1) & 1) na[i] = a[r --];
			else na[i] = a[l ++];
		}
		bool f = false;
		for (int i = n + 1; i <= n << 1; ++ i) {
			if ((s >> n * 2 - i + 1) & 1) na[i] = a[r --];
			else na[i] = a[l ++];
			if (na[i] != na[n * 2 - i + 1]) { f = true; break; }
		}
		if (f) continue;
		for (int i = 1; i <= n << 1; ++ i)
			if ((s >> n * 2 - i + 1) & 1) cout << 'R';
			else cout << 'L';
		cout << '\n';
		return;
	}
	cout << -1 << '\n';
	return;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t --) solve();
}
