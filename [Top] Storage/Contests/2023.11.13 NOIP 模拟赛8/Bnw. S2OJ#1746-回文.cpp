#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 3e5 + 10;
const int LN = 19 + 3;
char s[N], t[N << 1];
int n, m, mx, q, st[LN][N << 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s + 1, n = strlen(s + 1);
	t[m = 0] = '$', t[++ m] = '#';
	for (int i = 1; i <= n; ++ i) t[++ m] = s[i], t[++ m] = '#';
	t[++ m] = '^', mx = log2(m) + 1;
	for (int i = 1, mid = 0, mr = 0; i <= m; ++ i) {
		st[0][i] = i < mr ? min(st[0][(mid << 1) - i], mr - i) : 1;
		while (t[i + st[0][i]] == t[i - st[0][i]]) st[0][i] ++;
		if (i + st[0][i] > mr) mid = i, mr = i + st[0][i];
	}
	for (int i = 1; i <= m; ++ i) st[0][i] --;
	for (int i = 1; i <= mx; ++ i)
		for (int j = 1; j + (1 << i) <= m; ++ j)
			st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	cin >> q;
	for (int i = 1, ql, qr, mid, l, r, k; i <= q; ++ i) {
		cin >> ql >> qr, ++ ql, ++ qr, ql <<= 1, qr <<= 1, l = 1, r = qr - ql + 2 >> 1;
		while (l < r) {
			mid = l + r + 1 >> 1, k = log2(qr - ql - (mid << 1) + 3);
			if (max(st[k][ql + mid - 1], st[k][qr - mid + 1 - (1 << k) + 1]) >= mid) l = mid;
			else r = mid - 1;
		}
		cout << l << '\n';
	}
	return 0;
}
