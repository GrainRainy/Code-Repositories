#include <bits/stdc++.h>
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
int n, m, op, x;
int rt, idx;
struct FHQ {
	int l, r;
	int val, key, siz;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define val(x) tree[x].val
	#define key(x) tree[x].key
	#define siz(x) tree[x].siz
}tree[N];

inline int newNode(int val) {
	idx ++;
	val(idx) = val, key(idx) = rand(), siz(idx) = 1;
	return idx;
} 

inline void pushUp(int u) {
	siz(u) = siz(l(u)) + siz(r(u)) + 1;
}

void split(int u, int val, int &rx, int &ry) {
	if (!u) return rx = ry = 0, void();
	if (val(u) <= val) split(r(u), val, r(rx = u), ry);
	else split(l(u), val, rx, l(ry = u));
	pushUp(u);
}

int merge(int x, int y) {
	if (!x or !y) return x | y;
	if (key(x) < key(y)) {
		r(x) = merge(r(x), y);
		pushUp(x);
		return x;
	} else {
		l(y) = merge(x, l(y));
		pushUp(y);
		return y;
	}
}

void insert(int val) {
	int rx, ry;
	split(rt, val, rx, ry);
	rt = merge(merge(rx, newNode(val)), ry);
}

void del(int val) {
	int x, y, z;
	split(rt, val, x, z);
	split(x, val - 1, x, y);
	y = merge(l(y), r(y));
	rt = merge(merge(x, y), z);
}

int getVal(int u, int k) { 
	if (k <= siz(l(u))) return getVal(l(u), k);
	if (k == siz(l(u)) + 1) return val(u);
	return getVal(r(u), k - siz(l(u)) - 1);
}

int getRank(int val) {
	int x, y;
	split(rt, val - 1, x, y);
	int tmp = siz(x) + 1;
	merge(x, y);
	return tmp;
}

int getPre(int val) {
	int x, y;
	split(rt, val - 1, x, y);
	int tmp = getVal(x, siz(x));
	merge(x, y);
	return tmp;
}

int getSuf(int val) {
	int x, y;
	split(rt, val, x, y);
	int tmp = getVal(y, 1);
	merge(x, y);
	return tmp;
}

int main() {
	srand(time(0));
	input(n);
	while (n --) {
		input(op), input(x);
		if (op == 1) insert(x);
		if (op == 2) del(x);
		if (op == 3) output(getRank(x));
		if (op == 4) output(getVal(rt, x));
		if (op == 5) output(getPre(x));
		if (op == 6) output(getSuf(x));
	}
	return 0;
}
