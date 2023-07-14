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

LL a, b, k, r, c;

int main() {
	cin >> a >> b >> k >> r >> c;
	cout << (b - a) * k * r - (b - a) * k * c << endl;
	return 0;
}
