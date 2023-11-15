#include <bits/stdc++.h>
using namespace std;
const int N = 10;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
	int t = mt() % 10 + 1;
	cout << t << '\n';
	while (t --) {
		int n = mt() % N + 1;
		for (int i = 1; i <= n; ++ i) {
			int op = mt() % 3;
			if (!op) cout << 'a';
			else if (op == 1) cout << 'b';
			else cout << '?';
		}
		cout << ' ' << mt() % 7 + 1 << ' ' << mt() % 7 + 1 << '\n';
	}
	return 0;
}
