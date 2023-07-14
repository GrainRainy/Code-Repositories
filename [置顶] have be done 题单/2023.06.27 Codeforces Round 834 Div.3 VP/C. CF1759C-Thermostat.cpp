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

LL l, r, x, a, b; 

void solve() {
	input(l, r, x, a, b);
	if (a == b) return puts("0"), void();
	if (l > a - x and r < a + x) return puts("-1"), void();
	if (l > b - x and r < b + x) return puts("-1"), void();
	if (abs(a - b) >= x) return puts("1"), void();
	int ans = 0x3f3f3f3f;
	if (r - a >= x) 
		if (r - b >= x) ans = min(ans, 2);
		else ans = min(ans, 3);
	if (a - l >= x) 
		if (b - l >= x) ans = min(ans, 2);
		else ans = min(ans, 3);
	output(ans, '\n');
	return;
}

int main() {
	int t; input(t);
	while (t -- ) solve();
	return 0;
}
