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

const int N = 2e2 + 10;
const int dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};
int n, m, x, y, k, s, t, d, ans;
char gph[N][N];
struct Node { int val, pos; }q[N]; int head, tail;
int dp[N][N];

void solve(int x, int y, int len, int d) {
	head = 1, tail = 0;
	for (int i = 1; x >= 1 and x <= n and y >= 1 and y <= m; ++ i, x += dx[d], y += dy[d]) {
		if (gph[x][y] == 'x') head = 1, tail = 0;
		else {
			while (head <= tail and q[tail].val + i - q[tail].pos < dp[x][y]) tail --;
			q[++ tail] = {dp[x][y], i};
			if (q[tail].pos - q[head].pos > len) head ++;
			dp[x][y] = q[head].val + i - q[head].pos;
			ans = max(ans, dp[x][y]);
		}
	}
}

int main() {
	input(n), input(m), input(x), input(y), input(k);
	for (int i = 1; i <= n; ++ i) cin >> gph[i] + 1;
	memset(dp, 0xcf, sizeof dp); dp[x][y] = 0;
	for (int i = 1, len; i <= k; ++ i) {
		input(s), input(t), input(d);
		len = t - s + 1;
		if (d == 1) for (int y = 1; y <= m; ++ y) solve(n, y, len, d);
		if (d == 2) for (int y = 1; y <= m; ++ y) solve(1, y, len, d);
		if (d == 3) for (int x = 1; x <= n; ++ x) solve(x, m, len, d);
		if (d == 4) for (int x = 1; x <= n; ++ x) solve(x, 1, len, d);
	}
	cout << ans << '\n';
	return 0;
} 
