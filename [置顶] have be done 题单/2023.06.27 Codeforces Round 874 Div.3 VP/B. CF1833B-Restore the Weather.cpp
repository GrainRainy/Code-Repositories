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

const int N = 1e5 + 10;
int n, ans[N], k;
PII a[N]; int b[N];

void solve() {
	input(n, k);
	for (int i = 1, tmp; i <= n; ++ i) input(tmp), a[i] = {tmp, i};
	for (int i = 1; i <= n; ++ i) input(b[i]);
	sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; ++ i) ans[a[i].se] = b[i];
	for (int i = 1; i <= n; ++ i) output(ans[i], " \n"[i == n]);
}

int main() {
	int t; input(t);
	while (t -- ) solve();
	return 0;
}
