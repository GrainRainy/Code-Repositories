#include <bits/stdc++.h>
#define ls (u << 1)
#define rs (u << 1 | 1)
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace IO;
using namespace std;
const int N = 1e5 + 10;
const int M = 2e5 + 10;
int n, m, k;
struct Edge { int a, b; }edge[M];
struct Save { int fa, fb; bool add; }st[M]; int top;
vector<int> tree[N << 2]; // SegmentTree 
int fa[N << 1], h[N << 1];

inline int find(int a) {
	while (fa[a] ^ a) a = fa[a];
	return a;
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (h[x] > h[y]) swap(x, y); // x to y
	st[++ top] = {x, y, h[x] == h[y]};
	fa[x] = y;
	h[y] += (h[x] == h[y]);
}

void modify(int u, int tl, int tr, int l, int r, int val) {
	if (tl > r or tr < l) return;
	if (tl >= l and tr <= r) return tree[u].push_back(val), void();
	int mid = tl + tr >> 1;
	modify(ls, tl, mid, l, r, val);
	modify(rs, mid + 1 ,tr, l, r, val);
}

void dfs(int u, int tl, int tr) {
	bool f = true; int ptr = top;
	int tmpa, tmpb;
	for (int t : tree[u]) {
		tmpa = find(edge[t].a), tmpb = find(edge[t].b);
		if (tmpa == tmpb) {
			for (int i = tl; i <= tr; ++ i) puts("No");
			f = false;
			break;
		}
		merge(edge[t].a, edge[t].b + n);
		merge(edge[t].a + n, edge[t].b);
	}
	if (f) {
		if (tl == tr) puts("Yes");
		else {
			int mid = tl + tr >> 1;
			dfs(ls, tl, mid), dfs(rs, mid + 1, tr);
		}
	}
	for (; top > ptr; top --) {
		h[fa[st[top].fa]] -= st[top].add;
		fa[st[top].fa] = st[top].fa;
	}
	return;
}

int main() {
	input(n), input(m), input(k);
	for (int i = 1, x, y, l, r; i <= m; ++ i) {
		input(x), input(y), input(l), input(r);
		edge[i] = {x, y};
		modify(1, 1, k, l + 1, r, i);
		// note that max Range is k 
	}
	for (int i = 1; i <= (n << 1); ++ i) fa[i] = i, h[i] = 1; // init dsu
	dfs(1, 1, k);
	return 0;
}
