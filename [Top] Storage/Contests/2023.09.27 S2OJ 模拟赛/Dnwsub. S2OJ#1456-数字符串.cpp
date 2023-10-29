#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int MOD = 998244353;
int n, k, cnt[N], nxt[N], f[N];
char s[N];
long long ans = 1;

namespace sub2 {
	void solve() {
		int lcm = k & 1 ? k << 1 : k;
		for (int i = 1, r; i <= n; ++ i) {
			if ((i & 1)) f[i] = i / k - i / lcm;
			else f[i] = i / lcm;
			ans = ans * (f[i] + 1) % MOD;
		}
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s + 1 >> k;
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++ i) cnt[s[i] - 'a'] ++;
	if (cnt[s[1] - 'a'] == n) return sub2::solve(), 0;
	for (int i = 2, j = 0; i <= n; ++ i) {
		while (j and s[i] != s[j + 1]) j = nxt[j];
		if (s[i] == s[j + 1]) j ++;
		nxt[i] = j;
	}
	for (int i = 1, p; i <= n; ++ i) {
		p = i;
		while (p << 1 >= i + 1) {
			f[i] += !(((p << 1) - i) % k);
			p = nxt[p];
		}
		ans = ans * (f[i] + 1) % MOD;
	}
	cout << ans << '\n';
	return 0;
}
