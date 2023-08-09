#include <iostream>
#include <ctime>
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
		while (top) putchar(st[top -- ] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;

const int N = 1e5 + 10;
int n, m;
int rt, idx;
struct FHQ {
	int l, r;
	int val, key, siz;
	bool lazy;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define val(x) tree[x].val
	#define key(x) tree[x].key
	#define lazy(x) tree[x].lazy
	#define siz(x) tree[x].siz
}tree[N];

inline void pushUp(int u) {
	siz(u) = siz(l(u)) + siz(r(u)) + 1;
}

inline void pushDown(int u) {
	if (!lazy(u)) return;
	swap(l(l(u)), r(l(u))), swap(l(r(u)), r(r(u)));
	lazy(l(u)) ^= 1, lazy(r(u)) ^= 1;
	lazy(u) = 0;
}

void split(int u, int val, int &x, int &y) {
	if (!u) return x = y = 0, void();
	pushDown(u);
	if (siz(l(u)) + 1 <= val) split(r(u), val - siz(l(u)) - 1, r(x = u), y);
	else split(l(u), val, x, l(y = u));
	pushUp(u);
}

int merge(int x, int y) {
	if (!x or !y) return x | y;
	if (key(x) <= key(y)) {
		pushDown(x);
		r(x) = merge(r(x), y);
		pushUp(x);
		return x;
	} else {
		pushDown(y);
		l(y) = merge(x, l(y));
		pushUp(y);
		return y;
	}
}

int newNode(int val) {
	idx ++;
	val(idx) = val, key(idx) = rand(), siz(idx) = 1;
	return idx;
}

void insert(int val) {
	rt = merge(rt, newNode(val));
}

void reverse(int l, int r) {
	int x, y, z;
	split(rt, l - 1, x, y);
	split(y, r - l + 1, y, z);
	swap(l(y), r(y)), lazy(y) ^= 1;
	rt = merge(merge(x, y), z);
}

void print(int u) {
	if (!u) return;
	pushDown(u);
	print(l(u));
	output(val(u), ' ');
	print(r(u));
}

int main() {
	srand(time(0));
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) insert(i);
	for (int i = 1, l, r; i <= m; ++ i) {
		input(l), input(r);
		reverse(l, r);
	}
	print(rt);
	return 0;
}
