#include <bits/stdc++.h>
#define enter putchar('\n')

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar(); bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T, typename... Args> void input(T &x, Args&... args) {
	input(x), input(args...);
}
template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 2e5 + 10;
const LL MOD = 1e9 + 7;
LL n, k;
LL fact[N];
LL ans, tmp;

void InitFact() {
	fact[0] = 1;
	for (int i = 1; i <= N; i ++) {
		fact[i] = fact[i - 1] * i % MOD;
	}
}

LL qpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		res = b & 1 ? res * a % MOD : res;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

LL inv(LL a) {
	return qpow(a, MOD - 2);
}

LL C(LL n, LL m) { // n > m 
	return fact[n] * inv(fact[n - m]) % MOD * inv(fact[m]) % MOD;
}

void solve() {
	ans = 0, tmp = 0;
	input(n, k);
	
	for (int i = 0; i < n; i += 2) tmp = (tmp + C(n, i)) % MOD;
	if (n & 1) ans = (ans + qpow(tmp + 1, k)) % MOD;
	// equal
	else {
		for (int i = 0; i < k; i ++) 
			ans = (ans + qpow(tmp, i) * qpow(qpow(2, n), k - i - 1) % MOD) % MOD;
		ans = (ans + qpow(tmp, k)) % MOD;
	}

	output(ans);
	// not equal 
}

int main() {
	InitFact();
	
	int t; input(t);
	while (t --) solve();
	return 0;
}
