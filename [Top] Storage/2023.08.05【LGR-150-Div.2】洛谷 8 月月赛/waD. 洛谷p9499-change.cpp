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
using INT = __int128;
const int N = 2e5 + 10;
const int MOD = 998244353;
int sid, t, n;
int v[N], c[N], x[N];
int ans;

inline void upd(int &x, int y) {
	x += y; (x >= MOD) and (x -= MOD);
}

namespace sub1{
	void solve() {
		input(n);
		for (int i = 1; i <= n; ++ i) input(v[i]);
		for (int i = 1; i <= n; ++ i) input(c[i]);
		for (int i = 1; i < n; ++ i) input(x[i]);
		for (int i = 1; i <= n; ++ i) {
			if ((LL)v[i] * x[i] <= v[i + 1] and i < n)
				c[i + 1] += c[i] / x[i], c[i] %= x[i];
			upd(ans, (LL)c[i] * v[i] % MOD);
		}
		output(ans, '\n');
		ans = 0;
	}
}

namespace sub2 {
	int suf[N];
	void solve() {
		input(n);
		for (int i = 1; i <= n; ++ i) input(v[i]);
		for (int i = 1; i <= n; ++ i) input(c[i]);
		for (int i = 1; i < n; ++ i) input(x[i]);
		for (int i = n; i; -- i) suf[i] = max(suf[i + 1], v[i]);
		int cnt = 0;
		for (int i = 1; i <= n; ++ i) {
			upd(cnt, c[i]);
			if (suf[i] != suf[i + 1])
				upd(ans, (LL)v[i] * cnt % MOD), cnt = 0;
		}
		output(ans, '\n');
		ans = 0;
		for (int i = 1; i <= n; ++ i) suf[i] = 0;
	}
}

namespace sub3 {
	const int M = 2e3 + 10;
	INT dp[M][M];
	void solve() {
		memset(dp, 0, sizeof dp);
		input(n);
		for (int i = 1; i <= n; ++ i) input(v[i]);
		for (int i = 1; i <= n; ++ i) input(c[i]);
		for (int i = 1; i < n; ++ i) input(x[i]);
		for (int i = 1; i <= n; ++ i) {
			for (int a = 0; a <= c[i - 1] / x[i - 1]; ++ a)
				for (int b = 0; b <= c[i] / x[i]; ++ b) {
					dp[i][b] = max(dp[i][b], dp[i - 1][a] - v[i - 1] * b + v[i] * (b + c[i]));
				}
		}
		INT res = 0;
		for (int i = 1; i <= c[n - 1] / x[n - 1]; ++ i)
			res = max(res, dp[n][i]);
		output(res % MOD, '\n');
	}
}

int main() {
	input(sid), input(t);
	if (sid == 2) while (t --) sub2::solve();
	if (sid == 1 or sid == 3) while (t --) sub1::solve();
	if (sid == 4 or sid == 5) while (t --) sub3::solve();
	return 0;
}
