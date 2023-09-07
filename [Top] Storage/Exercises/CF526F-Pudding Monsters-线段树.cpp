#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}
using namespace std;
const int N = 3e5 + 10;
int n, a[N], mxstk[N], mxt, mnstk[N], mnt;
long long ans;
struct SegmentTree {
	int mn, tg, cnt;
	SegmentTree operator + (const SegmentTree &t) const {
		SegmentTree ans = {0, 0, 0};
		ans.mn = min(mn, t.mn);
		ans.cnt = (ans.mn == mn ? cnt : 0) + (ans.mn == t.mn ? t.cnt : 0);
		return ans;
	}
	#define l(x) ((x) << 1)
	#define r(x) ((x) << 1 | 1)
	#define mn(x) tree[x].mn
	#define tg(x) tree[x].tg
	#define cnt(x) tree[x].cnt
}tree[N << 2];

void build(int u, int tl, int tr) {
	if (tl == tr) return cnt(u) = 1, void();
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
	tree[u] = tree[l(u)] + tree[r(u)];
}

inline void add(int u, int val) { mn(u) += val, tg(u) += val; }
void modify(int u, int tl, int tr, int l, int r, int val) {
	if (tl >= l and tr <= r) return add(u, val), void();
	int mid = tl + tr >> 1;
	if (tg(u)) add(l(u), tg(u)), add(r(u), tg(u)), tg(u) = 0;
	if (l <= mid) modify(l(u), tl, mid, l, r, val);
	if (r > mid) modify(r(u), mid + 1, tr, l, r, val);
	tree[u] = tree[l(u)] + tree[r(u)];
}

int main() {
	rd(n), build(1, 1, n);
	for (int i = 1, x, y; i <= n; ++ i) rd(x), rd(y), a[x] = y;
	for (int i = 1; i <= n; ++ i) {
		while (mxt and a[mxstk[mxt]] < a[i]) modify(1, 1, n, mxstk[mxt - 1] + 1, mxstk[mxt], -a[mxstk[mxt]]), mxt --;
		while (mnt and a[mnstk[mnt]] > a[i]) modify(1, 1, n, mnstk[mnt - 1] + 1, mnstk[mnt], a[mnstk[mnt]]), mnt --;
		modify(1, 1, n, mxstk[mxt] + 1, i, a[i]), mxstk[++ mxt] = i;
		modify(1, 1, n, mnstk[mnt] + 1, i, -a[i]), mnstk[++ mnt] = i;
		modify(1, 1, n, 1, i, -1);
		ans += cnt(1);
	} 
	return cout << ans << '\n', 0;
}
