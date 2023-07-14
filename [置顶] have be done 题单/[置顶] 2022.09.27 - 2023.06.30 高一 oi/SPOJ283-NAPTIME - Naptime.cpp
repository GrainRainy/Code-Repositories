#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
} 

template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top -- ] | '0');
	putchar(ed);
}

const int N = 3850;
int n, b, w[N];
int dp[2][N][2], dp2[2][N][2]; 
int ans = 0;

void solve() {
	memset(dp, 0xcf, sizeof dp);
	memset(dp2, 0xcf, sizeof dp2);
	dp[1][1][1] = dp[1][0][0] = 0;
	ans = 0;
	
	input(n), input(b);
	for (int i = 1; i <= n; ++ i) input(w[i]);
	dp2[1][1][1] = w[1];
	
	for (int i = 2; i <= n; i ++) {
		for (int j = 0; j <= min(i, b); j ++) {
			dp[i & 1][j][0] = max(dp[(i - 1) & 1][j][0], dp[(i - 1) & 1][j][1]);
			if (j >= 1) dp[i & 1][j][1] = max(dp[i - 1 & 1][j - 1][0], dp[(i - 1) & 1][j - 1][1] + w[i]);
			
			dp2[i & 1][j][0] = max(dp2[(i - 1) & 1][j][0], dp2[i - 1 & 1][j][1]);
			if (j >= 1) dp2[i & 1][j][1] = max(dp2[(i - 1) & 1][j - 1][0], dp2[(i - 1) & 1][j - 1][1] + w[i]);
			
		}
	}
	ans = max({dp[n & 1][b][1], dp[n & 1][b][0], dp2[n & 1][b][1]});
	output(ans);
	return;
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
