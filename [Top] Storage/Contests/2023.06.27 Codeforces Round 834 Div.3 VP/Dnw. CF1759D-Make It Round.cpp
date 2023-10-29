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
LL n, m, cnt2, cnt5, d, t;

void solve() {
	input(n), input(m);
	cnt2 = cnt5 = 0, d = 1, t = n;
	while (!(n % 2)) cnt2 ++, n /= 2;
	while (!(n % 5)) cnt5 ++, n /= 5;
	while (cnt2 < cnt5 and d * 2 <= m) d *= 2, cnt2 ++;
	while (cnt5 < cnt2 and d * 5 <= m) d *= 5, cnt5 ++;
	while (d * 10 <= m) d *= 10;
	d *= m / d;
	output(t * d);
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0; 
}
