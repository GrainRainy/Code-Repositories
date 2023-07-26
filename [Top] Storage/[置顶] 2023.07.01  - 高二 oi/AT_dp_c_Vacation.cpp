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
int n, w[N][4], dp[N][4];

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= 3; ++ j)
			input(w[i][j]);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= 3; ++ j)
			for (int k = 1; k <= 3; ++ k)
				if (k != j) dp[i][j] = max(dp[i][j], dp[i - 1][k] + w[i][j]);
	return printf("%d\n", max({dp[n][1], dp[n][2], dp[n][3]})), 0; 
}
