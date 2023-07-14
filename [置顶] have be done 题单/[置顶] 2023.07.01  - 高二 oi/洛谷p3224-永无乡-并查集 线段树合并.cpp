#include <bits/stdc++.h>
#define DEBUG puts("__DEBUG__");
#define debug(x) cerr << #x << ' ' << x << endl;
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
const int LOGN = 18;
int n, m, q;
char op[10];
int fa[N], siz[N]; // dsu 
int rt[N], top;
struct SegmentTree {
	int s[2], cnt, id;
	#define l(x) tree[x].s[0]
	#define r(x) tree[x].s[1]
	#define id(x) tree[x].id 
	#define cnt(x) tree[x].cnt
}tree[N * LOGN << 2];

void pushUp(int u) { cnt(u) = cnt(l(u)) + cnt(r(u)); }

void modify(int &u, int tl, int tr, int pos, int id) {
	if (!u) u = ++ top;
	if (tl == tr) return cnt(u) ++, id(u) = id, void();
	int mid = tl + tr >> 1;
	if (pos <= mid) modify(l(u), tl, mid, pos, id);
	else modify(r(u), mid + 1, tr, pos, id);
	pushUp(u);
}

int query(int u, int tl, int tr, int k) {
//	DEBUG
//	debug(u) debug(tl) debug(tr) debug(cnt(u)) debug(k)
	if (cnt(u) < k) return -1;
	if (tl == tr) return id(u);
	int mid = tl + tr >> 1;
	if (k <= cnt(l(u))) return query(l(u), tl, mid, k);
	else return query(r(u), mid + 1, tr, k - cnt(l(u)));
}

int merge(int a, int b, int tl, int tr) {
	if (!a or !b) return a | b;
	if (tl == tr) return cnt(a) += cnt(b), id(a) = id(b), a;
	int mid = tl + tr >> 1;
	l(a) = merge(l(a), l(b), tl, mid);
	r(a) = merge(r(a), r(b), mid + 1, tr);
	pushUp(a);
	return a;
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void mergeDsu(int &a, int &b) {
	a = find(a), b = find(b);
	if (a == b) return;
	if (siz[a] < siz[b]) swap(a, b);
	fa[b] = a, siz[a] += siz[b];
	return;
}

int main() {
	input(n), input(m);
	for (int i = 1, tmp; i <= n; ++ i) {
		input(tmp);
		modify(rt[i], 1, n, tmp, i);
		fa[i] = i, siz[i] = 1;
	}
	
//	debug(query(rt[1], 1, n, 1))
//	DEBUG
//	debug(query(rt[2], 1, n, 1))
	
	for (int i = 1, a, b; i <= m; ++ i) {
		input(a), input(b);
		mergeDsu(a, b);
		rt[a] = rt[b] = merge(rt[a], rt[b], 1, n);
	}
	
//	for (int i = 1; i <= n; ++ i) debug(rt[i])
//	debug(cnt(rt[1]))
//	debug(query(rt[2], 1, n, 1))

	input(q);
	for (int i = 1, x, y; i <= q; ++ i) {
		cin >> op; input(x), input(y);
		if (*op == 'Q') output(query(rt[x], 1, n, y));
		else {
			mergeDsu(x, y);
			rt[x] = rt[y] = merge(rt[x], rt[y], 1, n);
		}
	}
	return 0;
}
