#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e7 + 10;
LL l, r, k, lim, ans;
bool st[N], as[N]; // i, l + i

int main() {
	cin >> l >> r >> k, lim = sqrt(r);
	for (LL i = 2; i <= min(lim, k); ++ i) {
		if (!st[i]) {
			for (LL j = i + i; j <= min(lim, k); j += i)
				st[j] = true;
			for (LL j = max(i + i, (LL)ceil((double)l / i) * i); j <= r; j += i)
				as[j - l] = true;
		}
	}
	for (int i = 0; i <= r - l; ++ i)
		if (!as[i]) ans ^= l + i;
	return cout << ans << '\n', 0;
}
