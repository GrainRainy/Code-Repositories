#include <iostream>
#include <cstring>
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
	static short tag[20], top;
	do tag[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(tag[top -- ] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int n, m, op, x, y, fx, fy;
int lson[N], rson[N], dis[N], rt[N], val[N];
bool tag[N];
// basis 

inline bool cmp(int x, int y) {
	if (val[x] ^ val[y]) return val[x] < val[y];
	return x < y;
}

int find(int x) {
	return rt[x] == x ? x : rt[x] = find(rt[x]);
}

int merge(int x, int y) {
	if (!x or !y) return x | y;
	if (cmp(y, x)) swap(x, y);
	rson[x] = merge(rson[x], y);
	if (dis[lson[x]] < dis[rson[x]]) swap(lson[x], rson[x]);
	dis[x] = dis[rson[x]] + 1;
	return x;
}

void del(int u) {
	tag[u] = true;
	rt[lson[u]] = rt[rson[u]] = rt[u] = merge(lson[u], rson[u]);
	lson[u] = rson[u] = dis[u] = 0;
}

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i)
		input(val[i]), rt[i] = i, dis[i] = 1;

	while (m --) {
		input(op), input(x);
		if (op == 1) {
			input(y);
			fx = find(x), fy = find(y);
			if (tag[x] or tag[y] or fx == fy) continue;
			rt[fx] = rt[fy] = merge(fx, fy);
		}
		if (op == 2) {
			if (tag[x]) { puts("-1"); continue; }
			x = find(x);
			output(val[x]);
			del(x);
		}
	}
	return 0;
}
