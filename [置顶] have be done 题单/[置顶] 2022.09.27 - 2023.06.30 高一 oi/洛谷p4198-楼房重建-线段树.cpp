#include <iostream>
#include <cstring>
#include <algorithm>

#define lson ((u) << 1)
#define rson ((u) << 1 | 1)

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
const int N = 1e5 + 10;
int n, m;
struct SegmentTree {
	int len; double mx;
	#define len(x) tree[x].len
	#define mx(x) tree[x].mx
}tree[N << 2];

int query(int u, int tl, int tr, double lim) {
	if (mx(u) <= lim) return 0;
	if (tl == tr) return mx(u) > lim;
	int mid = tl + tr >> 1;
	if (mx(lson) <= lim) return query(rson, mid + 1, tr, lim);
	else return query(lson, tl, mid, lim) + len(u) - len(lson);
}

void modify(int u, int tl, int tr, int pos, double val) {
	if (tl == tr) return mx(u) = val, len(u) = 1, void();
	int mid = tl + tr >> 1;
	if (pos <= mid) modify(lson, tl, mid, pos, val);
	else modify(rson, mid + 1, tr, pos, val);
	mx(u) = max(mx(lson), mx(rson));
	len(u) = len(lson) + query(rson, mid + 1, tr, mx(lson));
}

int main() {
	input(n), input(m);
	for (int i = 1, x, y; i <= m; ++ i) {
		input(x), input(y);
		modify(1, 1, n, x, (double)y / x);
		output(len(1));
	}
	return 0;
}
