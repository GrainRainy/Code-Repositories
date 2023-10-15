#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 26;
const LL L = 2e9;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
	int n = mt() % N + 2;
	cout << n << '\n';
	for (int i = 1; i <= n; ++ i)
		cout << mt() % n << ' ';
	cout << '\n';
	for (int i = 2; i <= n; ++ i) {
		cout << i << ' ' << mt() % (i - 1) + 1 << ' ';
		cout << mt() % L - 100000000 << '\n';
//		cout << mt() % 10 + 1 << '\n';
	}
	return 0;
}
