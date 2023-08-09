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
using LL = long long;
const int N = 1e2 + 10;
const int W = 1e3 + 10;
int n, tot, sum, v[N], w[N];
LL dp[W * N];

int main() {
	input(n), input(tot);
	for (int i = 1; i <= n; ++ i) {
		input(v[i]), input(w[i]);
		sum += w[i];
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for (int i = 1; i <= n; ++ i)
		for (int j = sum; j >= w[i]; -- j)
			dp[j] = min(dp[j - w[i]] + v[i], dp[j]);
	int mx = 0;
	for (int i = 1; i <= sum; ++ i)
		if (dp[i] and dp[i] <= tot) mx = max(mx, i);
	return printf("%d\n", mx), 0;
}
