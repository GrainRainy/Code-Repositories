#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;

const int N = 1e6 + 10;
const int LOGN = 24;
int n, m, a[N];
int rt[N * LOGN], idx;
struct SegmentTree {
	int l, r, val;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define val(x) tree[x].val
}tree[N * LOGN];

void build(int &u, int tl, int tr) {
	u = ++ idx;
	if (tl == tr) return val(u) = a[tl], void();
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
} 

void modify(int &u, int pre, int tl, int tr, int pos, int val) {
	u = ++ idx; tree[u] = tree[pre];
	if (tl == tr) return val(u) = val, void();
	int mid = tl + tr >> 1;
	if (pos <= mid) modify(l(u), l(pre), tl, mid, pos, val);
	else modify(r(u), r(pre), mid + 1, tr, pos, val);
}

int query(int u, int tl, int tr, int pos) {
	if (tl == tr) return val(u);
	int mid = tl + tr >> 1;
	if (pos <= mid) return query(l(u), tl, mid, pos);
	else return query(r(u), mid + 1, tr, pos);
}

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) input(a[i]);
	build(rt[0], 1, n);
	for (int i = 1, ver, op, pos, val; i <= m; ++ i) {
		input(ver), input(op), input(pos);
		if (op == 1) {
			input(val);
			modify(rt[i], rt[ver], 1, n, pos, val);
		} else {
			rt[i] = rt[ver];
			output(query(rt[ver], 1, n, pos));
		}
	}
	return 0;
}
