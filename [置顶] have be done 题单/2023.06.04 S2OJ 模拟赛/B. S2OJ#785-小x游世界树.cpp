#include <bits/stdc++.h>

#define __DEBUG__ puts("__DEBUG__");

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
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed); 
	}
}

using namespace IO;
using namespace std;
using LL = long long;

const int N = 7e5 + 10;
int n, w[N];
int head[N], idx;
struct Node {
	int nxt, to, w;
}edge[N << 1];
// grpah
int siz[N];
LL f[N];
LL mn = 0x3f3f3f3f3f3f3f3f, id;

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

void dfs1(int u, int fa) {
	siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		dfs1(j, u);
		siz[u] += siz[j];
		f[u] += f[j] + (edge[i].w - w[u]) * siz[j];
	}
	return;
} 

void dfs2(int u, int fa) {
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		f[j] += (f[u] - f[j] - (edge[i].w - w[u]) * siz[j]) + (edge[i].w - w[j]) * (siz[1] - siz[j]);
		dfs2(j, u);
	}
}

int main() {
	input(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= n; ++ i) input(w[i]);
	for (int i = 1, a, b, c; i < n; ++ i) {
		input(a), input(b), input(c);
		add(a, b, c), add(b, a, c);
	}
	
	dfs1(1, 0);
	dfs2(1, 0);
	
	for (int i = 1; i <= n; ++ i) 
		if (f[i] < mn) mn = f[i], id = i;
	output(id); output(mn);
	return 0;
}
