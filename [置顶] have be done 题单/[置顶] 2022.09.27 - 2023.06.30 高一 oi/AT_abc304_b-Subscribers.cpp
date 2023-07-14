#include <bits/stdc++.h>

#define enter putchar('\n')
#define FI first
#define SE second

namespace IO {
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
}

using namespace std;
using namespace IO;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

int n;

int main() {
	input(n);
	if (n <= 1e3 - 1) output(n);
	if (n >= 1e3 and n <= 1e4 - 1) n /= 10, n *= 10, output(n);
	if (n >= 1e4 and n <= 1e5 - 1) n /= 100, n *= 100, output(n);
	if (n >= 1e5 and n <= 1e6 - 1) n /= 1000, n *= 1000, output(n);
	if (n >= 1e6 and n <= 1e7 - 1) n /= 10000, n *= 10000, output(n);
	if (n >= 1e7 and n <= 1e8 - 1) n /= 100000, n *= 100000, output(n);
	if (n >= 1e8 and n <= 1e9 - 1) n /= 1000000, n *= 1000000, output(n);
	return 0;
}
