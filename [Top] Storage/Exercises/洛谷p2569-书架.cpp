#include <bits/stdc++.h>
#define __DEBUG__ puts("__DEBUG__");
#define debug(x) cout << #x << ' ' << x << endl;
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

using namespace std;
using namespace IO;

const int N = 8e4 + 10;
int n, m, p[N], id[N];
int a, b, c, d; // tmp root 
char op[10];
int rt, idx;
struct FHQ {
	int l, r;
	int fa, val, siz, key;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define fa(x) tree[x].fa
	#define val(x) tree[x].val
	#define siz(x) tree[x].siz
	#define key(x) tree[x].key
}tree[N];

int newNode(int val) {
	idx ++;
	val(idx) = val, siz(idx) = 1, key(idx) = rand();
	id[val] = idx;
	return idx;
}

void pushUp(int u) {
	siz(u) = siz(l(u)) + siz(r(u)) + 1;
}

void split(int u, int k, int &x, int &y, int fax = 0, int fay = 0) {
	if (!u) return x = y = 0, void();
	if (siz(l(u)) < k) {
		x = u, fa(x) = fax;
		split(r(u), k - siz(l(u)) - 1, r(x), y, u, fay);
	} else {
		y = u, fa(y) = fay;
		split(l(u), k, x, l(y), fax, u);
	}
	pushUp(u);
}

int merge(int x, int y) {
	if (!x or !y) return x | y;
	if (key(x) < key(y)) {
		r(x) = merge(r(x), y);
		fa(r(x)) = x;
		pushUp(x);
		return x;
	} else {
		l(y) = merge(x, l(y));
		fa(l(y)) = y;
		pushUp(y);
		return y;
	}
}

void insert(int pos, int val){
    split(rt, pos, a, b);
    rt = merge(a, merge(newNode(val), b));
}
inline bool isRx(int u) { return r(fa(u)) == u; }

int getRk(int u) {
	int node = u, res = siz(l(u)) + 1;
	while (node != rt and u) {
		if (isRx(u)) res += siz(l(fa(u))) + 1;
		u = fa(u);
	}
	return res;
}

int main() {
	srand(time(0));
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) 
		input(p[i]), insert(i - 1, p[i]);
	for (int i = 1, s, t, k; i <= m; ++ i) {
		scanf("%s", op); input(s);
		if (*op == 'T') {
			k = getRk(id[s]);
			split(rt, k, a, c);
			split(a, k - 1, a, b);
			rt = merge(b, merge(a, c));
		} else if (*op == 'B') {
			k = getRk(id[s]);
			split(rt, k, a, c);
			split(a, k - 1, a, b);
			rt = merge(merge(a, c), b);
		} else if (*op == 'I') {
			input(t);
			k = getRk(id[s]);
			if (t > 0)  {
				split(rt, k + 1, c, d);
				split(c, k, b, c);
				split(b, k - 1, a, b);
				rt = merge(a, merge(c, merge(b, d)));
			} else if (t < 0) {
				split(rt, k, c, d);
				split(c, k - 1, b, c);
				split(b, k - 2, a, b);
				rt = merge(a, merge(c, merge(b, d)));
			}
		} else if (*op == 'A') {
			output(getRk(id[s]) - 1);
		} else if (*op == 'Q') {
			split(rt, s, a, b);
			int tmp = a;
			while (r(tmp)) tmp = r(tmp);
			output(val(tmp));
			merge(a, b);
		}
	}
	return 0;
}
