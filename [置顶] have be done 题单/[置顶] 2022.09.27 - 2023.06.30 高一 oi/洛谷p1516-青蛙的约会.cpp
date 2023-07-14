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

LL x, y, m, n, l;
LL tmpx, tmpy;
LL gcd;

LL exgcd(LL a, LL b, LL &tmpx, LL &y) {
	if (!b) { tmpx = 1, tmpy = 0; return a;}
	gcd = exgcd(b, a % b, tmpx, tmpy);
	LL tmp = tmpx;
	tmpx = tmpy, tmpy = tmp - tmpy * (a / b);
	return gcd;
}

int main() {
	input(x), input(y), input(m), input(n), input(l);
	LL gro = m - n, grt = y - x;
	if (gro < 0) gro *= -1, grt *= -1;
	
	if (grt % exgcd(gro, l, tmpx, tmpy)) return puts("Impossible"), owo;
	cout << (tmpx  * (grt / gcd) % l + l) % l << '\n';
	
	return owo;
}
