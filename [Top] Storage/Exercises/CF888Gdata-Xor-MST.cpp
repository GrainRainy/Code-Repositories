#include <bits/stdc++.h>
using namespace std;
const int N = 2e3;
const int L = 1 << 29;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
	cout.tie(0)->ios::sync_with_stdio(false);
	int n = mt() % N + 1;
	cout << n << '\n';
	for (int i = 1; i <= n; ++ i) cout << mt() % L + 1 << ' ';
	return cout << '\n', 0;
}
