#include <iostream>
#include <cstring>
#include <algorithm>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace IO;
using namespace std;

const int N = 2e3 + 10;

int t, maxp, w, ap, bp, as, bs;
int head, tail, q[N];
int dp[N][N];

int main() {
	input(t), input(maxp), input(w);
	memset(dp, 0xcf, sizeof dp);
	for (int i = 1; i <= t; ++ i) {
		input(ap), input(bp), input(as), input(bs);
		for (int j = 0; j <= as; ++ j) dp[i][j] = -1 * j * ap;
		for (int j = 0; j <= maxp; ++ j) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		if (i <= w) continue;
		head = 1, tail = 0;
		for (int j = 0; j <= maxp; ++ j) {
			while (head <= tail and q[head] < j - as) head ++;
			while (head <= tail and dp[i - w - 1][q[tail]] + q[tail] * ap <= dp[i - w - 1][j] + j * ap) tail --;
			q[++ tail] = j;
			if (head <= tail) dp[i][j] = max(dp[i][j], dp[i - w - 1][q[head]] + q[head] * ap - j * ap);
		}
		head = 1, tail = 0;
		for (int j = maxp; j >= 0; -- j) {
			while (head <= tail and q[head] > j + bs) head ++;
			while (head <= tail and dp[i - w - 1][q[tail]] + q[tail] * bp <= dp[i - w - 1][j] + j * bp) tail --;
			q[++ tail] = j;
			if (head <= tail) dp[i][j] = max(dp[i][j], dp[i - w - 1][q[head]] + q[head] * bp - j * bp);
		}
	}
	return cout << dp[t][0] << '\n', 0;
}
