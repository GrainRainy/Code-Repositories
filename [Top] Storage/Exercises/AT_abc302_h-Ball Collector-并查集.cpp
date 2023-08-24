#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
const int N = 2e5 + 10;
int n, a[N], b[N], ans[N];
int head[N], idx;
int fa[N], siz[N], presm;
struct Save { int a; bool b, c; };
struct Node { int nxt, to; }edge[N << 1];
bool st[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

int find(int x) { return (x == fa[x]) ? x : find(fa[x]); }

void dfs(int u, int father) {
	ans[u] = presm;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		int fax = find(a[j]), fay = find(b[j]);
		if (siz[fax] < siz[fay]) swap(fax, fay);
		if (fax == fay) {
			if (!st[fax]) {
				presm ++, st[fax] = true;
				dfs(j, u);
				st[fax] = false, presm --;
			} else dfs(j, u);
		} else {
			int nsiz = siz[fax];
			bool tsx = st[fax], tsy = st[fay];
			fa[fay] = fax, siz[fax] += siz[fay];
			st[fax] = tsx | tsy;
			if (!tsx || !tsy) presm ++;
			dfs(j, u);
			fa[fay] = fay, siz[fax] = nsiz;
			st[fay] = tsy, st[fax] = tsx;
			if (!tsx || !tsy) presm --;
		}
	}
}

int main() {
//	freopen("test.in", "r", stdin);
	input(n);
	memset(head, -1, sizeof head);
	for (int i = 1; i <= n; ++ i) {
		input(a[i]), input(b[i]);
		fa[i] = i, siz[i] = 1;	
	}
	for (int i = 1, a, b; i < n; ++ i) {
		input(a), input(b);
		add(a, b), add(b, a);
	}
	presm = 1;
	int nu = a[1], nv = b[1];
	if (nu == nv) st[nu] = 1;
	else fa[nv] = nu, siz[nu] += siz[nv];
	dfs(1, 0);
	for (int i = 2; i <= n; ++ i) output(ans[i], " \n"[i == n]);
	return 0;
}

