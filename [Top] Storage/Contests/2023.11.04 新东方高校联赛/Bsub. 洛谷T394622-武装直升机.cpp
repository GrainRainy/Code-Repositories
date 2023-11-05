#include <bits/stdc++.h>
namespace fastio {
	const int MAXBUF = 1 << 23;
	char buf[MAXBUF], *p1 = buf, *p2 = buf;
	char pbuf[MAXBUF], *pp = pbuf;
	inline char getc() {
		return (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, MAXBUF, stdin)), p1 == p2 ? EOF : *p1++;
	}
	inline void putc(char c) {
		(pp == pbuf + MAXBUF) && (fwrite(pbuf, 1, MAXBUF, stdout), pp = pbuf), *pp++ = c;
	}
	inline void print_final() {
		fwrite(pbuf, 1, pp - pbuf, stdout), pp = pbuf;
	}
}
using namespace std;
using namespace fastio;
const int N = 1e6 + 10;
int n, k, a[N], f[N];
int mx[N], mxt, mn[N], mnt;

template <class _Tp> inline _Tp& rd(_Tp& x) {
	x = 0; bool sign = 0; char ch = getc();
	for (; !isdigit(ch); ch = getc()) sign |= (ch == '-');
	for (x = 0; isdigit(ch); ch = getc()) x = x * 10 + (ch ^ 48);
	return sign ? (x = -x) : x;
}
template <class _Tp> inline void ot(_Tp x, char ed = '\n') {
	if (x < 0) putc('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putc(st[top --] | '0');
	putc(ed); 
}

int main() {
	rd(n), rd(k);
	if (k == 1) {
		for (int i = 1; i <= n; ++ i) ot(0);
		return print_final(), 0;
	}
	for (int i = 1; i <= n; ++ i) {
		rd(a[i]), a[i] ^= f[i - 1];
		while (mxt and a[mx[mxt]] < a[i]) mxt --;
		while (mnt and a[mn[mnt]] > a[i]) mnt --;
		mx[++ mxt] = i, mn[++ mnt] = i;
		if (i < k) { ot(0); continue; }
		f[i] = a[mx[1]] - a[mn[1]];
		for (int j = k, xp = 1, np = 1; j <= i - k; ++ j) {
			while (mx[xp] <= j) xp ++;
			while (mn[np] <= j) np ++;
			f[i] = min(f[i], max(f[j], a[mx[xp]] - a[mn[np]]));
		}
		ot(f[i]);
	}
	return print_final(), 0;
}
