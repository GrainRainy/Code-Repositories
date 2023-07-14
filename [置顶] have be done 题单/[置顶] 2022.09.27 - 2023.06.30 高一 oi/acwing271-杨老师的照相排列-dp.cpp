#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x; 
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);		
	}
}

using namespace IO;
using namespace std;
using LL = long long;
const int K = 32;
int k, n[K], sum;
LL dp[K][K][K][K][K];

void solve() {
	memset(dp, 0, sizeof dp);
	dp[0][0][0][0][0] = 1;
	for (int i = 1; i <= k; ++ i) input(n[i]);
	for (int i = k + 1; i <= 5; ++ i) n[i] = 0;
		for (int a = 0; a <= n[1]; ++ a)
			for (int b = 0; b <= min(a, n[2]); ++ b)
				for (int c = 0; c <= min(b, n[3]); ++ c)
					for (int d = 0; d <= min(c, n[4]); ++ d)
						for (int e = 0; e <= min(d, n[5]); ++ e) {
							LL &t = dp[a][b][c][d][e];
							if (a and a - 1 >= b) t += dp[a - 1][b][c][d][e];
							if (b and b - 1 >= c) t += dp[a][b - 1][c][d][e];
							if (c and c - 1 >= d) t += dp[a][b][c - 1][d][e];
							if (d and d - 1 >= e) t += dp[a][b][c][d - 1][e];
							if (e) t += dp[a][b][c][d][e - 1];
						}
	output(dp[n[1]][n[2]][n[3]][n[4]][n[5]]);
	return;
}

int main() {
	while (input(k), k) solve();
	return 0;
}
