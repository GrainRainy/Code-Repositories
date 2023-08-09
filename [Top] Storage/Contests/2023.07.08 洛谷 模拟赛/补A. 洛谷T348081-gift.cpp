#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using IO::input;
using namespace std;
using LL = long long;
const int N = 1e3 + 10;
const int MOD = 1e7 + 7;
int n, m, a[N], sum;
int f[N], ans;

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i)
		input(a[i]), sum += a[i];
	sort(a + 1, a + n + 1);
	if (m > sum) return puts("1") & 0;
	f[0] = 1;
	for (int i = n; i; -- i) {
		sum -= a[i];
		for (int j = max(0, m - sum - a[i] + 1); j <= m - sum; ++ j)
			ans = ((LL)ans + f[j]) % MOD;
		for (int j = m; j >= a[i]; -- j)
			f[j] = ((LL)f[j] + f[j - a[i]]) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}
