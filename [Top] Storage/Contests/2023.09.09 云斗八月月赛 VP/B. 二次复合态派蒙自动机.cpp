#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void ot(T x, char ed = '\n') {
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
const int M = 2e5 + 10;
int n, m;
struct Edge { int a, b, w; }edge[M];
int d[N];

int main() {
	rd(n), rd(m);
	for (int i = 1, a, b, w; i <= m; ++ i) {
		rd(a), rd(b), rd(w);
		edge[i] = {a, b, w};
		d[a] |= w, d[b] |= w;
	}
	for (int i = 1, a, b, w; i <= m; ++ i) {
		a = edge[i].a, b = edge[i].b, w = edge[i].w;
		if ((d[a] & d[b]) != w) return puts("0") & 0;
	}
	puts("1");
	for (int i = 1; i <= n; ++ i) ot(d[i], ' ');
	return 0;
}
