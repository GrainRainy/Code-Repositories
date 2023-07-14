#include <iostream>
#include <cstring>
#include <algorithm>

#define owo 0

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[16], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int a, p;

LL qpow(LL a, LL b, LL mod) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

inline void solve() {
	input(a), input(p);
	if (__gcd(a, p) != 1) return puts("impossible"), void();
	LL x = qpow(a, p - 2, p);
	return output((x % p + p) % p), void();
}

int main() {
	int t; input(t);
	while (t --) solve();
	return owo;
}
