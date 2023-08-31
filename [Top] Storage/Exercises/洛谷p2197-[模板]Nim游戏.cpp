#include <bits/stdc++.h>
using std::cin;
int t, n, tmp, ans;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	while (t --) {
		cin >> n; ans = 0;
		for (int i = 1; i <= n; ++ i)
			cin >> tmp, ans ^= tmp;
		puts(ans ? "Yes" : "No");
	}
	return 0;
} 
