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
LL n, st, ed, rate[N];
LL ans, change;

void solve() {
	input(n), input(st), input(ed);
	ans = 0, change = -n;
	for (int i = 1; i <= n; ++ i) input(rate[i]), rate[i] = min(rate[i], ed);
	sort(rate + 1, rate + n + 1);
	for (int i = 1; i <= n; ++ i) {
		if (st < rate[i]) {
			if (change <= 0) return puts("-1"), void();
			LL round = (rate[i] - st + change - 1) / change;
			ans += round * n, st += round * change;
		}
		if (rate[i] == ed) break;
		ans += 1, change += 2, st ++;
	}
	return output(ans + ed - st), void();
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}

