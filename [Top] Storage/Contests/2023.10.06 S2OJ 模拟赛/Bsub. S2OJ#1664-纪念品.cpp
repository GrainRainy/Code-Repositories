#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, ps[N], as[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int main() {
	rd(n), rd(m);
	for (int i = 1, l, r; i <= n; ++ i) {
		rd(l), rd(r);
		ps[1] ++, ps[r - l + 1] --;
		for (int j = r - l + 1; j <= m; ++ j)
			if (ceil(l * 1.0 / j) * j <= r) as[j] ++;
	}
	for (int i = 1; i <= m; ++ i) 
		ps[i] += ps[i - 1], ot(ps[i] + as[i]);
	return 0;
}
