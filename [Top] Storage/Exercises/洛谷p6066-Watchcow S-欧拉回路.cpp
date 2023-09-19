#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e4 + 10;
const int M = 5e4 + 10;
int n, m, head[N], idx;
struct Node { int nxt, to; }edge[M << 1];
int stk[M << 1], top;
bool st[M << 1];

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

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u) {
	for (int &i = head[u]; i; i = edge[i].nxt)
		if (!st[i]) st[i] = true, dfs(edge[i].to);
	stk[++ top] = u;
} 

int main() {
	rd(n), rd(m);
	for (int i = 1, a, b; i <= m; ++ i) rd(a), rd(b), add(a, b), add(b, a);
	dfs(1);
	while (top) ot(stk[top --]);
	return 0;
}
