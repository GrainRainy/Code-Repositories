#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void ot(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[30], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}
using IO::ot;
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
int n, m, seed, vmax;
struct Range {
	int l, r; 
	mutable LL val;
	Range(int l, int r = 0, LL val = 0) : l(l), r(r), val(val) {}
	bool operator < (const Range &t) const { return l < t.l; }
};
struct Save {
	int len; LL val;
	bool operator < (const Save &t) const { return val < t.val; }
};
set<Range> st;
set<Range>::iterator it, itl, itr;

set<Range>::iterator split(int pos) {
	it = lower_bound(st.begin(), st.end(), Range(pos));
	if (it != st.end() and it->l == pos) return it;
	-- it;
	if (it->r < pos) return st.end();
	int l = it->l, r = it->r; LL val = it->val;
	st.erase(it);
	st.insert((Range){l, pos - 1, val});
	return st.insert((Range){pos, r, val}).first;
}

void merge(int l, int r, int val) {
	itr = split(r + 1), itl = split(l);
	st.erase(itl, itr);
	st.insert((Range){l, r, val});
}

void modify(int l, int r, int val) {
	itr = split(r + 1), itl = split(l);
	for (auto i = itl; i != itr; ++ i) i->val += val;
}

LL rk(int l, int r, int k) {
	vector<Save> a;
	itr = split(r + 1), itl = split(l);
	for (auto i = itl; i != itr; ++ i)
		a.push_back((Save){i->r - i->l + 1, i->val});
	sort(a.begin(), a.end());
	for (auto t : a) {
		if (k <= t.len) return t.val;
		else k -= t.len;
	}
}

int qpow(LL a, int b, int p) {
	int res = 1; a %= p;
	while (b) {
		if (b & 1) res = (LL)res * a % p;
		a = (LL)a * a % p;
		b >>= 1;
	}
	return res;
}

inline void upd(int &x, int y, int p) { x += y; (x >= p) and (x -= p); }
int rpow(int l, int r, int x, int y) {
	int res = 0;
	set<Range>::iterator itr = split(r + 1), itl = split(l);
	for (auto i = itl; i != itr; ++ i)
		upd(res, (LL)qpow(i->val, x, y) * (i->r - i->l + 1) % y, y);
	return res;
}

int rnd() {
	int ret = seed;
	seed = ((LL)seed * 7 + 13) % MOD;
	return ret;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &seed, &vmax);
	for (int i = 1, a; i <= n; ++ i) {
		a = rnd() % vmax + 1;
		st.insert((Range){i, i, a});
	}
	for (int i = 1, op, l, r, x, y; i <= m; ++ i) {
		op = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1;
		if (l > r) swap(l, r);
		if (op == 3) x = rnd() % (r - l + 1) + 1;
		else x = rnd() % vmax + 1;
		if (op == 4) y = rnd() % vmax + 1;
		if (op == 1) modify(l, r, x);
		if (op == 2) merge(l, r, x);
		if (op == 3) ot(rk(l, r, x));
		if (op == 4) ot(rpow(l, r, x, y));
	}
	return 0;
}
