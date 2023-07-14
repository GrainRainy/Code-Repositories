#include <iostream>
#include <cstring>
#include <algorithm>

#define owo 0

using namespace std;
using LL = long long;
using ULL = unsigned long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

LL n, m, l;
LL x, y;

LL fmul(LL a, LL b, LL p) {
	LL z = (double) a / p * b;
	LL res = (ULL)a * b - (ULL) z * p;
	return (res % p + p) % p;
}

LL fpow(LL a, LL b, LL p) {
	LL res = 1;
	while (b) {
		if (b & 1) res = fmul(res, a, p);
		a = fmul(a, a, p);
		b >>= 1;
	}
	return res;
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
	if (!b) { x = 1, y = 0; return a; }
	LL gcd = exgcd(b, a % b, x, y);
	LL tmp = x;
	x = y, y = tmp - y * (a / b);
	return gcd;
}

int main() {
	input(n), input(m), input(l);
	exgcd(2, n + 1, x, y);
	x = (x % (n + 1) + (n + 1)) % (n + 1);
	cout << fmul(l, fpow(x, m, n + 1), n + 1) << '\n';
	return owo;
}
