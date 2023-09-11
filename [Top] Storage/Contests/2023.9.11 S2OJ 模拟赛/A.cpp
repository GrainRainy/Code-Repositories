#include <bits/stdc++.h>
using namespace std;
int t, m, d;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t >> m >> d;
	cout << m << '\n';
	if (!t) {
		for (int i = 1; i <= m; ++ i)
			cout << m - i + 1 << ' ';
		cout << '\n';
	} else {
		for (int i = 1; i <= m; ++ i)
			cout << i + 1 << ' ';
		cout << '\n';
	}
	return 0;
}
