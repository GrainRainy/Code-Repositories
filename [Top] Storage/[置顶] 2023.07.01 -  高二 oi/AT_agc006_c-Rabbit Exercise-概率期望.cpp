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
const int N = 1e5 + 10;
int n, m, x[N], tmp[N], ans[N], d[N];
LL ot[N], k;

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(x[i]), d[i] = ans[i] = i;
	input(m), input(k);
	for (int i = 1, x; i <= m; ++ i) input(x), swap(d[x], d[x + 1]);
	while (k) {
		if (k & 1) {
			for (int i = 1; i <= n; ++ i) tmp[i] = ans[d[i]];
			for (int i = 1; i <= n; ++ i) ans[i] = tmp[i];
		}
		for (int i = 1; i <= n; ++ i) tmp[i] = d[d[i]];
		for (int i = 1; i <= n; ++ i) d[i] = tmp[i];
		k >>= 1;
	}
	for (int i = 1; i <= n; ++ i) ot[i] = x[ans[i]] - x[ans[i] - 1];
	for (int i = 1; i <= n; ++ i) output(ot[i] += ot[i - 1], '.'), putchar('0'), putchar('\n');
	return 0;
}
