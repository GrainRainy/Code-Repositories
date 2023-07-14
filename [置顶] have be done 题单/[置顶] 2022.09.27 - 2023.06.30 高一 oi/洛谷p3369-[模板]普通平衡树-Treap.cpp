#include <iostream>
#include <cstring>
#include <random>
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
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
const int INF = 0x7fffffff;
struct Treap {
	int l, r;
	int val, dat;
	int cnt, siz;
	
	#define l(x) tr[x].l
	#define r(x) tr[x].r
	#define val(x) tr[x].val
	#define dat(x) tr[x].dat
	#define cnt(x) tr[x].cnt
	#define siz(x) tr[x].siz
}tr[N];
int tot, root;
int n, op, x;

int New(int val) {
	val(++ tot) = val;
	dat(tot) = rand();
	cnt(tot) = siz(tot) = 1;
	return tot;
}

void Update(int u) {
	siz(u) = siz(l(u)) + siz(r(u)) + cnt(u);
}

void Build() {
	New(-INF), New(INF);
	root = 1, r(1) = 2;
	Update(root);
}

int GetRankByVal(int u, int val) {
	if (!u) return 0;
	if (val == val(u)) return siz(l(u)) + 1;
	if (val < val(u)) return GetRankByVal(l(u), val);
	return GetRankByVal(r(u), val) + siz(l(u)) + cnt(u);
}

int GetValByRank(int u, int rank) {
	if (!u) return 0;
	if (siz(l(u)) >= rank) return GetValByRank(l(u), rank);
	if (siz(l(u)) + cnt(u) >= rank) return val(u);
	return GetValByRank(r(u), rank - siz(l(u)) - cnt(u));
}

void zig(int &u) { // left 
	int lson = l(u);
	l(u) = r(lson), r(lson) = u, u = lson;
	Update(r(u)), Update(u);
}

void zag(int &u) {
	int rson = r(u);
	r(u) = l(rson), l(rson) = u, u = rson;
	Update(l(u)), Update(u);
}

void Insert(int &u, int val) {
	if (!u) return u = New(val), void();
	if (val == val(u)) {
		cnt(u) ++; Update(u);
		return;
	}
	if (val < val(u)) {
		Insert(l(u), val);
		if (dat(u) < dat(l(u))) zig(u);
	}
	else {
		Insert(r(u), val);
		if (dat(u) < dat(r(u))) zag(u);
	}
	return Update(u), void();
}

int GetPre(int p, int val)   // ??????val????
{
    if (!p) return -INF;
    if (tr[p].val >= val) return GetPre(tr[p].l, val);
    return max(tr[p].val, GetPre(tr[p].r, val));
}

int GetNext(int p, int val)    // ??????val????
{
    if (!p) return INF;
    if (tr[p].val <= val) return GetNext(tr[p].r, val);
    return min(tr[p].val, GetNext(tr[p].l, val));
}

int GetPre(int val) {
	int ans = 1; // -INF
	int u = root;
	while (u) {
		if (val == val(u)) {
			if (l(u) > 0) {
				u = l(u);
				while (r(u) > 0) u = r(u);
				ans = u;
			}
			break;
		}
		if (val(u) < val and val(u) > val(ans)) ans = u;
		u = val < val(u) ? l(u) : r(u);
	}
	return val(ans);
}

int GetNext(int val) {
	int ans = 2; // INF 
	int u = root;
	while (u) {
		if (val == val(u)) {
			if (r(u) > 0) {
				u = r(u);
				while (l(u) > 0) u = l(u);
				ans = u;
			}
			break;
		}
		if (val(u) > val and val(u) < val(ans)) ans = u;
		u = val < val(u) ? l(u) : r(u);
	}
	return val(ans);
}

void Remove(int &u, int val) {
	if (!u) return;
	if (val == val(u)) {
		if (cnt(u) > 1) {
			cnt(u) --; Update(u);
			return;
		}
		if (l(u) or r(u)) {
			if (!r(u) or dat(l(u)) > dat(r(u)))
				zig(u), Remove(r(u), val);
			else zag(u), Remove(l(u), val);
			Update(u);
		}
		else u = 0;
		return;
	}
	val < val(u) ? Remove(l(u), val) : Remove(r(u), val);
	return Update(u), void();
}

int main() {
	Build();
	input(n);
	while (n --) {
		input(op), input(x);
		if (op == 1) Insert(root, x);
		if (op == 2) Remove(root, x);
		if (op == 3) output(GetRankByVal(root, x) - 1);
		if (op == 4) output(GetValByRank(root, x + 1));
		if (op == 5) output(GetPre(x));
		if (op == 6) output(GetNext(x));
	}
	return 0;
} 

