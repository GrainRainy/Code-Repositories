#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
	int n = mt() % N + 2, m = mt() % N + 1, cnt = 1;
	cout << n << ' ' << m << '\n';
	for (int i = 1; i <= m; ++ i) {
		int op = mt() % 3 + 1;
		if (op == 1) {
			int v = mt() % n;
			cout << "K " << v << '\n';
		} else if (op == 2) {
			cnt ++;
			int x = mt() % n;
			int y = mt() % n;
			while (y == x) y = mt() % n;
			cout << "R " << x << ' ' << y << '\n';
		} else {
			int st = mt() % n;
			int ed = mt() % n;
			int t = mt() % cnt + 1;
			cout << "T " << st << ' ' << ed << ' ' << t << '\n';
		}
	}
}
