#include <bits/stdc++.h>
#define getchar() getchar_unlocked()
#define putchar(a) putchar_unlocked(a)
using namespace std;
const int N = 2e5 + 10;
int n, k, ans, c[N], al[N], head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
int fa[N], siz[N], dep[N], hs[N], dfn[N], nd[N], stamp;
int st[N], cz, ca;
bool cg[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[ ++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top -- ] | '0');
	putchar(ed);
}

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void dfs1(int u, int father, int depth) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	dfn[u] = ++ stamp, nd[stamp] = u;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == father) continue;
		dfs1(v, u, depth + 1);
		siz[u] += siz[v];
		if (siz[v] > siz[hs[u]]) hs[u] = v;
	}
}

inline void mul(int c) {
	if (!st[c]) cz ++;
	if ((++ st[c]) == al[c]) ca ++;
}

inline void dec(int c) {
	if (st[c] == al[c]) ca --;
	if (!(-- st[c])) cz --;
}

void calc(int u, bool kp) {
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if ((v = edge[i].to) != fa[u] and v != hs[u]) calc(v, 0);
	if (hs[u]) calc(hs[u], true);
	for (int i = head[u], v; ~i; i = edge[i].nxt) 
		if ((v = edge[i].to) != fa[u] and v != hs[u])
			for (int j = dfn[v]; j < dfn[v] + siz[v]; ++ j) 
				mul(c[nd[j]]);
	mul(c[u]);
	if (!(ca - (st[c[fa[u]]] == al[c[fa[u]]]) == cz - (bool)st[c[fa[u]]])) cg[fa[u]] = true;
	if (!(ca - (st[c[u]] == al[c[u]]) == cz - (bool)st[c[u]])) cg[u] = true;
	if (!kp) for (int i = dfn[u]; i < dfn[u] + siz[u]; ++ i) dec(c[nd[i]]);
}

int main() {
	rd(n), rd(k);
	for (int i = 1; i <= n; ++ i) rd(c[i]), al[c[i]] ++, head[i] = -1;
	for (int i = 1, a, b; i < n; ++ i) rd(a), rd(b), add(a, b), add(b, a);
	dfs1(1, 0, 1), calc(1, 1);
	for (int i = 1; i <= n; ++ i) if (cg[i] and !(-- al[c[i]])) ans ++;
	ot(k - ans);
	for (int i = 1; i <= k; ++ i) if (al[i]) ot(i, ' ');
	return putchar('\n') & 0; 
}
