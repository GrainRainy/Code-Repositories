#include <bits/stdc++.h>
#define debug(x) cout << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using IO::input;
using namespace std;

const int N = 1e5 + 10;
const int M = 1e6 + 10;
int n, m, op, val, last,ans;
int x, y, z;
int rt, idx;
struct FHQ {
	int l, r;
	int val, siz, key;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define val(x) tree[x].val
	#define siz(x) tree[x].siz
	#define key(x) tree[x].key
}tree[N + M];

int newNode(int val) {
	idx ++;
	val(idx) = val, siz(idx) = 1, key(idx) = rand();
	return idx;
}

inline void pushUp(int u) {
	siz(u) = siz(l(u)) + siz(r(u)) + 1;
}

void split(int u, int val, int &x, int &y) {
	if (!u) return x = y = 0, void();
	if (val(u) <= val) split(r(u), val, r(x = u), y);
	else split(l(u), val, x, l(y = u));
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
	split(rt, val, x, y);
	rt = merge(merge(x, newNode(val)),y);
}

void del(int val) {
//	split(rt, val, x, z);
//	split(x, val - 1, x, y);
	split(rt, val - 1, x, y);
	split(y, val, y, z);
	y = merge(l(y), r(y));
	rt = merge(merge(x, y), z);
}

int getRk(int val) {
	split(rt, val - 1, x, y);
	int tmp = siz(x) + 1;
	merge(x, y);
	return tmp;
}

int getVal(int u, int rk) {
	if (rk <= siz(l(u))) return getVal(l(u), rk);
	if (rk == siz(l(u)) + 1) return val(u);
	return getVal(r(u), rk - siz(l(u)) - 1);
}

int getPre(int val) {
	split(rt, val - 1, x, y);
	int tmp = getVal(x, siz(x));
	merge(x, y);
	return tmp;
}

int getSuf(int val) {
	split(rt, val, x, y);
	int tmp = getVal(y, 1);
	merge(x, y);
	return tmp;
}

int main() {
	srand(time(0));
	input(n), input(m);
	for (int i = 1; i <= n; ++ i)
		input(val), insert(val);
	while (m --) {
		input(op), input(val);
		val ^= last;
		if (op == 1) insert(val);
		if (op == 2) del(val);
		if (op == 3) last = getRk(val), ans ^= last;
		if (op == 4) last = getVal(rt, val), ans ^= last;
		if (op == 5) last = getPre(val), ans ^= last;
		if (op == 6) last = getSuf(val), ans ^= last;
	}
	printf("%d\n", ans);
	return 0;
}
