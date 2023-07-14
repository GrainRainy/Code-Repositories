#include <iostream>
#include <cstring>
#include <algorithm>

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

LL mul(LL a, LL b, LL p) {
	LL tmp = (double)a / p * b;
	LL res = (ULL)a * b - (ULL)tmp * p;
	return (res + p) % p;
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
	if (!b) { x = 1, y = 0; return a;}
	LL d = exgcd(b, a % b, x, y);
	LL tmp = x;
	x = y, y = tmp - y * (a / b);
	return d;
}

LL n, a, b, x, y;
LL ans, mod;
LL ai[10], bi[10];

int main() {
	input(n);
	input(mod), input(ans);
	for (int i = 2; i <= n; ++ i) {
		input(a), input(b);
		LL c = (b - ans % a + a) % a;
		LL gcd = exgcd(mod, a, x, y), ag = a / gcd;
		if (c % gcd) return puts("-1"), 0;
		
		x = mul(x, c / gcd, ag);
		ans += x * mod;
		mod *= ag;
		ans = (ans % mod + mod) % mod;
	}
	cout << (ans % mod + mod) % mod << endl;
	return 0;
}
