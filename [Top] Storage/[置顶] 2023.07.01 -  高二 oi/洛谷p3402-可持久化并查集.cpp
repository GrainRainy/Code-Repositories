#include <bits/stdc++.h>
#define __DEBUG__ puts("__DEBUG__");
#define debug(x) cout << #x << ' ' << x << endl;
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

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int LOGN = 18 + 2;
int n, m;
int rt[M], rtdep[M], rtfa[M], tot;
struct Tree {
	int l, r, val;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define val(x) tree[x].val
}tree[(N + M) * LOGN];

void build(int &u, int tl, int tr) {
	u = ++ tot;
	if (tl == tr) return val(u) = tl, void();
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
}

void modify(int &u, int pre, int tl, int tr, int pos, int val) {
	u = ++ tot; tree[u] = tree[pre];
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

int find(int ver, int x) {
	int tmp = query(rtfa[ver], 1, n, x);
	return x == tmp ? x : x = find(ver, tmp);
}

void merge(int now, int pre, int a, int b) {
	a = find(pre, a), b = find(pre, b);
	if (a == b) {
		rtfa[now] = rtfa[pre];
		rtdep[now] = rtdep[pre];
	} else {
		int depa = query(rtdep[pre], 1, n, a);
		int depb = query(rtdep[pre], 1, n, b);
		if (depa == depb) {
			modify(rtfa[now], rtfa[pre], 1, n, a, b);
			modify(rtdep[now], rtdep[pre], 1, n, b, depb + 1);
		} else {
			if (depa > depb) swap(depa, depb), swap(a, b);
			modify(rtfa[now], rtfa[pre], 1, n, a, b);
			rtdep[now] = rtdep[pre];
		}
	}
}

int main() {
	input(n), input(m);
	build(rtfa[0], 1, n);
	for (int i = 1, op, a, b; i <= m; ++ i) {
		input(op), input(a);
		if (op == 1) {
			input(b);
			merge(i, i - 1, a, b);
		} else if (op == 2) {
			rtfa[i] = rtfa[a];
			rtdep[i] = rtdep[a];
		} else if (op == 3) {
			input(b);
			rtfa[i] = rtfa[i - 1];
			rtdep[i] = rtdep[i - 1];
			puts(find(i, a) == find(i, b) ? "1" : "0");
		}
	}
	return 0;
}
