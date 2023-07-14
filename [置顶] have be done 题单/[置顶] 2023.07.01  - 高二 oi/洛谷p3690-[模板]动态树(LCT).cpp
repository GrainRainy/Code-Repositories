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
int n, m;
struct LCT {
	int s[2], fa;
	int val, sum;
	bool tag;
	#define l(x) tree[x].s[0]
	#define r(x) tree[x].s[1]
	#define fa(x) tree[x].fa
	#define val(x) tree[x].val
	#define sum(x) tree[x].sum
	#define tag(x) tree[x].tag
}tree[N];

inline bool notRt(int x) {
	return l(fa(x)) == x or r(fa(x)) == x;
}

inline void pushUp(int u) {
	sum(u) = sum(l(u)) ^ sum(r(u)) ^ val(u);
}

inline void pushDown(int u) {
	if (!tag(u)) return;
	swap(l(u), r(u));
	tag(l(u)) ^= 1, tag(r(u)) ^= 1;
	tag(u) = 0;
}

inline void pushAll(int x) {
	if (notRt(x)) pushAll(fa(x));
	pushDown(x);
}

void rotate(int x) {
	int y = fa(x), z = fa(y);
	bool isrx = r(y) == x;
	if (notRt(y)) tree[z].s[r(z) == y] = x;
	fa(x) = z;
	tree[y].s[isrx] = tree[x].s[isrx ^ 1];
	fa(tree[x].s[isrx ^ 1]) = y;
	tree[x].s[isrx ^ 1] = y;
	fa(y) = x;
	pushUp(y); pushUp(x);
}

void splay(int x) {
	pushAll(x);
	while (notRt(x)) {
		int y = fa(x), z = fa(y);
		if (notRt(y)) (l(y) == x) ^ (l(z) == y) ? rotate(x) : rotate(y);
		rotate(x);
	}
}

void access(int x) {
	for (int y = 0; x; y = x, x = fa(x))
		splay(x), r(x) = y, pushUp(x);
}

int findRt(int x) {
	access(x);
	splay(x);
	while (l(x)) pushDown(x), x = l(x);
	splay(x);
	return x;
}

void modifyRt(int x) {
	access(x);
	splay(x);
	tag(x) ^= 1;
}

void link(int x, int y) {
	modifyRt(x);
	if (findRt(y) != x) fa(x) = y;
}

void cut(int x, int y) {
	modifyRt(x);
	if (findRt(y) == x and fa(y) == x and !l(y)) {
		r(x) = fa(y) = 0;
		pushUp(x);
	}
}

void split(int x, int y) {
	modifyRt(x);
	access(y);
	splay(y);
}

void modifyVal(int x, int val) {
	splay(x);
	val(x) = val;
	pushUp(x);
}

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) input(tree[i].val);
	for (int i = 1, op, x, y; i <= m; ++ i) {
		input(op), input(x), input(y);
		if (op == 0) split(x, y), output(sum(y));
		if (op == 1) link(x, y);
		if (op == 2) cut(x, y);
		if (op == 3) modifyVal(x, y);
	}
	return 0;
}
