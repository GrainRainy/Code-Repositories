#include <iostream>
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
using LL = long long;

const int N = 1e5 + 10;
int n, m;
struct Person {
	int fa, cst, ld;
}per[N];
int lson[N], rson[N], rt[N], dis[N], siz[N];
LL cos[N];
// leftist tree
LL ans = -1;

int merge(int a, int b) {
	if (!a or !b) return a | b;
	if (per[b].cst > per[a].cst) swap(a, b);
	rson[a] = merge(rson[a], b);
	if (dis[lson[a]] < dis[rson[a]]) swap(lson[a], rson[a]);
	dis[a] = dis[rson[a]] + 1;
	return a;
}

int main() {
	input(n), input(m);
	dis[0] = -1;
	for (int i = 1, b, c, l; i <= n; ++ i) {
		input(b), input(c), input(l);
		per[i] = {b, c, l};
		siz[i] = 1, rt[i] = i;
		cos[i] = c;
		ans = max(ans, (LL)l);
	}
	for (int i = n, fa; i > 1; -- i) {
		fa = per[i].fa;
		rt[fa] = merge(rt[fa], rt[i]);
		siz[fa] += siz[i], cos[fa] += cos[i];
		while (cos[fa] > m) {
			cos[fa] -= per[rt[fa]].cst, siz[fa] --;
			rt[fa] = merge(lson[rt[fa]], rson[rt[fa]]);
		}
		ans = max(ans, (LL)per[fa].ld * siz[fa]);
	}
	return output(ans), 0;
}
