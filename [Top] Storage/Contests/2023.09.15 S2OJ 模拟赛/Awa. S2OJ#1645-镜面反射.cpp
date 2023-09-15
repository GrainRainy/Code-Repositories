#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL t, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t --) {
		cin >> a >> b;
		cout << 360 * b / a / 2 - 2 << '\n';
	}
	return 0;
}
