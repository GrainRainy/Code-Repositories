#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
//	freopen("magic.in", "w", stdout);
	int n = mt() % N + 2, m = mt() % N + 1;
	cout << n << ' ' << m << '\n';
	for (int i = 2; i <= n; ++ i)
		cout << i << ' ' << mt() % (i - 1) + 1 << '\n';
	for (int i = 1; i <= m; ++ i)
		cout << mt() % n + 1 << ' ' << mt() % n + 1 << '\n';
}
