#include <iostream>
#include <cstring>
#include <algorithm>

#define owo 0

using namespace std;
using LL = long long;

const LL MOD = 19260817;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 % MOD + (c ^ '0');
	if (f) x = -x;
}

LL a, b, x, y;

LL exgcd(LL a, LL b, LL &x, LL &y) {
	if (!b) { x = 1, y = 0; return a; }
	LL d = exgcd(b, a % b, x, y);
	LL tmp = x;
	x = y, y = tmp - y * (a / b);
	return d;
}

int main() {
	input(a), input(b);
	if (!b) return puts("Angry!"), owo;
	
	LL d = exgcd(b, MOD, x, y);
	cout << (x % MOD + MOD) % MOD * a % MOD << endl;
	return owo;
}
