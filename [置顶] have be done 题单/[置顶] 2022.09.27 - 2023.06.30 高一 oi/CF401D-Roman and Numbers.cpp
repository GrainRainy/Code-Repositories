#include <bits/stdc++.h>
#define ET putchar('\n')

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
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

const int N = 20;
const int M = 1e2 + 10;
const int S = (1 << N - 2) + 10;
LL n, m;
int nums[N], top = -1;
LL dp[S][M]; 
bool st[N];

int main() {
	input(n), input(m);
	do nums[++ top] = n % 10, n /= 10; while (n);
	
	dp[0][0] = 1;
	for (int s = 1; s < 1 << top + 1; s ++) {
		memset(st, 0, sizeof st);
		for (int i = 0; i <= top; i ++) {
			if (s == (1 << i) and !nums[i]) break;
			if (!(s & (1 << i)) or st[nums[i]]) continue;
			st[nums[i]] = true;
			for (int j = 0; j < m; j ++)
				dp[s][(j * 10 + nums[i]) % m] += dp[s ^ (1 << i)][j];
		}
	}
	output(dp[(1 << top + 1) - 1][0]);
	return 0;
}
