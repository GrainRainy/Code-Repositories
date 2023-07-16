#include <bits/stdc++.h>
#define enter putchar('\n')
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
const int N = 200 + 10;
int n, m, k;
int f[N][N], l[N][N], u[N][N];
// x, z /    y, z    / x, y
int main() {
	input(n), input(m), input(k);
	for (int a = 1, x; a <= k; ++ a)
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= m; ++ j) {
				input(x); // i, j, a     j, a, i
				f[a][i] |= x, u[m - j + 1][i] |= x, l[k - a + 1][m - j + 1] |= x;
			}
	for (int i = k; i; -- i, puts(""))
		for (int j = 1; j <= n; ++ j)
			output(f[i][j], ' ');
	for (int i = 1; i <= k; ++ i, puts(""))
		for (int j = 1; j <= m; ++ j)
			output(l[i][j], ' ');
	for (int i = 1; i <= m; ++ i, puts(""))
		for (int j = 1; j <= n; ++ j)
			output(u[i][j], ' ');
	return 0;
}
