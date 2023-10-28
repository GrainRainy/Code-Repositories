#include <bits/stdc++.h>
using namespace std;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
	freopen("test.in", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n = 1e5;
	cout << n << '\n';
	for (int i = 1; i <= n; ++ i)
		cout << mt() % 1024 << '\n';
}
