#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar())x = x * 10 + (c ^ '0');
		if (f) x = -x; 
	}
}

using IO::rd;
using namespace std;
const int N = 1e5 + 10;
int n, m, p, ori[N];
struct Sort { bool op; int l, r; }q[N];
struct SegmentTree {
	int cnt, tag;
	#define ls(u) ((u) << 1)
	#define rs(u) ((u) << 1 | 1)
	#define cnt(x) tree[x].cnt
	#define tag(x) tree[x].tag
}tree[N << 2];

inline void pushUp(int u) {
	cnt(u) = cnt(ls(u)) + cnt(rs(u));
}

inline void pushDown(int u, int tl, int tr) {
	if (!tag(u)) return;
	int mid = tl + tr >> 1;
	tag(ls(u)) = tag(rs(u)) = tag(u);
	if (tag(u) == 1) cnt(ls(u)) = mid - tl + 1, cnt(rs(u)) = tr - mid;
	else cnt(ls(u)) = cnt(rs(u)) = 0;
	tag(u) = 0;
	return;
}

void build(int u, int tl, int tr, int val) {
	tag(u) = 0;
	if (tl == tr) return cnt(u) = (int)(ori[tl] >= val), void();
	int mid = tl + tr >> 1;
	build(ls(u), tl, mid, val), build(rs(u), mid + 1, tr, val);
	pushUp(u);
}

int query(int u, int tl, int tr, int l, int r) {
	if (tl > r or tr < l) return 0;
	if (tl >= l and tr <= r) return cnt(u);
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	return query(ls(u), tl, mid, l, r) + query(rs(u), mid + 1, tr, l, r);
}

void cover(int u, int tl, int tr, int l, int r, bool op) {
	if (tl > r or tr < l) return;
	if (tl >= l and tr <= r) {
		if (op) cnt(u) = tr - tl + 1, tag(u) = 1;
		else cnt(u) = 0, tag(u) = 2; 
		return;
	}
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1;
	cover(ls(u), tl, mid, l, r, op), cover(rs(u), mid + 1, tr, l, r, op);
	pushUp(u);
}

void Sort(int l, int r, bool op) {
	int cnt = query(1, 1, n, l, r);
	if (op) cover(1, 1, n, l, l + cnt - 1, 1), cover(1, 1, n, l + cnt, r, 0);
	else cover(1, 1, n, l, r - cnt, 0), cover(1, 1, n, r - cnt + 1, r, 1);
	return;
}

bool check(int u) {
	build(1, 1, n, u);
	for (int i = 1; i <= m; ++ i) Sort(q[i].l, q[i].r, q[i].op);
	return query(1, 1, n, p, p);
}

int main() {
//	freopen("sort.in", "r", stdin);
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i) rd(ori[i]);
	for (int i = 1, op, l, r; i <= m; ++ i)
		rd(op), rd(l), rd(r), q[i] = {(bool)op, l, r};
	rd(p);
	int l = 1, r = n, mid;
	while (l < r) {
		mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	return printf("%d\n", l), 0;
}
