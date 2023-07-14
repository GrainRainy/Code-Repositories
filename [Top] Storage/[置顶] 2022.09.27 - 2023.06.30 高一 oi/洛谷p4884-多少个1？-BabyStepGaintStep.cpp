#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>

#define owo 0

using namespace std;
using BIGI = __int128;

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

BIGI k, m;
map<BIGI, BIGI> hsh;

BIGI qpow(BIGI a, BIGI b, BIGI m) {
	BIGI res = 1;
	while (b) {
		if (b & 1) res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

BIGI BabyStepGiantStep(BIGI a, BIGI b, BIGI m) {
	if (a == 0) return b == 0 ? 1 : -1;
	hsh.clear();
	b = (b % m + m) % m;
	BIGI len = (BIGI)sqrt((double)m) + 1;
	for (int j = 0; j < len; ++ j) {
		BIGI val = b * qpow(a, j, m) % m;
		hsh[val] = j;
	}
	a = qpow(a, len, m);
	for (int i = 0; i <= len; ++ i) {
		BIGI val = qpow(a, i, m);
		BIGI j = hsh.find(val) == hsh.end() ? -1 : hsh[val];
		if (j >= 0 and i * len - j >= 0) return i * len - j;
	}
	return -1;
}

int main() {
	input(k), input(m);
	k = (k * 9 + 1) % m;
	return output(BabyStepGiantStep(10, k, m)), owo;
}
