#include <bits/stdc++.h>
template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}
template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}
using namespace std;
const int N = 2e5 + 10;
int n, m, h[N], s[N], t[N], tr[N], ans[N], top;
struct Query {
	int h, tl, tr, val;
	bool operator < (Query &t) const { return h ^ t.h ? h < t.h : val < t.val; }
}q[N << 2];

inline void add(int x, int v) { while (x <= m) tr[x] += v, x += x & -x; }
int query(int r) { int v = 0; while (r) v += tr[r], r -= r & -r; return v; }
inline void ins(int l, int r, int tl, int tr) {
	if (l < r and tl < tr) q[++ top] = {l + 1, tl, tr, -1}, q[++ top] = {r + 1, tl, tr, -3};
}

int main() {
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i) rd(h[i]), t[i] = 1;
	for (int i = 1, x, y; i <= m; ++ i) {
		if (rd(s[i]), s[i] == 2) {
			rd(x), rd(y);
			ins(h[x - 1], h[x], t[x], i), ins(h[x], h[x + 1], t[x + 1], i);
			h[x] = y, t[x] = t[x + 1] = i;
		} else rd(x), q[++ top] = {x, i, 0, i};
	}
	for (int i = 1; i <= n; ++ i) ins(h[i - 1], h[i], t[i], m + 1);
	sort(q + 1, q + top + 1);
	for (int i = 1; i <= top; ++ i) {
		if (q[i].val < 0) add(q[i].tl, q[i].val + 2), add(q[i].tr, -q[i].val - 2);
		else ans[q[i].val] = query(q[i].tl);
	}
	for (int i = 1; i <= m; ++ i) if (s[i] == 1) ot(ans[i]);
	return 0;
}
