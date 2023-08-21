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

const int N = 2e3 + 10;
int n, m;
char g[N][N];
bool mp[N][N];

int main() {
	rd(n, m);
	for (int i = 1; i <= n; ++ i) cin >> g[i] + 1;
	char c = 'a';
	for (int op = 0; op < 26; ++ op) {
		for (int i = 1; i <= n; ++ i)
			for (int j = 1, cnt = 0, prepos = 0; j <= m; ++ j)
				if (g[i][j] == (char)(c + op)) {
					cnt ++;
					if (cnt == 1) prepos = j;
					else mp[i][j] = true;
					if (cnt == 2) mp[i][prepos] = true;
				}
		for (int j = 1; j <= m; ++ j)
			for (int i = 1, cnt = 0, prepos = 0; i <= n; ++ i)
				if (g[i][j] == (char)(c + op)) {
					cnt ++;
					if (cnt == 1) prepos = i;
					else mp[i][j] = true;
					if (cnt == 2) mp[prepos][j] = true;
				}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			if (!mp[i][j]) cnt ++;
	ot(cnt, '\n');
	return 0;
}
