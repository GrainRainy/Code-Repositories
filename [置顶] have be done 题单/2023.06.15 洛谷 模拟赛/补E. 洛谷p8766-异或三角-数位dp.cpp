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

using namespace std;
using namespace IO;
using LL = long long;

const int N = 40;
int t, n;
int stk[N], top;
LL f[N][10][2];

LL dp(int pos, int state, bool lim) {
	if (pos <= 0) return state == 7;
	if (~f[pos][state][lim]) return f[pos][state][lim];
	int limit = lim ? stk[pos] : 1;
	LL res = 0;
	for (int i = 0, b, c; i <= limit; ++ i) {
		b = state & 1;
		c = state >> 1 & 1;
		if (!i) {
			res += dp(pos - 1, state, lim & (i == limit));
			if (b and c) res += dp(pos - 1, state | 4, lim & (i == limit));
		}
		if (i) {
			res += dp(pos - 1, state | 1, lim & (i == limit));
			res += dp(pos - 1, state | 2, lim & (i == limit));
		}
	}
	return f[pos][state][lim] = res;
}

void solve() {
	memset(f, -1, sizeof f);
	input(n); top = 0;
	while (n) stk[++ top] = n % 2, n >>= 1;
	output(dp(top, 0, true) * 3);
}

int main() {
	input(t);
	while (t --) solve();
	return 0;
}
