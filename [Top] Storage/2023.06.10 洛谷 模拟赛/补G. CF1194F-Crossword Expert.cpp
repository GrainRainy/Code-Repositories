#include <iostream>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace IO;
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;
LL n, t;
LL ary[N], sum[N], g = 1, ans;
LL f[N], fact[N], p2[N];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

LL C(int n, int m) {
	return n < m ? 0 : fact[n] * qpow(fact[m], MOD - 2) % MOD * qpow(fact[n - m], MOD - 2) % MOD;
}

int main() {
	input(n), input(t);
	fact[0] = p2[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		input(ary[i]), sum[i] = sum[i - 1] + ary[i];
		f[i] = min((LL)i, t - sum[i]);
		fact[i] = fact[i - 1] * i % MOD;
		p2[i] = (p2[i - 1] << 1) % MOD;
	}
	for (int i = 1; i <= n; ++ i) {
		if (f[i] < 0) break;
		g = (g << 1) - C(i - 1, f[i - 1]) % MOD;
		if (f[i - 1] < f[i]) 
			for (int j = f[i - 1] + 1; j <= f[i]; ++ j) g = (g + C(i, j)) % MOD;
		if (f[i - 1] > f[i]) 
			for (int j = f[i] + 1; j <= f[i - 1]; ++ j) g = (g - C(i, j)) % MOD;
		ans = (ans + p2[n - i] * g % MOD) % MOD;
	}
	cout << (ans * qpow(p2[n], MOD - 2) % MOD + MOD) % MOD << endl;
	return 0;
}
