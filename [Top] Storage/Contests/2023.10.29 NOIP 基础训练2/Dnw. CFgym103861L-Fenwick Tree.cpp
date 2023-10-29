#include <bits/stdc++.h>
using namespace std;
using LL = long long; 
const int N = 1e6 + 10;
int n, c[N], ans;
char s[N];

void solve() {
	cin >> n >> s + 1, ans = 0;
	memset(c, 0, sizeof(int) * (n + 10));
	for (int i = 1; i <= n; ++ i) {
		if (s[i] == '1') c[i + (i & -i)] ++;
		if (s[i] == '1' and !c[i]) ans ++;
		if (s[i] == '0' and c[i] == 1) ans ++;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
