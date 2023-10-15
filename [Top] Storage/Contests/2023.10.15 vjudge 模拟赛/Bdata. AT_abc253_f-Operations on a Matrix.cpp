#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e3;
const LL L = 1e9;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n = mt() % N + 1, m = mt() % N + 1, q = mt() % N + 1;
	cout << n << ' ' << m << ' ' << q << '\n';
	for (int i = 1; i <= q; ++ i) {
		int op = mt() % 3 + 1;
		cout << op << ' ';
		if (op == 1) {
			int l = mt() % m + 1, r = mt() % m + 1, x = mt() % L + 1;
			if (r < l) swap(l, r);
			cout << l << ' ' << r << ' ' << x << '\n';
		} else if (op == 2) {
			cout << mt() % n + 1 << ' ' << mt() % L + 1 << '\n';
		} else cout << mt() % n + 1 << ' ' << mt() % m + 1 << '\n';
	}
	return 0;
}
