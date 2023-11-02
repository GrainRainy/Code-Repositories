#include <bits/stdc++.h>
#ifdef __LINUX__
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked(a)
#endif

#ifdef __WINDOWS__
#define getchar() _getchar_nolock()
#define putchar(a) _putchar_nolock()
#endif
using namespace std;
const int N = 1e6 + 10;
const int K = 1e2 + 10;
const int MOD = 1e9 + 7;
int n, m, k, a[N];
int q[K][N], hd[K], tl[K], tmpa[K], tmpb[K];
int f[N], ans;

inline void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

void dfs(int pos) {
	if (pos == m + 1) {
		memset(f, 0, sizeof(int) * (n + m + 10));
		for (int i = 1; i <= k; ++ i) tmpa[i] = hd[i];
		for (int i = 1; i <= k; ++ i) tmpb[i] = tl[i];
		for (int i = n + 1; i <= n + m; ++ i) q[a[i]][++ tl[a[i]]] = i;
		for (int i = 1; i <= n + m; ++ i) {
			if (hd[a[i]] == 1) f[i] ++;
			hd[a[i]] ++;
			for (int j = 1; j <= k; ++ j)
				if (hd[j] <= tl[j]) upd(f[q[j][hd[j]]], f[i]);
		}
		int res = 0;
		for (int i = 1; i <= n + m; ++ i) upd(res, f[i]);
		ans = max(ans, res);
		for (int i = 1; i <= k; ++ i) hd[i] = tmpa[i];
		for (int i = 1; i <= k; ++ i) tl[i] = tmpb[i];
		return;
	}
	for (int i = 1; i <= k; ++ i) a[n + pos] = i, dfs(pos + 1);
}

int main() {
	rd(n), rd(m), rd(k);
	for (int i = 1; i <= k; ++ i) hd[i] = 1;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], q[a[i]][++ tl[a[i]]] = i;
	dfs(1);
	return cout << ans << '\n', 0;
}
