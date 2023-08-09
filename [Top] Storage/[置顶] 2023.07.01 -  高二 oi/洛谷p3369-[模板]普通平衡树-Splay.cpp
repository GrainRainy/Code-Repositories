#include <bits/stdc++.h>
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
const int INF = 0x3f3f3f3f;
int n, op, x;
int rt, tot;
struct Splay {
	int s[2];
	int fa, val, cnt, siz;
	#define l(x) tree[x].s[0]
	#define r(x) tree[x].s[1]
	#define fa(x) tree[x].fa
	#define val(x) tree[x].val
	#define cnt(x) tree[x].cnt
	#define siz(x) tree[x].siz
	void init(int father, int value) {
		s[0] = s[1] = 0, fa = father, val = value, siz = cnt = 1;
	}
}tree[N];

void pushUp(int u) {
	siz(u) = siz(l(u)) + siz(r(u)) + cnt(u);
}

void rotate(int x) {
	int y = fa(x), z = fa(y);
	bool isrx = x == r(y);
	tree[y].s[isrx] = tree[x].s[isrx ^ 1];
	fa(tree[x].s[isrx ^ 1]) = y;
	tree[x].s[isrx ^ 1] = y, fa(y) = x;
	tree[z].s[y == r(z)] = x, fa(x) = z;
	pushUp(y), pushUp(x);
}

void splay(int x, int k) {
	while (fa(x) != k) {
		int y = fa(x), z = fa(y);
		if (z != k) ((l(y) == x) ^ (l(z) == y)) ? rotate(x) : rotate(y);
		rotate(x);
	}
	if (!k) rt = x;
}

void insert(int val) {
	int x = rt, fa = 0;
	while (x and val(x) != val)
		fa = x, x = tree[x].s[val > val(x)];
	if (x) cnt(x) ++;
	else {
		x = ++ tot;
		tree[fa].s[val > val(fa)] = x;
		tree[x].init(fa, val);
	}
	splay(x, 0);
}

void find(int val) {
	int x = rt;
	while (tree[x].s[val > val(x)] and val(x) != val)
		x = tree[x].s[val > val(x)];
	splay(x, 0);
}

int getPre(int val) {
	find(val);
	int x = rt;
	if (val(x) < val) return x;
	x = l(x);
	while (r(x)) x = r(x);
	return x;
}

int getSuf(int val) {
	find(val);
	int x = rt;
	if (val(x) > val) return x;
	x = r(x);
	while (l(x)) x = l(x);
	return x;
}

void del(int val) {
	int pre = getPre(val), suf = getSuf(val);
	splay(pre, 0), splay(suf, pre);
	int del = l(suf);
	if (cnt(del) > 1) cnt(del) --, splay(del, 0);
	else l(suf) = 0, splay(suf, 0);
}

int getVal(int rk) {
	rk ++;
	int x = rt;
	while (true) {
		if (rk > siz(l(x)) + cnt(x)) {
			rk -= siz(l(x)) + cnt(x);
			x = r(x);
		}
		else if (siz(l(x)) >= rk) x = l(x);
		else break;
	}
	splay(x, 0);
	return val(x);
}

int getRk(int val) {
	find(val);
	return siz(l(rt));
}

int main() {
	input(n);
	insert(-INF), insert(INF);
	while (n --) {
		input(op), input(x);
		if (op == 1) insert(x);
		if (op == 2) del(x);
		if (op == 3) output(getRk(x));
		if (op == 4) output(getVal(x));
		if (op == 5) output(val(getPre(x)));
		if (op == 6) output(val(getSuf(x)));
	}
	return 0;
}
