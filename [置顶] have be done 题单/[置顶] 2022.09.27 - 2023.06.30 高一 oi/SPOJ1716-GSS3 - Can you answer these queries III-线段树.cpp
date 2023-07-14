#include <iostream>
#include <cstring>
#include <algorithm>

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

#define lson (u << 1)
#define rson (u << 1 | 1)

const int N = 5e4 + 10;
int n, q, op, x, y;
int ary[N];
struct segmentTree {
	int sum, mx, pre, suf;
	#define sum(x) tree[x].sum
	#define mx(x) tree[x].mx
	#define pre(x) tree[x].pre
	#define suf(x) tree[x].suf
	segmentTree operator + (const segmentTree &t) const {
		segmentTree ans;
		ans.sum = sum + t.sum;
		ans.mx = max({mx, t.mx, suf + t.pre});
		ans.pre = max(pre, sum + t.pre);
		ans.suf = max(t.suf, suf + t.sum);
		return ans;
	}
}tree[N << 2];

void build(int u, int tl, int tr) {
	if (tl == tr) return sum(u) = mx(u) = pre(u) = suf(u) = ary[tl], void();
	int mid = tl + tr >> 1;
	build(lson, tl, mid), build(rson, mid + 1, tr);
	tree[u] = tree[lson] + tree[rson];
}

void modify(int u, int tl, int tr, int pos, int val) {
	if (tl == tr) return sum(u) = mx(u) = pre(u) = suf(u) = val, void();
	int mid = tl + tr >> 1;
	if (pos <= mid) modify(lson, tl, mid, pos, val);
	else modify(rson, mid + 1, tr, pos, val);
	tree[u] = tree[lson] + tree[rson];
	return;
}

segmentTree query(int u, int tl, int tr, int l, int r) {
	if (tl >= l and tr <= r) return tree[u];
	int mid = tl + tr >> 1;
	if (l > mid) return query(rson, mid + 1, tr, l, r);
	if (r <= mid) return query(lson, tl, mid, l, r);
	return query(lson, tl, mid, l, r) + query(rson, mid + 1, tr, l, r);
}

void print(int u, int tl, int tr) {
	output(u, ' '), output(tl, ' '), output(tr, ' ');
	output(sum(u), ' '), output(pre(u), ' '), output(suf(u), ' '), output(mx(u), ' ');
	puts("");
	if (tl == tr) return;
	int mid = tl + tr >> 1;
	print(lson, tl, mid), print(rson, mid + 1, tr);
}

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(ary[i]);
	build(1, 1, n);
	input(q);
	while (q --) {
		input(op), input(x), input(y);
		if (!op) modify(1, 1, n, x, y);
		else output(query(1, 1, n, x, y).mx);
	}
//	cout << "u tl tr sum pre suf mx" << endl;
//	print(1, 1, n);
	return 0;
}
