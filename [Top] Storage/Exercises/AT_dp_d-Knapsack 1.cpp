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
const int V = 1e5 + 10;
int n, tot, v[N], w[N];
LL dp[V];

int main() {
	input(n), input(tot);
	for (int i = 1; i <= n; ++ i) {
		input(v[i]), input(w[i]);
		for (int j = tot; j >= v[i]; -- j)
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
	}
	return printf("%lld\n", dp[tot]), 0;
}
