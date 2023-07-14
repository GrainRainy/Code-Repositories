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

using namespace std; 
using namespace IO;
using LL = long long;

const int K = 60;
const int N = 10; 
int t, k, a, b, c;
double dp[K][N][N][N];

int main() {
	for (int i = 1; i <= 50; ++ i) 
		for (int j = 0; j <= 7; ++ j)
			for (int k = 0; k + j <= 7; ++ k)
				for (int m = 0; m + k + j <= 7; ++ m) {
					double &t = dp[i][j][k][m];
					double p = 1.0 / ((double)j + (double)k + (double)m + 1);
					if (j) t += dp[i - 1][j - 1][k][m] * j * p;
					if (k) t += dp[i - 1][j + 1][k - 1][j + k + m + 1 <= 7 ? m + 1 : m] * k * p;
					if (m) t += dp[i - 1][j][k + 1][j + k + m + 1 <= 7 ? m : m - 1] * m * p;
					t += (dp[i - 1][j][k][m] + 1) * 1 * p;
				}
	input(t);
	while (t --) {
		input(k), input(a), input(b), input(c);
		printf("%.2lf\n", dp[k][a][b][c]);
	}
	return 0;
}
