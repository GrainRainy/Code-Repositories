#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, h[2];
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> h[i & 1];
		if (h[i & 1] > h[i - 1 & 1]) ans += h[i & 1] - h[i - 1 & 1];
	}
	return cout << ans << '\n', 0;
} 
