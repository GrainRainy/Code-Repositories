#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;

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
	void input(T &x, Args&... args) { input(x), input(args...); }
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
	template <typename T, typename ...Args>
	void output(T x, char ch = ' ', Args... args) {
		output(x, ch); output(args...);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int N = 1e3 + 10;
const int M = 5e5 + 10;
int n, q, cnt;
int ans[M];
PII a[N * N + M];

bool cmp(PII a, PII b) {
	if (a.fi ^ b.fi) return a.fi < b.fi;
	return a.se > b.se;
}

int main() {
	input(n), input(q);
	cnt = n * n;
	for (int i = 1, tmp; i <= cnt; ++ i) 
		input(tmp), a[i] = {tmp, 0};
	for (int i = 1, v; i <= q; ++ i)
		input(v), a[i + cnt] = {v, i};
	sort(a + 1, a + cnt + q + 1, cmp);
	for (int i = 1; i <= n * n + q; ++ i) {
		if (!a[i].se) cnt --;
		else ans[a[i].se] = cnt;
	}
	for (int i = 1; i <= q; ++ i) output(min(ans[i], n), '\n');
	return 0;
}
