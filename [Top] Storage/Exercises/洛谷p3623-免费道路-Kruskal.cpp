#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
const int M = 1e5 + 10;
int n, m, k, fa[N], cnt, tp;
struct Edge { int a, b, w; }e[M], ans[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
	rd(n), rd(m), rd(k);
	for (int i = 1; i <= n; ++ i) fa[i] = i;
	for (int i = 1; i <= m; ++ i) rd(e[i].a), rd(e[i].b), rd(e[i].w);
	sort(e + 1, e + m + 1, [](Edge &a, Edge &b) { return a.w > b.w; });
	for (int i = 1, a, b; i <= m; ++ i) {
		a = find(e[i].a), b = find(e[i].b);
		if (a != b) fa[a] = b;
		if (a != b and !e[i].w) cnt ++, e[i].w = -1;
	}
	if (cnt > k) return puts("no solution") & 0;
	for (int i = 2; i <= n; ++ i) if (find(i) != find(1)) return puts("no solution") & 0;
	cnt = 0; for (int i = 1; i <= n; ++ i) fa[i] = i;
	sort(e + 1, e + m + 1, [](Edge &a, Edge &b) { return a.w < b.w; });
	for (int i = 1, a, b; i <= m; ++ i) {
		a = find(e[i].a), b = find(e[i].b);
		if (a != b and (e[i].w == 1 or cnt < k)) {
			if (e[i].w < 1) e[i].w = 0, cnt ++;
			ans[++ tp] = e[i], fa[a] = b;
		}
	}
	if (cnt < k) return puts("no solution") & 0;
	for (int i = 2; i <= n; ++ i) if (find(i) != find(1)) return puts("no solution") & 0;
	for (int i = 1; i <= tp; ++ i) ot(ans[i].a, ' '), ot(ans[i].b, ' '), ot(ans[i].w);
	return 0;
}
