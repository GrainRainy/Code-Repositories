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
		x = x* 10 + (c ^ '0');
	if (f) x = -x;
} 

LL exgcd(LL a, LL b, LL &x, LL &y) {
	if (!b) { x = 1, y = 0; return a; }
	LL gcd = exgcd(b, a % b, x, y);
	LL tmp = x;
	x = y, y = tmp - y * (a / b);
	return gcd;
}

LL fmul(LL a, LL b, LL p) {
	LL z = (double) a / p * b;
	LL res = (ULL)a * b - (ULL)z * p;
	return (res % p + p) % p;
}

const int N = 15;
int k, a[N], b[N];
LL mul = 1, ans, mod, x, y;

int main() {
	input(k);
	
	for (int i = 1; i <= k; ++ i) input(a[i]);
	for (int i = 1; i <= k; ++ i) {
		input(b[i]);
		mul = mul * b[i];
	}
	
	for (int i = 1; i <= k; ++ i) {
		LL mod = mul / b[i];
		exgcd(mod, b[i], x, y);
		x = (x % b[i] + b[i]) % b[i];
		ans += fmul(fmul(a[i], mod, mul), x, mul);
	}
	
	cout << (ans % mul + mul) % mul << '\n';
	return owo;
}
