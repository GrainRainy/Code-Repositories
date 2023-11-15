#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false);
	int t = mt() % 10 + 1;
	cout << t << '\n';
	while (t --) {
		int m = mt() % N + 1, n = mt() % m + 1;
		cout << n << ' ' << m << '\n';
		for (int i = 1; i <= n; ++ i)
			cout << mt() % 10000 + 1 << ' ';
		cout << '\n';
	}
	return 0;
}
