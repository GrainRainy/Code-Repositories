#include <bits/stdc++.h>
inline void rd(int &x) {
	x = 0; char c = getchar();
	while (c < '0') c = getchar();
	for (; c >= '0'; c = getchar()) x = x * 10 + (c ^ '0');
}
const int MOD = 1e9 + 7;
int n, mx, cnt = 1, ans;
bool st[200010];

inline void upd(int &x, int y) { x += y; (x >= MOD) and (x -= MOD); }
int main() {
	rd(n);
	for (int i = 1, l, r; i <= n; ++ i)
		rd(l), rd(r), st[l] = true;
	for (int i = 1; i <= n << 1; ++ i)
		st[i] ? upd(ans, ans), upd(ans, cnt) : upd(cnt, cnt);
	return printf("%d\n", ans), 0;
}
