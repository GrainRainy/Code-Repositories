#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int M = 1e4 + 10;
const int LM = 15;
int n, c, m, rt[N], ttp;
struct SegmentTree {
	int l, r, c;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define c(x) tree[x].c
}tree[N * LM];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

void ins(int pre, int &u, int tl, int tr, int p) {
	u = ++ ttp, tree[u] = tree[pre];
	if (tl == tr) return c(u) ++, void();
	int mid = tl + tr >> 1;
	if (p <= mid) ins(l(pre), l(u), tl, mid, p);
	else ins(r(pre), r(u), mid + 1, tr, p);
	c(u) = c(l(u)) + c(r(u));
}

int qry(int pre, int u, int tl, int tr, int lim) {
	if (tl == tr) return tl;
	int mid = tl + tr >> 1;
	if (c(l(u)) - c(l(pre)) > lim) return qry(l(pre), l(u), tl, mid, lim);
	else if (c(r(u)) - c(r(pre)) > lim) return qry(r(pre), r(u), mid + 1, tr, lim);
	else return -1;
}

int main() {
	cout.tie(0)->sync_with_stdio(false);
	rd(n), rd(c);
	for (int i = 1, x; i <= n; ++ i) rd(x), ins(rt[i - 1], rt[i], 1, c, x);
	rd(m);
	for (int i = 1, l, r, t; i <= m; ++ i) {
		rd(l), rd(r), t = qry(rt[l - 1], rt[r], 1, c, r - l + 1 >> 1);
		if (~t) cout << "yes " << t << '\n';
		else cout << "no\n";
	}
	return 0;
}
