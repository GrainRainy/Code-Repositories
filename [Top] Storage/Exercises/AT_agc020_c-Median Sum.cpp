#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int n, s;
bitset<N * N> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, dp[0] = 1;
	for (int i = 1, a; i <= n; ++ i)
		cin >> a, s += a, dp |= dp << a;
	for (int i = s + 1 >> 1; i <= s; ++ i)
		if (dp[i]) return cout << i << '\n', 0;
}
