#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 3e5 + 10;
const int LN = 25;
int n, m, dt, nt, rt[N], ttp;
struct Dsu {
	int l, r, fa, siz;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define fa(x) tree[x].fa
	#define siz(x) tree[x].siz
}tree[N * LN << 1];
bool agy = false;
char op;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

void modify(int &u, int pre, int tl, int tr, int p, int nfa, int nsiz) {
	if (!u) u = ++ ttp;
//	cout << u << ' ' << tl << ' ' << tr << '\n';
	if (tl == tr) return fa(u) = nfa, siz(u) = nsiz, void();
	int mid = tl + tr >> 1;
	if (p <= mid) {
		if (!r(u)) r(u) = r(pre);
		modify(l(u), l(pre), tl, mid, p, nfa, nsiz);
	} else {
		if (!l(u)) l(u) = l(pre);
		modify(r(u), r(pre), mid + 1, tr, p, nfa, nsiz);
	}
}

Dsu val(int u, int tl, int tr, int p) {
	if (tl == tr) return tree[u];
	int mid = tl + tr >> 1;
	if (p <= mid) return val(l(u), tl, mid, p);
	return val(r(u), mid + 1, tr, p);
}

int find(int x, int v) {
	int nf = val(rt[v], 1, n, x).fa;
	return x == nf ? x : find(nf, v);
}

void merge(int a, int b) {
	auto faa = val(rt[nt], 1, n, find(a, nt)), fab = val(rt[nt], 1, n, find(b, nt));
	nt ++;
	if (faa.fa == fab.fa) return rt[nt] = rt[nt - 1], void();
	if (faa.siz < fab.siz) swap(faa, fab);
	modify(rt[nt], rt[nt - 1], 1, n, fab.fa, faa.fa, fab.siz);
	modify(rt[nt], rt[nt - 1], 1, n, faa.fa, faa.fa, faa.siz + fab.siz);
}

inline int ex(int x) { return x < 0 ? x + n : x > n ? x - n : x; }
int main() {
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i) modify(rt[0], rt[0], 1, n, i, i, 1);
	for (int i = 1, v, x, y, st, ed, t; i <= m; ++ i) {
		do op = getchar(); while (op != 'K' and op != 'R' and op != 'T');
		if (op == 'K') rd(v), dt = v, agy = false;
		else if (op == 'R') {
			rd(x), rd(y), x ++, y ++;
			agy ? merge(ex(x + dt), ex(y + dt)) : merge(x, y);
		} else {
			rd(st), rd(ed), rd(t), st ++, ed ++;
			if (find(st, max(nt - t, 0)) != find(ed, max(nt - t, 0))
				and find(st, nt) == find(ed, nt)) puts("Y"), agy = false;
			else puts("N"), agy = true;
		}
	}
	return 0;
}
