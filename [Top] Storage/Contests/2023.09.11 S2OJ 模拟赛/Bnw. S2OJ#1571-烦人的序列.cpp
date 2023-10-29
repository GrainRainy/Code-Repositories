#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, i, j, nw, mn = 0x3f3f3f3f, b[N];
bool pf[N], sf[N];

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
	for (i = 1, rd(n); i <= n; ++ i) rd(b[i]), mn = min(mn, b[i]);
	pf[0] = sf[n + 1] = true;
	for (i = 1, nw = 0x3f3f3f3f; i <= n; ++ i) {
		b[i] == mn ? pf[i] = pf[i - 1] : (pf[i] = pf[i - 1] & (b[i] <= nw), nw = b[i]);
		if (!pf[i]) break;
	}
	for (i = n, nw = 0x3f3f3f3f; i; -- i) {
		b[i] == mn ? sf[i] = sf[i + 1] : (sf[i] = sf[i + 1] & (b[i] <= nw), nw = b[i]);
		if (!sf[i]) break;
	}
	for (i = 1; i <= n; ++ i)
		if (b[i] == mn and pf[i - 1] and sf[i + 1]) {
			for (j = 1; j < i; ++ j) ot(b[j] == mn ? N : b[j], ' ');
			ot(b[i], ' ');
			for (j = i + 1; j <= n; ++ j) ot(b[j] == mn ? N : b[j], " \n"[j == n]);
			return 0;
		}
	return puts("cut_the_watermelon_with_a_hand") & 0;
}
