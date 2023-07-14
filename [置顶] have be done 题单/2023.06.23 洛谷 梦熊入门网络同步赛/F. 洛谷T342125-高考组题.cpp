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

int n, k;
struct Node {
	double val; int id;
	bool operator < (const Node &t) const {
		if (fabs(val - t.val) < 1e-8) return id < t.id;
		return val > t.val;
	}
}ary[1000];

int main() {
	input(n), input(k);
	for (int i = 1; i <= n; ++ i) {
		double tmp;
		ary[i].id = i;
		for (int j = 1; j <= k; ++ j) {
			input(tmp);
			ary[i].val += tmp / k;
		}
	}
	sort(ary + 1, ary + 1 + n);
	output(ary[1].id);
	output(ary[2].id);
	return 0;
}

