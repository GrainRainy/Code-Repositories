#include <bits/stdc++.h>
using namespace std;
const int N = 10;
const int M = 2e3;
const int Q = 2e2;
const int L = 1e9;
const int LL = 2e9;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n = mt() % N + 1, m = mt() % M + 1;
	cout << n << ' ' << m << '\n';
	for (int i = 1; i <= n; ++ i, cout << '\n')
		for (int j = 1; j <= m; ++ j)
			cout << ((long long)mt() % LL - L) << ' ';
	int q = mt() % Q + 1;
	cout << q << '\n';
	for (int i = 1, op, x, y, a, b, v; i <= q; ++ i) {
		op = mt() % 2 + 1;
		cout << op << ' ';
		if (op == 1) {
			cout << mt() % n + 1 << ' ' << mt() % m + 1 << ' ';
			cout << (long long)mt() % LL - L << '\n';
		} else {
			x = mt() % n + 1, y = mt() % m + 1;
			a = mt() % n + 1, b = mt() % m + 1;
			if (x > a) swap(a, x);
			if (y > b) swap(b, y);
			cout << x << ' ' << y << ' ' << a << ' ' << b << '\n';
		}
	}
	return 0;
}
