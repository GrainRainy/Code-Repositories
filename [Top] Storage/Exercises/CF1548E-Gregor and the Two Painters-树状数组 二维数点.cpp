#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, x, i, a[N], b[N], sa[N], sb[N];
int mna[N], mnb[N], stk[N], mx[N], tp; 
long long ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

struct Fenwick {
	int tr[N];
	inline void add(int p, int v) { while (p <= x) tr[p] += v, p += p & -p; }
	int qry(int p) { int r = 0; while (p) r += tr[p], p -= p & -p; return r; }
}t;

int main() {
	rd(n), rd(m), rd(x);
	for (i = 1; i <= n; ++ i) rd(a[i]), sa[i] = i, mna[i] = x, a[i] = min(a[i], x);
	for (i = 1; i <= m; ++ i) rd(b[i]), sb[i] = i, mnb[i] = x, b[i] = min(b[i], x);
	for (mx[tp = 0] = x, i = 1; i <= n; ++ i) {
		while (tp and a[stk[tp]] > a[i]) tp --, mx[tp] = max(mx[tp], mx[tp + 1]);
		mna[i] = min(mna[i], max(mx[tp], a[i])), stk[++ tp] = i, mx[tp] = a[i];
	}
	for (tp = 0, i = n; i; -- i) {
		while (tp and a[stk[tp]] >= a[i]) tp --, mx[tp] = max(mx[tp], mx[tp + 1]);
		mna[i] = min(mna[i], max(mx[tp], a[i])), stk[++ tp] = i, mx[tp] = a[i];
	}
	for (tp = 0, i = 1; i <= m; ++ i) {
		while (tp and b[stk[tp]] > b[i]) tp --, mx[tp] = max(mx[tp], mx[tp + 1]);
		mnb[i] = min(mnb[i], max(mx[tp], b[i])), stk[++ tp] = i, mx[tp] = b[i];
	}
	for (tp = 0, i = m; i; -- i) {
		while (tp and b[stk[tp]] >= b[i]) tp --, mx[tp] = max(mx[tp], mx[tp + 1]);
		mnb[i] = min(mnb[i], max(mx[tp], b[i])), stk[++ tp] = i, mx[tp] = b[i];
	}
	sort(sa + 1, sa + n + 1, [](int &x, int &y) { return a[x] < a[y]; });
	sort(sb + 1, sb + m + 1, [](int &x, int &y) { return mnb[x] > mnb[y]; });
	for (int i = 1, j = 1; i <= n; ++ i) {
		while (j <= m and mnb[sb[j]] > x - a[sa[i]]) t.add(b[sb[j ++]], 1);
		ans += t.qry(x - a[sa[i]]) - t.qry(x - mna[sa[i]]);
	}
	return cout << ans << '\n', 0;
}
