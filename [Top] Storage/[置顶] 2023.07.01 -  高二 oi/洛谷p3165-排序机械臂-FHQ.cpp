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
int n, rk[N];
struct Item {
	int h, pos;
	bool operator < (const Item &t) const {
		return h == t.h ? pos < t.pos : h < t.h;
	}
}ary[N];
int rt, idx, x, y, z;
struct FHQ {
	int l, r;
	int h, mn, siz, tag, key;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define h(x) tree[x].h
	#define mn(x) tree[x].mn
	#define siz(x) tree[x].siz
	#define tag(x) tree[x].tag
	#define key(x) tree[x].key
}tree[N];

int newNode(int val) {
	idx ++;
	h(idx) = val, mn(idx) = val, siz(idx) = 1, key(idx) = rand();
	return idx;
}

void pushUp(int u) {
	siz(u) = siz(l(u)) + siz(r(u)) + 1;
	mn(u) = h(u);
	if (l(u)) mn(u) = min(mn(u), mn(l(u)));
	if (r(u)) mn(u) = min(mn(u), mn(r(u)));
} 

void pushDown(int u) {
	if (!tag(u)) return;
	swap(l(u), r(u));
	if (l(u)) tag(l(u)) ^= 1;
	if (r(u)) tag(r(u)) ^= 1;
	tag(u) = 0;
}

void split(int u, int val, int &x, int &y) {
	if (!u) return x = y= 0, void();
	pushDown(u);
	if (siz(l(u)) < val) split(r(u), val - siz(l(u)) - 1, r(x = u), y);
	else split(l(u), val, x, l(y = u));
	pushUp(u);
}

int merge(int x, int y) {
	if (!x or !y) return x | y;
	if (key(x) < key(y)) {
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

int getRk(int u) {
	int k = 1;
	while (true) {
		pushDown(u);
		if (l(u) and mn(l(u)) == mn(u)) u = l(u);
		else if (r(u) and mn(r(u)) == mn(u)) 
			k += siz(l(u)) + 1, u = r(u);
		else return k + siz(l(u));
	}
}

int main() {
	srand(time(0));
	input(n);
	for (int i = 1; i <= n; ++ i)
		input(ary[i].h), ary[i].pos = i;
	sort(ary + 1, ary + n + 1);
	for (int i = 1; i <= n; ++ i)
		rk[ary[i].pos] = i;
	for (int i = 1; i <= n; ++ i)
		rt = merge(rt, newNode(rk[i]));
	for (int i = 1, k; i <= n; ++ i) {
		k = getRk(rt);
		output(k + i - 1, ' ');
		split(rt, k, x, y);
		split(x, k - 1, x, z);
		tag(x) ^= 1;
		rt = merge(x, y);
	}
	return 0;
}
