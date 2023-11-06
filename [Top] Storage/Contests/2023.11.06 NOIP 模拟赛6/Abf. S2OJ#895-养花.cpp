#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e5 + 10;
const int SN = 320 + 3;
const int LN = 20 + 3;
int n, m, mx, sa, ln, st[LN][N];
vector<int> pos[SN][SN];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

inline int qry(int l, int r) {
	int k = log2(r - l + 1);
	return max(st[k][l], st[k][r - (1 << k) + 1]);
}

int main() {
//	freopen("data.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i) 
		rd(st[0][i]), mx = max(mx, st[0][i]);
	sa = 300, ln = log2(n);
	for (int j = 1; j <= ln; ++ j)
		for (int i = 1; i + (1 << j) <= n; ++ i)
			st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
	for (int i = 1; i <= n; ++ i)
		for (int j = 2; j <= sa; ++ j)
			pos[j][st[0][i] % j].emplace_back(i);
	for (int i = 1, l, r, k; i <= m; ++ i) {
		rd(l), rd(r), rd(k);
		if (k == 1) ot(0);
		else if (k > mx) ot(mx);
		else if (k <= sa) {
			for (int j = k - 1; ~j; -- j) {
				auto itl = lower_bound(pos[k][j].begin(), pos[k][j].end(), l);
				auto itr = upper_bound(pos[k][j].begin(), pos[k][j].end(), r);
				if (itl != itr) { ot(j); break; }
			}
		} else {
			int res = 0;
			for (int j = l; j <= r; ++ j) {
				res = max(res, st[0][j] % k);
				if (res == k - 1) break;
			}
			ot(res);
		}
	}
	return 0;
}
