#include <bits/stdc++.h>
using namespace std;
long long k, a, b, x, y;

int main() {
	cin >> k >> a >> b >> x >> y;
	if (b >= k and y <= k or b <= k and y >= k)
		cout << (a - x) * (a - x) + (b - y) * (b - y) << '\n';
	else cout << (a - x) * (a - x) + (b - (2 * k - y)) * (b - (2 * k - y)) << '\n';
	return 0;
}
