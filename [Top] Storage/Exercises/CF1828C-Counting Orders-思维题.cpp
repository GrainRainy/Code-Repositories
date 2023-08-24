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
using LL = long long;

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;
int n, a[N], b[N];
LL ans;

void solve() {
	input(n); ans = 1;
	for (int i = 1; i <= n; ++ i) input(a[i]);
	for (int i = 1; i <= n; ++ i) input(b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1, pos; i <= n; ++ i) {
		pos = lower_bound(b + 1, b + 1 + n, a[i]) - 1 - b;
		if (pos < i) return puts("0"), void();
		ans = ans * (pos - i + 1) % MOD;
	}
	return output(ans), void();
}

int main() {
	int t; input(t);
	while (t --) solve();
}
