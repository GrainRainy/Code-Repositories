#include <bits/stdc++.h>
#define int long long
using namespace std;
int l, r, k, ans;

signed main() {
	cin >> l >> r >> k;
	for (int i = l; i <= r; ++ i) {
		bool f = true;
		for (int j = 2; j <= i / j and j <= k; ++ j)
			if (!(i % j)) { f = false; break; }
		if (f) ans ^= i;
	}
	return cout << ans << '\n', 0;
}

