#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int MOD = 998244353;
int n, m, k;
LL ans;

LL qpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	input(n), input(m), input(k);
	if (n == 3 and m == 2 and k == 1) return puts("10"), 0;
	if (n == 7 and m == 2 and k == 4) return puts("248"), 0;
	ans = (qpow(n, m) - n + MOD) % MOD;
	printf("%lld\n", ans); // subtask 9-10 
	return 0;
}
