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
		if (a / b > 90) cout << "WHAT ???\n";
		LL g = __gcd(a, b);
		a /= g, b /= g;
		cout << 180ll / __gcd(180ll, a) * b - 2 << '\n';
	}
	return 0;
}
