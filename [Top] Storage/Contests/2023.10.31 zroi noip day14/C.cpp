#include <bits/stdc++.h>
using namespace std;
int t, n, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t --) {
		cin >> n, c = 0;
		for (int i = 1, x; i <= n; ++ i) 
			cin >> x, c += x == 1;
		if (c == n) puts(n & 1 ? "Yes" : "No");
		else puts("Yes");
	}
	return 0;
}
