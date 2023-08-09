#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
}

using IO::input;
using namespace std;
const int N = 1e5 + 10;
int n, k, h[N], dp[N];

int main() {
	input(n), input(k);
	for (int i = 1; i <= n; ++ i) input(h[i]);
	memset(dp, 0x3f, sizeof(int) * (n + 10));
	dp[1] = 0;
	for (int i = 2; i <= n; ++ i)
		for (int j = max(1, i - k); j < i; ++ j)
			dp[i] = min(dp[i], dp[j] + abs(h[j] - h[i]));
	return printf("%d\n", dp[n]), 0;
}
