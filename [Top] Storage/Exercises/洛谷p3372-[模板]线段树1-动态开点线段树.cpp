#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
int n, m, op, x, y, k;
int root, cnt, lson[N << 1], rson[N << 1];
LL sum[N << 1], tag[N << 1];

void pushDown(int u, int tl, int tr) {
	if (!lson[u]) lson[u] = ++ cnt;
	if (!rson[u]) rson[u] = ++ cnt;
	tag[lson[u]] += tag[u], tag[rson[u]] += tag[u];
	int mid = tl + tr >> 1;
	sum[lson[u]] += tag[u] * (mid - tl + 1);
	sum[rson[u]] += tag[u] * (tr - mid);
	tag[u] = 0;
}

void modifyDot(int &u, int tl, int tr, int pos, int val) {
	if (!u) u = ++ cnt;
	sum[u] += val;
	if (tl == tr) return;
	int mid = tl + tr >> 1;
	if (pos <= mid) modifyDot(lson[u], tl, mid, pos, val);
	else modifyDot(rson[u], mid + 1, tr, pos, val);	
}

LL query(int u, int tl, int tr, int l, int r) {
	if (tl == l and tr == r) return sum[u];
	pushDown(u, tl, tr);
	int mid = tl + tr >> 1; LL res = 0;
	if (l <= mid) res += query(lson[u], tl, mid, l, min(mid, r));
	if (r > mid) res += query(rson[u], mid + 1, tr, max(mid + 1, l), r);
	return res;
}

void modifyRange(int &u, int tl, int tr, int l, int r, int val) {
	if (!u) u = ++ cnt;
	int len = min(tr, r) - max(tl, l) + 1;
	sum[u] += val * len;
	if (tl == l and tr == r) return tag[u] += val, void();
	int mid = tl + tr >> 1;
	if (l <= mid) modifyRange(lson[u], tl, mid, l, min(mid, r), val);
	if (r > mid) modifyRange(rson[u], mid + 1, tr, max(mid + 1, l), r, val);
}

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) {
		input(x);
		modifyDot(root, 1, n, i, x);
	}
	while (m --) {
		input(op), input(x), input(y);
		if (op == 1) input(k), modifyRange(root, 1, n, x, y, k);
		if (op == 2) output(query(root, 1, n, x, y));
	}
	return 0;
}
