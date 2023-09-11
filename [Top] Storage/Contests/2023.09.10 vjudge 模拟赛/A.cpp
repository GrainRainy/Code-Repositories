#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d, ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	while (n --) {
		cin >> a >> b >> c >> d;
		ans = 1;
		for (int i = 1; i <= b and i <= d; ++ i) {
			i = min(b / (b / i), d / (d / i));
			if (a <= b / i * i and c <= d / i * i) ans = i;
		}
		cout << ans << '\n';
	}
	return 0;
}
