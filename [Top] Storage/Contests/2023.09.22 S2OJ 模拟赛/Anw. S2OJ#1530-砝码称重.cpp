/* 本地极限数据 4~5 秒左右，出题人放我过吧 qwq */
#include <bits/stdc++.h>
#define l(u) ((u) << 1)
#define r(u) ((u) << 1 | 1)
#define mid (tl + tr >> 1)
using namespace std;
const int N = 1e6 + 10;
const int M = 1e5 + 10;
int n, q, m, a[N], mp[20], top;
unordered_map<int, int> st;
bitset<M> dp[(1 << 10) + 5]; 
struct Query { int op, l, r, x; }qs[N];
struct SegmentTree { short s, tg; }tree[N << 2];
#define s(u) tree[u].s
#define tg(u) tree[u].tg

#ifdef __LINUX__
#define getchar() getchar_unlocked()
#endif

#ifdef __WINDOWS__
#define getchar() _getchar_nolock()
#endif

inline void rd(int &x) {
	x = 0; char c = getchar();
	while (c < '0' or c > '9') c = getchar();
	for (; c >= '0' and c <= '9'; c = getchar()) x = x * 10 + (c ^ '0');
}

inline void build(int u, int tl, int tr) {
	if (tl == tr) return s(u) = 1 << st[a[tl]] - 1, void();
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
	s(u) = s(l(u)) | s(r(u));
}

inline short query(int u, int tl, int tr, int l, int r) {
	if (l <= tl and tr <= r) return s(u);
	if (tg(u)) s(l(u)) = s(r(u)) = tg(l(u)) = tg(r(u)) = tg(u), tg(u) = 0;
	if (r <= mid) return query(l(u), tl, mid, l, r);
	else if (l > mid) return query(r(u), mid + 1, tr, l, r);
	else return query(l(u), tl, mid, l, r) | query(r(u), mid + 1, tr, l, r);
}

inline void cover(int u, int tl, int tr, int l, int r, short val) {
	if (l <= tl and tr <= r) return s(u) = tg(u) = val, void();
	if (tg(u)) s(l(u)) = s(r(u)) = tg(l(u)) = tg(r(u)) = tg(u), tg(u) = 0;
	if (l <= mid) cover(l(u), tl, mid, l, r, val);
	if (r > mid) cover(r(u), mid + 1, tr, l, r, val);
	s(u) = s(l(u)) | s(r(u));
}

inline void solve(int s) {
	dp[s][0] = 1;
	for (int i = 1; i <= top; ++ i) 
		if ((s >> i - 1) & 1) for (int j = 0; j + mp[i] <= m; ++ j)
			dp[s][j + mp[i]] = dp[s][j + mp[i]] | dp[s][j];
}

int main() {
	rd(n), rd(m), rd(q);
	for (int i = 1; i <= n; ++ i) {
		rd(a[i]);
		if (st.find(a[i]) == st.end()) mp[++ top] = a[i], st[a[i]] = top;
	}
	for (int i = 1; i <= q; ++ i) {
		rd(qs[i].op), rd(qs[i].l), rd(qs[i].r), rd(qs[i].x);
		if (st.find(qs[i].x) == st.end()) mp[++ top] = qs[i].x, st[qs[i].x] = top;
	}
	build(1, 1, n);
	m = *max_element(mp + 1, mp + top + 1);
	for (int i = 1, s; i <= q; ++ i) {
		if (qs[i].op == 1) cover(1, 1, n, qs[i].l, qs[i].r, 1 << st[qs[i].x] - 1);
		else {
			if (!dp[s = query(1, 1, n, qs[i].l, qs[i].r)][0]) solve(s);
			puts(dp[s][qs[i].x] ? "Yes" : "No");
		}
	}
	return 0;
}

