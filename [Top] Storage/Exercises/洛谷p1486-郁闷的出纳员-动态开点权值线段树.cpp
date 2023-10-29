#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 3e5 + 10;
const int L = 1e9;
const int LL = 30;
int n, mn, k, rt, ttp, dt, awy;
char op;
struct SegmentTree {
	int l, r, c;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define c(x) tree[x].c
}tree[N * LL];
vector<int> buf;

int nw() {
	int tmp = buf.size() ? buf.back() : ++ ttp;
	if (buf.size()) buf.pop_back();
	return tmp;
}

void del(int u) {
	l(u) = r(u) = c(u) = 0;
	buf.emplace_back(u);
}

void insert(int &u, int tl, int tr, int p) {
	if (!u) u = nw();
	if (tl == tr) return c(u) ++, void();
	int mid = tl + tr >> 1;
	if (p <= mid) insert(l(u), tl, mid, p);
	else insert(r(u), mid + 1, tr, p);
	c(u) = c(l(u)) + c(r(u));
}

void clear(int &u, int tl, int tr, int l, int r) {
	if (l <= tl and tr <= r) return del(u), u = 0, void();
	int mid = tl + tr >> 1;
	if (l <= mid and l(u)) clear(l(u), tl, mid, l, r);
	if (r > mid and r(u)) clear(r(u), mid + 1, tr, l, r);
	c(u) = c(l(u)) + c(r(u));
}

int query(int u, int tl, int tr, int k) {
	if (tl == tr) return tl;
	int mid = tl + tr >> 1;
	if (c(r(u)) >= k) return query(r(u), mid + 1, tr, k);
	return query(l(u), tl, mid, k - c(r(u)));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> mn;
	while (n --) {
		cin >> op >> k;
		if (op == 'I' and k >= mn) insert(rt, -L, L, k - dt);
		if (op == 'A') dt += k;
		if (op == 'S') awy += c(rt), clear(rt, -L, L, mn - dt, mn - dt + k - 1), awy -= c(rt), dt -= k;
		if (op == 'F') cout << (k > c(rt) ? -1 : query(rt, -L, L, k) + dt) << '\n';
	}
	return cout << awy << '\n', 0;
}
