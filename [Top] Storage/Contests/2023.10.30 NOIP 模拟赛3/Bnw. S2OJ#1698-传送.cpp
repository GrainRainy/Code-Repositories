#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e6 + 10;
int t, n, m, q, head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
int id[N], idt, cl[N];
bool st[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

bool dfs(int u, int nid, int col) {
	bool jg = false;
	id[u] = nid, cl[u] = col;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if (!cl[v = edge[i].to] and dfs(v, nid, 3 - col)) jg = true;
		else if (cl[v] == col) jg = true;
	}
	return jg;
}

int main() {
	rd(t), rd(n), rd(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i <= m; ++ i) rd(a), rd(b), add(a, b), add(b, a);
	for (int i = 1; i <= n; ++ i) if (!id[i]) ++ idt, st[idt] = dfs(i, idt, 1);
	rd(q);
	for (int i = 1, a, b; i <= q; ++ i) {
		rd(a), rd(b);
		if (id[a] != id[b]) puts("-1");
		else if (a == b) puts("0");
		else puts(st[id[a]] ? "1" : cl[a] == cl[b] ? "2" : "1");
	}
	return 0;
}
