#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) bool f = false;
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}
using namespace IO;
using namespace std;

const int LOGN = 30 + 10;
int n, ans, dp[LOGN];

int main() {
	input(n);
	for (int i = 1, tmp, len; i <= n; ++ i) {
		input(tmp); len = 1;
		for (int j = 0; j <= 30; ++ j) 
			if ((1ll << j) & tmp) len = max(dp[j] + 1, len);
		for (int j = 0; j <= 30; ++ j)
			if ((1ll << j) & tmp) dp[j] = max(dp[j], len);
		ans = max(ans, len);
	}
	cout << ans << endl;
	return 0;
}

