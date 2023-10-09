#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int MOD = 998244353;
int n, a[N], b[N], pw[N] = {1}, ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) 
		rd(a[i]), pw[i] = add(pw[i - 1], pw[i - 1]);
	for (int i = 1; i <= n; ++ i)
		for (int j = i; j <= n; j += i)
			b[i] = max(b[i], a[j]);
	sort(b + 1, b + n + 1, greater<int>()); 
	for (int i = 1; i <= n; ++ i) 
		upd(ans, 1ll * b[i] * pw[n - i] % MOD);
	return cout << ans << '\n', 0;
}
