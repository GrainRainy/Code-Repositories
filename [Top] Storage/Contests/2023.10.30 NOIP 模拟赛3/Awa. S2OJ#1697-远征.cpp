#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 5e4 + 10;
int n, q, mx, a[N];
LL sm[N], ans;
struct SegmentTree {
	int pos;
	struct Node {
		int c, p[2];
		Node operator + (const Node &t) const {
			Node res;
			if (c >= 2) res.p[0] = p[0], res.p[1] = p[1];
			else if (c) res.p[0] = p[0], res.p[1] = t.p[0];
			else res.p[0] = t.p[0], res.p[1] = t.p[1];
			res.c = c + t.c;
			return res;
		}
	}tree[N << 2];
	#define c(x) tree[x].c
	#define p(x, y) tree[x].p[y]
	#define l(u) ((u) << 1)
	#define r(u) ((u) << 1 | 1)
	void build(int u, int tl, int tr) {
		if (tl == tr) {
			if ((a[tl] >> pos) & 1) c(u) = 1, p(u, 0) = tl, p(u, 1) = n + 1;
			else c(u) = 0, p(u, 0) = p(u, 1) = n + 1;
			return;
		}
		int mid = tl + tr >> 1;
		build(l(u), tl, mid), build(r(u), mid + 1, tr);
		tree[u] = tree[l(u)] + tree[r(u)];
	}
	Node query(int u, int tl, int tr, int l, int r) {
		if (tl > r or tr < l) return {0, {0, 0}};
		if (l <= tl and tr <= r) return tree[u];
		int mid = tl + tr >> 1;
		return query(l(u), tl, mid, l, r) + query(r(u), mid + 1, tr, l, r);
	}
}sg[15];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) rd(a[i]);
	for (int i = 0; i < 10; ++ i) sg[i].pos = i, sg[i].build(1, 1, n);
	for (int i = 1; i <= n; ++ i) rd(sm[i]), sm[i] += sm[i - 1];
	rd(q);
	for (int i = 1, l, r, x, mnp; i <= q; ++ i) {
		rd(l), rd(r), rd(x), mnp = n;
		for (int j = 0; j < 10; ++ j) 
			mnp = min(mnp, sg[j].query(1, 1, n, l, r).p[(x >> j) & 1] - 1);
		ans ^= sm[mnp] - sm[l - 1];
	}
	return cout << ans << '\n', 0;
}
