#include <bits/stdc++.h>

#define __DEBUG__ puts("__DEBUG__");
#define enter putchar('\n')
#define endl '\n'
#define fi first
#define se second

namespace IO {
	#ifdef __LINUX__
	#define getchar() getchar_unlocked()
	#define putchar(a) putchar_unlocked(a)
	#endif
	
	#ifdef __WINDOWS__
	#define getchar() _getchar_nolock()
	#define putchar(a) _putchar_nolock()
	#endif
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar(); bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T, typename... Args> 
	void input(T &x, Args&... args) {
		input(x), input(args...);
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
	template <typename T, typename ...Args>
	void output(T x, char ch = ' ', Args... args) {
		output(x, ch);
		output(args...);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

const LL MOD = 998244353;
LL l, r;
LL mul = 1;
bool f = false;

bool check(LL x) {
	LL res = 0;
	while (x) res += x % 10, x /= 10;
	for (LL i = 2; i * i <= res; ++ i) {
		if (res % i == 0) return false;
	}
	return true;
}

LL qmul(LL x, LL y){
	LL z = (double)x / MOD * y;
	LL res = (ULL) x * y - (ULL)z * MOD;
	return (res % MOD + MOD) % MOD;
}

int main() {
	input(l), input(r);
	for (LL i = 2; i <= 1000000; ++ i) {
		LL val = i * i;
		if (l <= val and r >= val and check(val)) {
			f = true;
			mul = qmul(mul, val);
		}
		if (val > r) break;
	}
	if (!f) puts("0");
	else output(mul, '\n');
	return 0;
}
