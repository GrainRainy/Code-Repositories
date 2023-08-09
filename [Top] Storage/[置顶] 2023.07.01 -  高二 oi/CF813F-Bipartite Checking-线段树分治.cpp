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

using IO::input;
using namespace std;
using PII = pair<int, int>;
const int N = 1e5 + 10;
int n, q;
int fa[N << 1], h[N << 1];
struct Edge { int a, b, st, ed; } edge[N]; int etop;
struct Stack { int a, b; bool add; }stk[N]; int top;
vector<int> tree[N << 2];
map<PII, int> mp;

int find(int x) {
	while (fa[x] ^ x) x = fa[x];
	return x;
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (h[a] > h[b]) swap(a, b); // merge a to b
	stk[++ top] = {a, b, h[a] == h[b]};
	fa[a] = b;
	h[b] += (h[a] == h[b]);
}

void modify(int u, int tl, int tr, int l, int r, int val) {
	if (tr < l or tl > r) return;
	if (l <= tl and tr <= r) return tree[u].push_back(val), void();
	int mid = tl + tr >> 1;
	modify(ls, tl, mid, l, r, val);
	modify(rs, mid + 1, tr, l, r, val);
}

void dfs(int u, int tl, int tr) {
	bool f = true; int ptr = top;
	int tmpa, tmpb;
	for (int t : tree[u]) {
		tmpa = find(edge[t].a), tmpb = find(edge[t].b);
		if (tmpa == tmpb) {
			for (int i = tl; i <= tr; ++ i) puts("NO");
			f = false;
			break;
		}
		merge(edge[t].a, edge[t].b + n);
		merge(edge[t].a + n, edge[t].b);
	}
	if (f) {
		if (tl == tr) puts("YES");
		else {
			int mid = tl + tr >> 1;
			dfs(ls, tl, mid), dfs(rs, mid + 1, tr);
		}
	}
	for (; top > ptr; -- top) {
		h[fa[stk[top].b]] -= stk[top].add;
		fa[stk[top].a] = stk[top].a;
	}
}

int main() {
	input(n), input(q);
	for (int i = 1, x, y; i <= q; ++ i) {
		input(x), input(y);
		if (x > y) swap(x, y);
		if (mp[{x, y}]) {
			edge[mp[{x, y}]].ed = i - 1;
			mp[{x, y}] = 0;
		} else {
			mp[{x, y}] = ++ etop;
			edge[etop] = {x, y, i};
		}
	}
//	for (int i = 1; i <= etop; ++ i) 
//		cout << edge[i].a << ' ' << edge[i].b << ' ' << edge[i].st << ' ' << edge[i].ed << '\n';
	for (int i = 1; i <= etop; ++ i) 
		modify(1, 1, q, edge[i].st, !edge[i].ed ? q : edge[i].ed, i);
	for (int i = 1; i <= (n << 1); ++ i) fa[i] = i, h[i] = 1;
	dfs(1, 1, q);
	return 0;
}
