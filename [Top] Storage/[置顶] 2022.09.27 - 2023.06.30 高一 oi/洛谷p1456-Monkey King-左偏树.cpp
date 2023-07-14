#include <iostream>
#include <cstring>
#include <algorithm>

#define __DEBUG__ puts("__DEBUG__");

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
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
int n, m, x, y, fx, fy;
// basis
int lson[N], rson[N], val[N], dis[N], rt[N];

int find(int x) {
	return rt[x] == x ? x : rt[x] = find(rt[x]);
}

int merge(int x, int y) {
	if (!x or !y) return x | y;
	if (val[y] > val[x]) swap(x, y);
	rson[x] = merge(rson[x], y);
	if (dis[lson[x]] < dis[rson[x]]) swap(lson[x], rson[x]);
	dis[x] = dis[rson[x]] + 1;
	return x;
}

int modify(int x) {
	val[x] >>= 1;
	int nrt = merge(lson[x], rson[x]);
	lson[x] = rson[x] = dis[x] = 0;
	return rt[nrt] = rt[x] = merge(nrt, x);
}

int main() {
	while (~scanf("%d", &n)) {
		dis[0] = -1;
		for (int i = 1; i <= n; ++ i) {
			input(val[i]), rt[i] = i;
			lson[i] = rson[i] = dis[i] = 0;
		}
		
		input(m);
		while (m --) {
			input(x), input(y);
			x = find(x), y = find(y);
			if (x == y) { puts("-1"); continue; }
			fx = modify(x), fy = modify(y);
			rt[fx] = rt[fy] = merge(fx, fy);
			output(val[rt[fx]]);
		}
	}
	return 0;
}
