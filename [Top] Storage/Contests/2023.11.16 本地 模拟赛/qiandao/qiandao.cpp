#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n, m, k, c, dg[N], ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int main() {
	freopen("qiandao.in", "r", stdin);
	freopen("qiandao.out", "w", stdout);
	rd(n), rd(m), rd(k), rd(c);
	for (int i = 1, a, b; i <= k; ++ i)
		rd(a), rd(b), dg[a] ++, dg[n + b] ++;
	for (int i = 1; i <= n + m; ++ i) ans += (bool)(dg[i] % c);
	return cout << ans << '\n', 0;
}
