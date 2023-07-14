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

const int N = 1e5 + 10;
int n, m, p;
LL fact[N];

LL fpow(LL a, LL b, int p) {
	a %= p;
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

inline LL inv(LL n, int p){
	return fpow(n, p - 2, p) % p;
}

inline LL C(LL n, LL m, int p) {
	if (m > n) return 0;
	return (fact[n] * inv(fact[m], p) % p * inv(fact[n - m], p) % p); 
}

LL Lucas(LL n, LL m, int p) {
	if (!m) return 1;
	return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

inline void solve() {
	input(n), input(m), input(p);
	for (int i = 1; i <= p; i ++) {
		fact[i] = fact[i - 1] * i % p;
	}
	return cout << Lucas(n + m, n, p) << '\n', void();
}

int main() {
	fact[0] = 1;
	int t; input(t);
	while (t --) solve();
	return 0;
}
