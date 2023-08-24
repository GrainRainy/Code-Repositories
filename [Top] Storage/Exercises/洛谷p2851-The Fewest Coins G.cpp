#include <bits/stdc++.h>
#define enter putchar('\n')

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar(); bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T, typename... Args> void input(T &x, Args&... args) {
	input(x), input(args...);
}
template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int T = 1e4 + 10;
const int N = 1e2 + 10;
const int V = 120;

int n, t;
int v[N], c[N];
LL sum, maxn;
int dp[3][T + V * V];

int main() {
	input(n, t);
	for (int i = 1; i <= n; i ++) input(v[i]);
	for (int i = 1; i <= n; i ++) {
		input(c[i]);
		sum += c[i] * v[i];
		maxn = max(maxn, (LL)v[i] * v[i]);
	}
	
	if (sum < t) return puts("-1"), 0;
	// spj 
	
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = dp[1][0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= c[i]; j <<= 1) {
			for (int k = t + maxn; k >= j * v[i]; k --) 
				dp[0][k] = min(dp[0][k], dp[0][k - j * v[i]] + j);
			c[i] -= j;
		}
		if (c[i]) {
			for (int k = t + maxn; k >= c[i] * v[i]; k --) 
				dp[0][k] = min(dp[0][k], dp[0][k - c[i] * v[i]] + c[i]);
		}
	}
	
	for (int i = 1; i <= n; i ++) 
		for (int j = v[i]; j <= maxn; j ++)
			dp[1][j] = min(dp[1][j], dp[1][j - v[i]] + 1);
	
	int ans = 0x3f3f3f3f;
	for (int i = t; i <= t + maxn; i ++)
		ans = min(ans, dp[0][i] + dp[1][i - t]);
	cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
	return 0;
}
