#include <iostream>
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

const int N = 3e2 + 10;
const int M = 1e5 + 10;
const int MOD = 998244353;
int n, ary[N];
// basis
int sum, dp[N][M << 1], ans;

void upd(int &t, int x) {
	t += x;
	while (t >= MOD) t -= MOD;
	return;
}

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(ary[i]), sum += ary[i];
	
	dp[0][ary[2] + sum] = 1;
	for (int i = 0; i <= n - 3; ++ i) {
		for (int j = 0; j <= sum << 1; ++ j) {
			if (!dp[i][j]) continue;
			if (j == sum) dp[i + 1][ary[i + 3] + j] = dp[i][j];
			else {
				if (ary[i + 3] + j <= (sum << 1))
					upd(dp[i + 1][ary[i + 3] + j], dp[i][j]);
				if (ary[i + 3] <= j) 
					upd(dp[i + 1][ary[i + 3] - j + (sum << 1)], dp[i][j]);
			}
		}
	}
	for (int i = 0; i <= (sum << 1); ++ i) 
		upd(ans, dp[n - 2][i]);
	cout << ans << endl;
	return 0;
}
