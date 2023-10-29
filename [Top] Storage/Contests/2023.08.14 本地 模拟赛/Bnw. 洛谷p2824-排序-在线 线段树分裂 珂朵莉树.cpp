#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO { 
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}
using IO::rd;
using namespace std;
const int N = 1e5 + 10;
const int LOGN = 17 + 5;
int n, m, q;
set<int> st;
set<int>::iterator it, itl, itr;
int tot, rt[N], buf[N * LOGN], top;
struct SegmentTree{
	int l, r, cnt;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define cnt(x) tree[x].cnt
	void init() { l = r = cnt = 0; }
}tree[N * LOGN];
bool op[N];

inline void del(int u) { buf[++ top] = u; }
inline int newNode() { return top ? buf[top --] : ++ tot; }

void insert(int &u, int tl, int tr, int pos) {
	if (!u) u = newNode();
	cnt(u) ++;
	if (tl == tr) return;
	int mid = tl + tr >> 1;
	if (pos <= mid) return insert(l(u), tl, mid, pos);
	else return insert(r(u), mid + 1, tr, pos);
}

int merge(int x, int y) {
	if (!x or !y) return x | y;
	l(x) = merge(l(x), l(y)), r(x) = merge(r(x), r(y));
	cnt(x) += cnt(y), del(y);
	return x;
}

void split(int x, int &y, int k, bool op) {
	if (!x) return;
	y = newNode(), tree[y].init();
	cnt(y) = cnt(x) - k, cnt(x) = k;
	if (op) {
		if (k > cnt(r(x))) split(l(x), l(y), k - cnt(r(x)), op);
		else swap(l(x), l(y));
		if (k < cnt(r(x))) split(r(x), r(y), k, op);
	} else {
		if (k > cnt(l(x))) split(r(x), r(y), k - cnt(l(x)), op);
		else swap(r(x), r(y));
		if (k < cnt(l(x))) split(l(x), l(y), k, op);
	}
}

set<int>::iterator split(int pos) {
	it = st.lower_bound(pos);
	if (*it == pos) return it; -- it;
	split(rt[*it], rt[pos], pos - *it, op[pos] = op[*it]);
	return st.insert(pos).first;
}

int query(int u, int tl, int tr) {
	if (tl == tr) return tl;
	int mid = tl + tr >> 1;
	return l(u) ? query(l(u), tl, mid) : query(r(u), mid + 1, tr);
}

int main() {
//	freopen("data.in", "r", stdin);
	rd(n), rd(m);
	for (int i = 1, a; i <= n; ++ i) {
		rd(a), insert(rt[i], 1, n, a);
		st.insert(i);
	}
	st.insert(n + 1);
	for (int i = 1, o, l, r; i <= m; ++ i) {
		rd(o), rd(l), rd(r);
		auto itr = split(r + 1), itl = split(l);
		for (auto i = ++ itl; i != itr; ++ i)
			rt[l] = merge(rt[l], rt[*i]);
		op[l] = o;
		st.erase(itl, itr);
	}
	rd(q);
	split(q), split(q + 1);
	return printf("%d\n", query(rt[q], 1, n)), 0;
}
