#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <ctime>

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
	if (x < 0) return puts("No Solution"), void();
	static short st[32], top = 0;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

LL a, b, p, val;

LL qpow(LL a, LL b, LL p) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

int BabyStepGiantStep(int a, int b, int p) {
	if (a == 0) return b == 0 ? 1 : -1;
	unordered_map<int, int> hsh;
	b %= p;
	int len = (int)sqrt(p) + 1;
	for (int i = 0, val = b; i < len; ++ i) {
		hsh[val] = i;
		val = (LL)val * a % p;
	}
	a = qpow(a, len, p);
	
	for (int i = 1, val = a; i <= len; ++ i) {
		if (hsh.count(val)) return (LL)i * len - hsh[val];
		val = (LL)val * a % p;
	}
	return -1;
}

int main() {
	input(a), input(p), input(b);
	while (a and b and p) {
		output(BabyStepGiantStep(a, b, p));
		input(a), input(p), input(b);
	}
	return owo;
}
