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
const int N = 2e5 + 10;
LL n, h, m, a[N], cnt2, cnt3, ans;

void solve() { 
	input(n), input(h); ans = 0;
	for (int i = 1; i <= n; ++ i) input(a[i]);
	sort(a + 1, a + 1 + n);
	for (int c = 0; c < 3; ++ c) {
		cnt2 = 2, cnt3 = 1, m = h;
		for (int i = 1; i <= n; ++ i) {
			while (m <= a[i]) {
				if (cnt2 == c and cnt3) m *= 3, cnt3 --;
				else if (cnt2) m *= 2, cnt2 --; 
				else break;
			} if (m <= a[i]) break;
			m += a[i] >> 1;
			ans = max(ans, (LL)i);
		}
	}
	output(ans);
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
} 
