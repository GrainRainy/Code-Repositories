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
const int N = 16 + 3;
int n, k, w[N];
LL dp[1 << N][N];

int main() {
	input(n), input(k);
	for (int i = 1; i <= n; ++ i) {
		input(w[i]);
		dp[1 << i - 1][i] = 1;
	}
	for (int s = 1; s < (1 << n); ++ s) {
		for (int i = 1; i <= n; ++ i) {
			if (!(s & (1 << i - 1))) continue;
			for (int j = 1; j <= n; ++ j) {
				if (i == j) continue;
				if (abs(w[i] - w[j]) <= k) continue;
				dp[s][i] += dp[s ^ (1 << i - 1)][j];
			}
		}
	}
	LL res = 0;
	for (int i = 1; i <= n; ++ i)
		res += dp[(1 << n) - 1][i];
	printf("%lld\n", res);
	return 0;
}
