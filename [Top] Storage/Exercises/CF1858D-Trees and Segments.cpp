#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 3e3 + 10;
int n, k, f[N][N], g[N][N], ans[N], pre[N];
char s[N];

template <typename T> inline void ot(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

void solve() {
	cin >> n >> k >> s + 1;
	memset(ans, -1, sizeof(int) * (n + 10)), pre[0] = 0;
	for (int i = 1; i <= n; ++ i) pre[i] = pre[i - 1] + s[i] - '0';
	for (int i = 0; i <= n + 1; ++ i)
		for (int j = 0; j <= k + 1; ++ j)
			f[i][j] = 0, g[i][j] = 0;
	for (int i = n, cnt; i; -- i) {
		cnt = 0;
		for (int j = i; j <= n and cnt <= k; ++ j) cnt += s[j] == '0', f[i][cnt] = j - i + 1;
		for (int j = 0; j <= cnt; ++ j) f[i][j] = max(f[i][j], f[i + 1][j]);
	}
	for (int i = 1, cnt; i <= n; ++ i) {
		cnt = 0;
		for (int j = i; j and cnt <= k; -- j) cnt += s[j] == '0', g[i][cnt] = i - j + 1;
		for (int j = 0; j <= cnt; ++ j) g[i][j] = max(g[i][j], g[i - 1][j]);
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = i - 1, res; j <= n; ++ j)
			if (k >= (res = pre[j] - pre[i - 1]))
				ans[j - i + 1] = max(ans[j - i + 1], max(f[j + 1][k - res], g[i - 1][k - res]));
	for (int i = 1, res; i <= n; ++ i) {
		res = 0;
		for (int j = 0; j <= n; ++ j) 
			if (ans[j] != -1) res = max(res, ans[j] + i * j);
		ot(res, " \n"[i == n]);
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
