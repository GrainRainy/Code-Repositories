#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int M = 1e5 + 10;
int n, m, res, pos = 1;
struct Range {
	int l, r;
	bool operator < (const Range &t) const { return r - l < t.r - t.l; }
}p[N];

struct Fenwick {
	int tr[M];
	inline void add(int p, int v) { while (p <= m) tr[p] += v, p += p & -p; }
	int query(int r) { int res = 0; while (r) res += tr[r], r -= r & -r; return res; }
}t;

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

int main() {
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i) rd(p[i].l), rd(p[i].r);
	sort(p + 1, p + n + 1);
	for (int d = 1; d <= m; ++ d) {
		while (pos <= n and p[pos].r - p[pos].l + 1 <= d)
			t.add(p[pos].l, 1), t.add(p[pos].r + 1, -1), pos ++;
		res = n - pos + 1;
		for (int i = d; i <= m; i += d) res += t.query(i);
		ot(res);
	}
	return 0;
}
