#include <bits/stdc++.h>
using namespace std;
const int L = 10;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false), cout.tie(0);
	int n = mt() % 10 + 1, m = mt() % (n >> 1) + 1;
	cout << n << ' ' << m << '\n';
	for (int i = 1; i <= n; ++ i)
		cout << mt() % L + 1 << ' ';
	cout << '\n';
}
