#include <bits/stdc++.h>
using namespace std;
int n, m, k;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

void solve() {
	rd(n), rd(m), rd(k);
	if (k > 3) return puts("0"), void();
	int ans[4] = {0, 1, m / n + min(n, m) - (m >= n), max(m - n, 0) - m / n + (m >= n)};
	return ot(ans[k]);
}

int main() {
	int t; rd(t);
	while (t --) solve();
}
