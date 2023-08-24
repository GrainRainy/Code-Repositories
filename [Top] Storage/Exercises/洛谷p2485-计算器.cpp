#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <cmath>

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
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int t, k, y, z, p;

LL fpow(LL a, LL b, LL p) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

LL gcdx, gcdy;
LL exgcd(LL a, LL b, LL &gcdx, LL &gcdy) {
	if (!b) { gcdx = 1, gcdy = 0; return a; }
	LL gcd = exgcd(b, a % b, gcdx, gcdy);
	LL tmp = gcdx;
	gcdx = gcdy, gcdy = tmp - gcdy * (a / b);
	return gcd;
}

void BabyStepGiantStep(LL a, LL b, LL p) {
    unordered_map<int, int> hsh; hsh.clear();
    b %= p;
    int len = (int)sqrt(p) + 1;
    for (int i = 0, val = b; i < len; ++ i) {
        hsh[val] = i;
        val = (LL)val * a % p;
    }
    a = fpow(a, len, p);
	if (!a and !b) return output(1), void();
	if (!a and b) return puts("Orz, I cannot find x!"), void();
	
    for (int i = 1, val = a; i <= len; ++ i) {
        if (hsh.count(val)) return output((LL)i * len - hsh[val]), void();
        val = (LL)val * a % p;
    }
    return puts("Orz, I cannot find x!"), void();
}

inline void solve1() {
	input(y), input(z), input(p);
	output(fpow(y, z, p));
}

inline void solve2() {
	input(y), input(z), input(p);
	LL gcd = exgcd(y, p, gcdx, gcdy);
	if (z % gcd) return puts("Orz, I cannot find x!"), void();
	gcdx = (gcdx % (p / gcd) + (p /gcd)) %  (p / gcd);
	return output(gcdx * (z / gcd) % (p / gcd) + (p / gcd)% (p / gcd)) , void();
}

inline void solve3() {
	input(y), input(z), input(p);
	BabyStepGiantStep(y, z, p);
}

int main() {
	input(t), input(k);
	if (k == 1) while (t --) solve1();
	if (k == 2) while (t --) solve2();
	if (k == 3) while (t --) solve3();
	return owo;
}
