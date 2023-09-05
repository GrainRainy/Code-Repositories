#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n, h[N];

int solve(int l, int r) {
	if (l < 0 or r > n or l > r) return 0;
	int mn = 0x3f3f3f3f, mnid = 0;
	for (int i = l; i <= r; ++ i)
		if (h[i] < mn) mn = h[i], mnid = i;
	for (int i = l; i <= r; ++ i)
		h[i] -= mn;
	return min(r - l + 1, mn + solve(l, mnid - 1) + solve(mnid + 1, r));
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> h[i];
	return cout << min(n, solve(1, n)) << '\n', 0;
}
