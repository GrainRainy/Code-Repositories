#include <bits/stdc++.h>

#define enter putchar('\n')
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

const int N = 2e5 + 10;
int w, h, n, ta, tb;
int q[N], p[N], a[N], b[N];
map<PLL, LL> mp;

int main() {
	input(w, h, n);
	for (int i = 1; i <= n; ++ i) input(q[i], p[i]);
	input(ta); for (int i = 1; i <= ta; ++ i) input(a[i]);
	input(tb); for (int i = 1; i <= tb; ++ i) input(b[i]);
	for (int i = 1, tmpx, tmpy; i <= n; ++ i) {
		tmpx = *lower_bound(a + 1, a + ta + 1, q[i]);
		tmpy = *lower_bound(b + 1, b + tb + 1, p[i]);
		mp[{tmpx, tmpy}] ++;
	}
	LL mx = 0, mn = n;
	for (auto t : mp) mx = max(mx, t.se);
	if (mp.size() < (ta + 1) * (tb + 1)) mn = 0;
	else for (auto t : mp) mn = min(mn, t.se);
	output(mn, ' ', mx, '\n');
	return 0;
}
