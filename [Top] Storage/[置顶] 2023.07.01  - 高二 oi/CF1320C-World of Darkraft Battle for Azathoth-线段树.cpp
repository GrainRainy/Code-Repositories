#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using IO::input;
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
const int INF = 2e9 + 10;
int n, m, p, ans = -INF, tmp[N];
struct Item {
	int val, c;
	bool operator < (const Item &t) const { return val < t.val; }
}a[N], b[N];
struct Monsters {
	int x, y, w;
	bool operator < (const Monsters &t) const { return x < t.x; }
}mt[N];
struct SegmentTree {
	int mx, tag;
	#define l(u) ((u) << 1)
	#define r(u) ((u) << 1 | 1)
	#define mx(x) tree[x].mx
	#define tag(x) tree[x].tag
}tree[N << 2];

inline void pushUp(int u) {
	mx(u) = max(mx(l(u)), mx(r(u)));
}

inline void pushDown(int u) {
	if (!tag(u)) return;
	mx(l(u)) += tag(u), mx(r(u)) += tag(u);
	tag(l(u)) += tag(u), tag(r(u)) += tag(u);
	tag(u) = 0;
}

void build(int u, int tl, int tr) {
	if (tl == tr) return mx(u) = -b[tl].c, void();
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
	pushUp(u);
}

void modify(int u, int tl, int tr, int l, int r, int val) {
	if (tl >= l and tr <= r) return mx(u) += val, tag(u) += val, void();
	pushDown(u);
	int mid = tl + tr >> 1;
	if (l <= mid) modify(l(u), tl, mid, l, r, val);
	if (r > mid) modify(r(u), mid + 1, tr, l, r, val);
	pushUp(u);
}

void killed(int id) {
	int pos = upper_bound(tmp + 1, tmp + m + 1, mt[id].y) - tmp;
	if (pos <= m) modify(1, 1, m, pos, m, mt[id].w);
}

signed main() {
	input(n), input(m), input(p);
	for (int i = 1; i <= n; ++ i) input(a[i].val), input(a[i].c);
	for (int i = 1; i <= m; ++ i) input(b[i].val), input(b[i].c);
	for (int i = 1; i <= p; ++ i) input(mt[i].x), input(mt[i].y), input(mt[i].w);
	sort(a + 1, a + n + 1), sort(b + 1, b + m + 1), sort(mt + 1, mt + p + 1);
	for (int i = 1; i <= m; ++ i) tmp[i] = b[i].val;
	build(1, 1, m);
	for (int i = 1, j = 1; i <= n; ++ i) {
		while (mt[j].x < a[i].val and j <= p) killed(j ++);
		ans = max(ans, mx(1) - a[i].c);
	}
	return printf("%d\n", ans), 0;
}
