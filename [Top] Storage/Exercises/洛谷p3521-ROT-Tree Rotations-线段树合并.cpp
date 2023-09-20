#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
const int LOGN = 19;
int n, val, top;
LL ans, u, v;
struct SegmentTree {
	int l, r, siz;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define siz(x) tree[x].siz
}tree[N * LOGN];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int insert(int tl, int tr, int pos) {
	int u = ++ top;
	siz(u) ++;
	if (tl == tr) return u;
	int mid = tl + tr >> 1;
	if (pos <= mid) l(u) = insert(tl, mid, pos);
	else r(u) = insert(mid + 1, tr, pos);
	return u;
}

int merge(int x, int y, int tl, int tr) {
	if (!x or !y) return x | y;
	if (tl == tr) return siz(x) += siz(y), x;
	u += (LL)siz(r(x)) * siz(l(y)), v += (LL)siz(l(x)) * siz(r(y));
	int mid = tl + tr >> 1;
	l(x) = merge(l(x), l(y), tl, mid);
	r(x) = merge(r(x), r(y), mid + 1, tr);
	siz(x) += siz(y);
	return x;
}

int dfs() {
	rd(val);
	if (!val) {
		int l = dfs(), r = dfs();
		u = v = 0;
		int tmp = merge(l, r, 1, n);
		ans += min(u, v);
		return tmp;
	} else return insert(1, n, val);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	rd(n), dfs();
	return cout << ans << '\n', 0;
}
