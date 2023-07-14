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
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top -- ] | '0');
	putchar(ed);
}

const int N = 1e6 + 10;
int n, m, x, y, fx, fy;
char op[3];
bool tag[N];
int lson[N], rson[N], val[N], dis[N], rt[N];
// leftist tree 

int find(int x) {
	return x == rt[x] ? x : rt[x] = find(rt[x]);
}

int merge(int a, int b) {
	if (!a or !b) return a | b;
	if (val[b] < val[a]) swap(a, b);
	rson[a] = merge(rson[a], b);
	if (dis[lson[a]] < dis[rson[a]]) swap(lson[a], rson[a]);
	dis[a] = dis[rson[a]] + 1;
	return a;
}

void del(int x) {
	if (tag[x]) return puts("0"), void();
	x = find(x);
	output(val[x]);
	rt[lson[x]] = rt[rson[x]] = rt[x] = merge(lson[x], rson[x]);
	tag[x] = true;
	lson[x] = rson[x] = dis[x] = 0;
	return;
}

int main() {
	input(n);
	dis[0] = -1;
	for (int i = 1; i <= n; ++ i) {
		input(val[i]), rt[i] = i;
	}
	
	input(m);
	while (m -- ) {
		cin >> op; input(x);
		if (op[0] == 'M') {
			input(y);
			if (tag[x] or tag[y]) continue;
			fx = find(x), fy = find(y);
			if (fx != fy) rt[fx] = rt[fy] = merge(fx, fy);
		}
		if (op[0] == 'K') del(x);
	}
	return 0;
}
