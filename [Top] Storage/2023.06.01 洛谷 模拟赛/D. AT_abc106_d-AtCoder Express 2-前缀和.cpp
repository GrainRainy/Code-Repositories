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

using namespace std;
using namespace IO;
using LL = long long;

const int N = 600;
LL n, m, q;
LL gph[N][N];
// basis 
LL tmpl, tmpr;

int main() {
	input(n), input(m), input(q);
	for (int i = 1; i <= m; ++ i) {
		input(tmpl), input(tmpr);
		gph[n - tmpl + 1][tmpr] += 1;
	}
	for (int i = 1; i <= n; ++ i) 
		for (int j = 1; j <= n; ++ j)
			gph[i][j] += gph[i][j - 1] + gph[i - 1][j] - gph[i - 1][j - 1];
	while (q --) {
		input(tmpl), input(tmpr);
		output(gph[n - tmpl + 1][tmpr]);
	}
	return 0;
}

