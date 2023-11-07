#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 3e5 + 10;
const int LN = 20;
int n, m, mx, col[N], rt[N], ttp;
struct SegmentTree {
	int l, r, cnt;
	#define l(u) tree[u].l
	#define r(u) tree[u].r
	#define cnt(x) tree[x].cnt
}tree[N * LN * 3];

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

void mfy(int pre, int &u, int tl, int tr, int p, int v) {
	u = ++ ttp, tree[u] = tree[pre];
	if (tl == tr) return cnt(u) += v, void();
	int mid = tl + tr >> 1;
	if (p <= mid) mfy(l(pre), l(u), tl, mid, p, v);
	else mfy(r(pre), r(u), mid + 1, tr, p, v);
}

int qry(int pre, int u, int tl, int tr, int p) {
	if (tl == tr) return cnt(u) - cnt(pre);
	int mid = tl + tr >> 1;
	if (p <= mid) return qry(l(pre), l(u), tl, mid, p);
	else return qry(r(pre), r(u), mid + 1, tr, p);
}

int main() {
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i) rd(col[i]), mx = max(mx, col[i]);
	for (int i = 1; i <= n; ++ i) mfy(rt[i - 1], rt[i], 1, mx, col[i], 1);
	for (int i = 1, op, l, r, x; i <= m; ++ i) {
		rd(op);
		if (op == 1) {
			rd(l), rd(r), rd(x);
			if (x > mx) ot(0);
			else ot(qry(rt[l - 1], rt[r], 1, mx, x));
		} else {
			rd(x), swap(col[x], col[x + 1]);
			mfy(rt[x], rt[x], 1, mx, col[x + 1], -1), mfy(rt[x], rt[x], 1, mx, col[x], 1);
		}
	}
	return 0;
}
