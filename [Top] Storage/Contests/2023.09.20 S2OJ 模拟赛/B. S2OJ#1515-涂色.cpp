#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m;
struct Edge { int a, b, c, v; }e[N];

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

namespace sub1 {
	int stk[N], fa[N];
	pair<int, int> ck[N];
	bool st[N];
	
	int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
	bool kruskal() {
		for (int i = 1; i <= n; ++ i) fa[i] = i;
		for (int i = 1; i <= m; ++ i) ck[i] = {stk[i], i};
		sort(ck + 1, ck + 1 + m);
		for (int i = 1; i <= m; ++ i) {
			if (find(e[ck[i].second].a) == find(e[ck[i].second].b)) continue;
			if (!e[ck[i].second].c) return false;
			fa[find(e[ck[i].second].a)] = find(e[ck[i].second].b);
		}
		return true;
	}
	
	void dfs(int u) {
		if (u == m + 1) {
			if (!kruskal()) return;
			for (int i = 1; i <= m; ++ i) ot(stk[i], " \n"[i == m]);
			exit(0);
		}
		for (int i = 1; i <= m; ++ i) {
			if (st[i]) continue;
			stk[u] = i, st[i] = true;
			dfs(u + 1);
			stk[u] = 0, st[i] = false;
		}
	}
}

namespace sub2 {
	void solve() {
		for (int i = 1; i <= m; ++ i) ot(i, " \n"[i == m]);
	}
}

int main() {
	rd(n), rd(m);
	for (int i = 1, a, b, c; i <= m; ++ i) {
		rd(a), rd(b), rd(c);
		e[i] = {a, b, c};
	}
	if (m == n - 1) return sub2::solve(), 0;
	return sub1::dfs(1), 0;
}
