#include <bits/stdc++.h>
using namespace std;
const int N = 10;
const int L = 10;
const int B = 100;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false), cout.tie(0);
	int n = mt() % N + 1, q = mt() % N + 1;
	cout << n << '\n';
	for (int i = 1; i <= n; ++ i) cout << mt() % L + 1 << ' ';
	cout << '\n';
	for (int i = 1; i <= n; ++ i) cout << mt() % B + 1 << ' ';
	cout << '\n' << q << '\n';
	for (int i = 1, l, r, x; i <= q; ++ i) {
		l = mt() % n + 1, r = mt() % n + 1, x = mt() % L + 1;
		if (l > r) swap(l, r);
		cout << l << ' ' << r << ' ' << x << '\n';
	}
	return 0;
}
