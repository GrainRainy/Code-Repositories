#include <bits/stdc++.h>
#define fi first
#define se second
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';

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
		static short st[30], top;
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

const int N = 1e5 + 10;
int n, m, d;
int pos[N], ori[N];
map<LL, int> mp;
LL cnt, mx;

void solve() {
	rd(n), rd(m), rd(d);
	mx = cnt = 0; mp.clear();
	for (int i = 1; i <= m; ++ i) rd(pos[i]);
	pos[0] = 1, pos[m + 1] = n + 1;
	cnt += ori[0] = (pos[1] - 2) / d + (pos[1] != 1);
	for (int i = 1; i <= m; ++ i) {
		ori[i] = (pos[i + 1] - pos[i] - 1) / d + 1;
		LL del = (pos[i + 1] - pos[i - 1] - 1) / d + 1;
		cnt += ori[i];
		mp[ori[i] + ori[i - 1] - del] = mp[ori[i] + ori[i - 1] - del] + 1;
	}
	for (auto t : mp) mx = max(mx, t.fi);
	ot(cnt - mx, ' '), ot(mp[mx], '\n');
	return;
}

int main() {
//	freopen("test.out", "w", stdout);
	int t; rd(t);
	while (t -- ) solve();
	return 0;
}
