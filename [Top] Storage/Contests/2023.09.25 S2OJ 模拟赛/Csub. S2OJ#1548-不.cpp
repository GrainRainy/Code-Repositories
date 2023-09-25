#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
int n, m = 1e8;
LL w[N];
double st, ed;
LL ans = 1;
int stk[N], top;

void solve() {
	for (int s = 1; s < 1 << n; ++ s) {
		int cnt = 0;
		LL g = 0;
		for (int i = 1; i <= n; ++ i) 
			if ((s >> i - 1) & 1) {
				cnt ++;
				if (!g) g = w[i];
				else g = __gcd(g, w[i]);
			}
		if (cnt >= (n + 1 >> 1)) ans = max(ans, g);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> w[i];
	if (n <= 10) return solve(), 0;
	for (int i = 2; i <= m and (clock() - st) / CLOCKS_PER_SEC <= 0.9; ++ i) {
		bool jg = false;
		for (int j = 1; j <= top; ++ j)
			if (!(i % stk[j])) { jg = true; break; }
		if (jg) continue;
		int cnt = 0;
		for (int j = 1; j <= n; ++ j) if (!(w[j] % i)) cnt ++;
		if (cnt < (n + 1 >> 1)) stk[++ top] = i;
		else ans = i;
	}
	cout << ans << '\n';
}


