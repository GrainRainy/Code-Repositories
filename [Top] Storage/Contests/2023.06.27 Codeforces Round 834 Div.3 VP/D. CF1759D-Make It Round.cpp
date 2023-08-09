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

const int N = 2e5 + 10;
LL n, m, cnt, pos;
LL a[N], cg, cb;

void update(LL &m, LL a) {
	if (m > a) return;
	if (cg and m * 2 > a) m *= 2, cg --;
	else if (cb and m * 3 > a) m *= 3, cb --;
	else if (cg == 2 and m * 4 > a) m *= 4, cg -= 2;
	else if (cg and cb and m * 6 > a) m *= 6, cg --, cb --;
	else if (cg == 2 and cb and m * 12 > a) m *= 12, cg -= 2, cb --;
}

void solve() {
	input(n, m); pos = cnt = 0, cg = 2, cb = 1;
	for (int i = 1; i <= n; ++ i) {
		input(a[++ pos]);
		if (a[pos] == 1) pos --;
	}
	cnt = n - pos, n = pos;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++ i) {
		update(m, a[i]);
		if (m <= a[i]) break;
		m += a[i] / 2, cnt ++;
	}
	output(cnt, '\n');
	return;
}

int main() {
	int t; input(t);
	while (t -- ) solve();
	return 0;
}
