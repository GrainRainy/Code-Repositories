#include <iostream>
#include <cstring>
#include <algorithm>

namespace IO {
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
		static short st[20], top;
		do st[ ++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top -- ] | '0');
		putchar(ed);
	}
}

using namespace std;
using namespace IO;

const int N = 2e5 + 10;
int n, op, x, y;
int lson[N], rson[N], val[N], dis[N], rt[N], top;

int find(int x) {
	return x == rt[x] ? x : rt[x] = find(rt[x]);
}

int merge(int a, int b) {
	if (!a or !b) return a | b;
	if (val[b] < val[a] or val[b] == val[a] and b < a) swap(a, b);
	rson[a] = merge(rson[a], b);
	if (dis[lson[a]] < dis[rson[a]]) swap(lson[a], rson[a]);
	dis[a] = dis[rson[a]] + 1;
	return a;
}

void del(int a) {
	rt[lson[a]] = rt[rson[a]] = rt[a] = merge(rson[a], lson[a]);
	lson[a] = rson[a] = dis[a] = 0;
}

int main() {
	dis[0] = -1, val[0] = 0x3f3f3f3f;
	input(n);
	while (n --) {
		input(op), input(x);
		if (op == 1) val[++ top] = x, rt[top] = top;
		if (op == 2) {
			input(y);
			x = find(x), y = find(y);
			if (x != y) rt[x] = rt[y] = merge(x, y);
		}
		if (op == 3) output(val[find(x)]);
		if (op == 4) del(find(x));
	}
	return 0;
}
