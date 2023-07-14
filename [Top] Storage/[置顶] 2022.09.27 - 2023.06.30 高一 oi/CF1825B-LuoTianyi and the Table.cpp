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

int n, m;

inline void solve() {
	input(n), input(m);
	int tmp;
	LL ans = 0;
	int maxa = -1e6, maxb = -1e6, mina = 1e6, minb = 1e6;
	for (int i = 1; i <= n * m; i ++) {
		input(tmp);
		if (tmp >= maxa) maxb = maxa, maxa = tmp;
		else if (tmp >= maxb) maxb = tmp;
		if (tmp <= mina) minb = mina, mina = tmp;
		else if (tmp <= minb) minb = tmp;
	}
	ans += max(maxb - mina, maxa - minb) * (min(m, n) - 1);
	ans += (maxa - mina) * (n * m - min(m, n));
	output(ans);
	return;
}

int main() {
	int t; input(t);
	while (t -- ) solve();
	return 0;
}
