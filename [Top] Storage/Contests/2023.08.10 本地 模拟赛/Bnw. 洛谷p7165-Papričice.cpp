#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
}

using IO::input;
using namespace std;
const int N = 2e5 + 10;
int n, head[N], idx, siz[N];
struct Node { int nxt, to; }edge[N << 1];
multiset<int> fa, br;
multiset<int>::iterator it;
int mn = 0x3f3f3f3f;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

inline void upd(int x, int y) {
	mn = min(mn, max({x, y, n - x - y}) - min({x, y, n - x - y}));
}

void pre(int u, int father) {
	siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		pre(j, u);
		siz[u] += siz[j];
	}
}

void dfs(int u, int father) {
	if (fa.size()) {
		it = fa.lower_bound((n - siz[u] >> 1) + siz[u]);
		if (it != fa.end()) upd(siz[u], *it - siz[u]);
		if (it != fa.begin()) { -- it; upd(siz[u], *it - siz[u]); }
	} if (br.size()) {
		it = br.lower_bound(n - siz[u] >> 1);
		if (it != br.end()) upd(siz[u], *it);
		if (it != br.begin()) { -- it; upd(siz[u], *it); }
	}
	if (father) fa.insert(siz[u]);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs(j, u);
	}
	if (father) fa.erase(fa.find(siz[u])), br.insert(siz[u]);
}

int main() {
	input(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) {
		input(a), input(b);
		add(a, b), add(b, a);
	}
	pre(1, 0), dfs(1, 0);
	return printf("%d\n", mn), 0;
}
