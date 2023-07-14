#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 1;
int main() {
	cin >> n >> m;
	if (n == 1) return cout << m << endl, 0;
	for (long long i = 2; i <= m / i; ++ i) {
		if (!(m % i)) {
			if (m / i >= n) ans = max(ans, i);
			if (i >= n) ans = max(ans, m / i);
		}
	}
	cout << ans << endl;
	return 0;
}
