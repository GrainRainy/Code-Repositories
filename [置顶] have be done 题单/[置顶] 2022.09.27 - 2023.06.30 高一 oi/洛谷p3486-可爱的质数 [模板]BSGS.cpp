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

int p, b, n;

LL qpow(int a, int b, int p) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = (LL)a * a % p;
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
	input(p), input(b), input(n);
	int ans = BabyStepGiantStep(b, n, p);
	if (ans == -1) return puts("no solution"), owo;
	return cout << ans << endl, owo;
}
