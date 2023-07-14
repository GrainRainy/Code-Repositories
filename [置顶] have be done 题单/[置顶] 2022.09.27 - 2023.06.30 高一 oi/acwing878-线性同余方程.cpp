#include <iostream>
#include <cstring>
#include <algorithm>

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
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
	if (!b) { x = 1, y = 0; return a; }
	LL d = exgcd(b, a % b, x, y);
	LL tmp = x;
	x = y, y = tmp - a / b * y;
	return d;
}

LL x, y;
LL a, b, m;

inline void solve() {
	input(a), input(b), input(m);
	LL d = exgcd(a, m, x, y);
	if (b % d) return puts("impossible"), void();
	return output((LL)b / d * x % m), void();
}

int main(){
	int t; input(t);
	while (t --) solve();
	return 0;
}
