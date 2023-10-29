#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 30;
int n, m, q, l, r, nxt[N][M], f[20][N], ans;
char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> m >> n >> s + 1;
	for (int i = 0; i < 26; ++ i) nxt[n + 1][i] = n + 1;
	for (int i = n; i; -- i) {
		memcpy(nxt[i], nxt[i + 1], 4 * m);
		nxt[i][s[i] - 'a'] = i;
		f[0][i] = *max_element(nxt[i], nxt[i] + m) + 1;
	}
	f[0][n + 1] = f[0][n + 2] = n + 2;
	for (int i = 1; i <= 18; ++ i)
		for (int j = 1; j <= n + 2; ++ j)
			f[i][j] = f[i - 1][f[i - 1][j]];
	cin >> q;
	while (q --) {
		cin >> l >> r, ans = 0;
		for (int i = 18; ~i; -- i)
			if (f[i][l] <= r + 1) l = f[i][l], ans += 1 << i;
		cout << ans + 1 << '\n';
	}
	return 0;
}
