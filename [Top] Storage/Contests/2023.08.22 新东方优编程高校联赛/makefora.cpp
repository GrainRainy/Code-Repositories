#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int M = 1e5;
const int MOD = 2147483647;
mt19937 mt(chrono::system_clock().now().time_since_epoch().count());

int main() {
	freopen("test.in", "w", stdout);
	int q = N, n = M, m = M;
	cout << q << ' ' << n << ' ' << m << '\n';
	for (int i = 1; i <= n; ++ i)
		cout << mt() % MOD + 1 << ' ';
	cout << '\n';
	for (int i = 1; i <= m; ++ i)
		cout << mt() % MOD + 1 << ' ';
	cout << '\n';
	return 0;
}
