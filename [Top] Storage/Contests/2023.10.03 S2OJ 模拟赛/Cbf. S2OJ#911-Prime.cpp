#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL l, r, k, ans;

bool check(LL u) {
	for (LL i = 2; i <= u / i and i <= k; ++ i) 
		if (!(u % i)) return false;
	return true;
}

int main() {
	cin >> l >> r >> k;
	for (LL i = l; i <= r; ++ i)
		if (check(i)) ans ^= i;
	cout << ans << '\n';
}
