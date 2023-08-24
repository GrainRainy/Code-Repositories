#include <bits/stdc++.h>
#define fi first
#define se second
#define DEBUG cerr << "-- DEBUG --\n";

namespace IO {
	#ifdef __LINUX__
	#define getchar() getchar_unlocked()
	#define putchar(a) putchar_unlocked(a)
	#endif
	
	#ifdef __WINDOWS__
	#define getchar() _getchar_nolock()
	#define putchar(a) _putchar_nolock()
	#endif
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar(); bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T, typename... Args> 
	void rd(T &x, Args&... args) { rd(x), rd(args...); }
	template <typename T> inline void ot(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
	template <typename T, typename ...Args>
	void output(T x, char ch = ' ', Args... args) {
		ot(x, ch); ot(args...);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

template<typename Typ1> void debug(Typ1 a) { cerr << a << '\n'; }
template<typename Typ1, typename ...Typ2> void debug(Typ1 a, Typ2 ...arg) {
	cerr << a << " ", debug(arg...);
}

const int N = 3e5 + 10;
int n;
struct A {
	int f, s;
	bool operator < (const A &t) const {
		if (f ^ t.f) return f < t.f;
		return s > t.s;
	}
}a[N];

inline bool cmp(const A &x, const A &y) {
	return x.s > y.s;
}

LL ans;

int main() {
	rd(n);
	for (int i= 1; i <= n; ++ i) rd(a[i].f, a[i].s);
	sort(a + 1, a + n + 1, cmp);
	int pos = 2;
	while (a[pos].f == a[1].f) ++ pos;
	ans = a[1].s + a[pos].s;
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; ++ i) 
		ans = max(ans, (LL)a[i - 1].s + a[i].s / 2);
	ot(ans, '\n');
	return 0;
}
