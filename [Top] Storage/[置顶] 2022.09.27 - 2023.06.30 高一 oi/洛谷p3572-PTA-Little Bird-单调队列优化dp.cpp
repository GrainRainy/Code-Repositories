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

const int N = 1e6 + 10;
int n, h[N], m, k;
int dp[N], q[N], head, tail;

void solve() {
	input(k);
	q[head = tail = 1] = 1;
	for (int i = 2; i <= n; ++ i) {
		while (head <= tail and q[head] < i - k) head ++;
		dp[i] = dp[q[head]] + (h[q[head]] <= h[i]);
		while (head <= tail and (dp[q[tail]] > dp[i] or dp[q[tail]] == dp[i] and h[q[tail]] <= h[i])) tail --;
		q[++ tail] = i;
	}
	return output(dp[n]), void();
}

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(h[i]);
	
	input(m);
	while (m --) solve();
	return 0;
}
