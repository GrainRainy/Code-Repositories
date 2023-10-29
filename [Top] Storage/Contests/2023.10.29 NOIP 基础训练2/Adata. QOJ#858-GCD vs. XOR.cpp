#include <bits/stdc++.h>
using namespace std;
const int N = 3e3;
const int L = 1e4;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
//	freopen("a.in", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = mt() % 20 + 1;
//	t = 20;
	cout << t << '\n';
	while (t --) {
		int n = mt() % N + 1;
//		n = 2e6;
		cout << n << '\n';
//		cout << L << ' ';
//		for (int i = 2; i <= n; ++ i)
//			cout << mt() % L + 1 << ' ';
		for (int i = 1; i <= n; ++ i)
			cout << mt() % L + 1 << ' ';
		cout << '\n';
	}
}
