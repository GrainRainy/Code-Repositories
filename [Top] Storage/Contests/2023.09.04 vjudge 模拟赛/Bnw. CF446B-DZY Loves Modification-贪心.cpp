#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
}
using IO::rd;
using namespace std;
using LL = long long;
const int N = 1e3 + 10;
const int K = 1e6 + 10;
LL n, m, k, p, c[K], r[K], ans = -1e18;
priority_queue<LL> row, clo;

int main() {
	rd(n), rd(m), rd(k), rd(p);
	for (int i = 1, val, tmp; i <= n; ++ i) {
		val = 0;
		for (int j = 1; j <= m; ++ j)
			rd(tmp), val += tmp, c[j] += tmp;
		row.push(val);
	}
	for (int i = 1; i <= m; ++ i) clo.push(c[i]);
	for (int i = 1; i <= k; ++ i) {
		r[i] = row.top(), c[i] = clo.top();
		row.pop(), clo.pop();
		row.push(r[i] - m * p), clo.push(c[i] - n * p);
		r[i] += r[i - 1], c[i] += c[i - 1];
	}
	for (int i = 0; i <= k; ++ i) ans = max(ans, r[i] + c[k - i] - (LL)i * (k - i) * p);
	return cout << ans << '\n', 0;
}
