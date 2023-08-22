#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	} 
	template <typename T> inline void ot(T x ,char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
int k, n, m;

void solve() {
	rd(k), rd(n), rd(m);
	if (k > n * m) return ot(0), void();
	int mn = min(n, m), mx = max(n, m);
	if (mn == 1 or k == n * m or k == 1 or k == 2) return ot(1), void();
	if (k == 3) {
		ot(2);
	} else if (k == 4) {
		int res = 1;
		if (mx >= 4) res ++;
		if (mx >= 3) res += 3;
		ot(res);
	} else if (k == 5) {
		int res = 0;
		if (mx >= 5) res ++;
		if (mn >= 2 and mx >= 4) res += 3;
		if (mn >= 2 and mx >= 3) res += 2;
		if (mn >= 3 and mx >= 3) res += 6;
		ot(res);
	}
}

int main() {
	int t; rd(t);
	while (t --) solve();
	return 0;
}
