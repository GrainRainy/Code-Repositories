#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int MOD = 998244353;
string s;
int n, k, f[N];
long long ans = 1;

bool cmp(int a, int b, int c, int d) {
	for (int i = 0; i <= b - a; ++ i)
		if (s[a + i] != s[c + i]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s >> k;
	n = s.size(), s = "0" + s;
	for (int i = 1; i <= n; ++ i) {
		for (int x = 1; x <= i; ++ x) {
			if (x < i - x + 1) continue;
			if (!cmp(1, x, i - x + 1, i)) continue;
			if (!((x - (i - x + 1) + 1) % k)) f[i] ++;
		}
	}
	for (int i = 1; i <= n; ++ i) ans = ans * (f[i] + 1) % MOD;
	cout << ans << '\n';
	return 0;
}
