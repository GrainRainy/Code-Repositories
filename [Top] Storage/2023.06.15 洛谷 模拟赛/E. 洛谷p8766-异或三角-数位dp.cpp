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

const int N = 1e5 + 10;
int t, n;
int cnt, ary[3];

void solve() {
	cnt = ary[0] = ary[1] = ary[2] = 0;
	input(n);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j) {
			ary[0] = i, ary[1] = j, ary[2] = i ^ j;
			if (!ary[2] or ary[2] > n) continue;
			if (ary[0] + ary[1] > ary[2] and ary[0] + ary[2] > ary[1] and ary[1] + ary[2] > ary[0]) cnt ++;
		}
	return output(cnt), void();
}

int main() {
	input(t);
	while (t --) solve();
}
