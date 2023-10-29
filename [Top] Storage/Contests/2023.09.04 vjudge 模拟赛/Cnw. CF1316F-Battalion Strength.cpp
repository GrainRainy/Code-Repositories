#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void ot(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
const int N = 3e5 + 10;
const int MOD = 1e9 + 7;
int n, q, p[N], pos;
int lis[N << 1], id[N], val[N], inv[N];
map<int, int> mp;
int rt, top;
struct SegmentTree {
	int l, r, cnt, val, pre, suf;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define cnt(x) tree[x].cnt
	#define val(x) tree[x].val
	#define pre(x) tree[x].pre
	#define suf(x) tree[x].suf
}tree[N << 2];

inline int upd(int x, int y) { return x + y > MOD ? x + y - MOD : x + y; }
void modify(int &u, int tl, int tr, int pos, int val) {
	if (!u) u = ++ top;
	if (tl == tr) {
		val(u) = 0;
		cnt(u) = val > 0 ? 1 : 0;
		pre(u) = upd(pre(u), (LL)val * inv[1] % MOD);
		suf(u) = upd(suf(u), (LL)val * inv[1] % MOD);
		return; 
	}
	int mid = tl + tr >> 1;
	if (pos <= mid) modify(l(u), tl, mid, pos, val);
	else modify(r(u), mid + 1, tr, pos, val);
	cnt(u) = cnt(l(u)) + cnt(r(u));
	val(u) = upd(upd(val(l(u)), val(r(u))), (LL)suf(l(u)) * pre(r(u)) % MOD);
	pre(u) = upd(pre(l(u)), (LL)pre(r(u)) * inv[cnt(l(u))] % MOD);
	suf(u) = upd((LL)suf(l(u)) * inv[cnt(r(u))] % MOD, suf(r(u)));
}

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	rd(n);
	inv[n] = qpow(qpow(2, n), MOD - 2);
	for (int i = 1; i <= n; ++ i) rd(p[i]), lis[i] = p[i];
	for (int i = n - 1; ~i; -- i) inv[i] = upd(inv[i + 1], inv[i + 1]);
	rd(q);
	for (int i = 1; i <= q; ++ i) rd(id[i]), rd(val[i]), lis[n + i] = val[i];
	sort(lis + 1, lis + n + q + 1);
	for (int i = 1; i <= n; ++ i) {
		mp[p[i]] ++;
		p[i] = lower_bound(lis + 1, lis + n + q + 1, p[i]) - lis + mp[p[i]] - 1;
		modify(rt, 1, n + q, p[i], lis[p[i]]);
	}
	ot(val(rt), '\n');
	for (int i = 1; i <= q; ++ i) {
		mp[val[i]] ++;
		val[i] = lower_bound(lis + 1, lis + n + q + 1, val[i]) - lis + mp[val[i]] - 1;
		modify(rt, 1, n + q, p[id[i]], -lis[p[id[i]]]);
		modify(rt, 1, n + q, p[id[i]] = val[i], lis[val[i]]);
		ot(val(rt), '\n');
	}
	return 0;
}
