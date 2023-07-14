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
}

using namespace IO;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

const int N = 1e5 + 10;
LL n, m, x[N], y[N], deltax, deltay;

int main() {
	input(n, m);
	for (int i = 1; i <= n; ++ i) input(x[i], y[i]);
	for (int i = 1, op, tmpx, tmpy; i <= m; ++ i) {
		input(op, tmpx);
		if (op == 1) {
			input(tmpy);
			deltax += tmpx, deltay += tmpy;
		} else if (op == 2) {
			x[tmpx] += deltax, y[tmpx] +=  deltay;
			swap(x[tmpx], y[tmpx]);
			x[tmpx] -= deltax, y[tmpx] -= deltay;
		} else {
			output(x[tmpx] + deltax, ' '), output(y[tmpx] + deltay, '\n');
		}
	}
	return 0;
}
