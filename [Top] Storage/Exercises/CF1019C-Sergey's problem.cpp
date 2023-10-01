#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, head[N], idx, cnt;
struct Node { int nxt, to; }edge[N];
bool st[2][N];

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

int main() {
	rd(n), rd(m);
	for (int i = 1, a, b; i <= m; ++ i) rd(a), rd(b), add(a, b);
	for (int i = 1; i <= n; ++ i) {
		if (st[0][i]) continue;
		st[0][i] = st[1][i] = true, cnt ++;
		for (int j = head[i]; j; j = edge[j].nxt) st[0][edge[j].to] = true;
	}
	for (int i = n; i; -- i) {
		if (!st[1][i]) continue;
		for (int j = head[i]; j; j = edge[j].nxt) 
			if (st[1][edge[j].to]) cnt --, st[1][edge[j].to] = false;
	}
	ot(cnt);
	for (int i = 1; i <= n; ++ i) if (st[1][i]) ot(i, ' ');
	return putchar('\n'), 0;
}
