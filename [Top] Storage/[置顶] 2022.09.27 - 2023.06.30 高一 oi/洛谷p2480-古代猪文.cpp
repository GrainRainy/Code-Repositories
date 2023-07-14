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
		x =x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 4e4 + 10;
const int MOD = 999911658;
LL n, g, ans;
int a[5], b[5] = {0, 2, 3, 4679, 35617};
LL fact[5][N];


LL fastPow(LL a, LL b, LL p) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

inline LL inv(int n, int p) {
	return fastPow(n, p - 2, p);
}

inline LL C(int n, int m, int idx) {
	if (m > n) return 0;
	return fact[idx][n] * inv(fact[idx][m], b[idx]) % b[idx] * inv(fact[idx][n - m], b[idx]) % b[idx];
}

LL Lucas(int n, int m, int idx) {
	if (!m) return 1;
	return C(n % b[idx], m % b[idx], idx) * Lucas(n / b[idx], m / b[idx], idx) % b[idx];
}

void init() {
	for (int i = 1; i <= 5; ++ i) fact[i][0] = 1;
	for (int i = 1; i <= 5; ++ i) {
		for (int j = 1; j <= b[i]; ++ j) {
			fact[i][j] = fact[i][j - 1] * j % b[i];
		}
	}
}

LL crt() {
	for (int i = 1; i <= 4; ++ i) {
		ans = (ans + a[i] * (MOD / b[i]) % MOD * inv(MOD / b[i], b[i])) % MOD;
	}
	return ans;
}

int main() {
	input(n), input(g);
	init();
	if (g == 999911659) return putchar('0'), owo;
	
	for (int i = 1; i <= n / i; ++ i) {
		if (n % i == 0) {
			for (int j = 1; j <= 4; ++ j) {
				a[j] = (a[j] + Lucas(n, i, j)) % b[j];
			}
			if (i != n / i) {
				for (int j = 1; j <= 4; ++ j) {
					a[j] = (a[j] + Lucas(n, n / i, j)) % b[j];
				}
			}
		}
	}
	return printf("%lld", fastPow(g, crt(), MOD + 1)), owo;
}
