#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, d, c[N], sm, ans = N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> d;
	for (int i = 1, x; i <= n; ++ i) {
		cin >> x;
		if (x) c[i % d] ++, sm ++;
	}
	for (int i = 0; i < d; ++ i) ans = min(ans, sm - c[i]);
	return cout << ans << '\n', 0;
}
