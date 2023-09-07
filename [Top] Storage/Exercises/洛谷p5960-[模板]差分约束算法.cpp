#include <bits/stdc++.h>
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

using namespace std;
const int N = 5e3 + 10;
int n, m, head[N], idx;
struct Node { int nxt, to, w; }edge[N];
int dis[N], cnt[N];
bool st[N];

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

bool spfa() {
	queue<int> q;
	for (int i = 1; i <= n; ++ i) q.push(i), st[i] = true;
	while (q.size()) {
		int u = q.front(); q.pop(); st[u] = false;
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (dis[j] > dis[u] + edge[i].w) {
				dis[j] = dis[u] + edge[i].w;
				if (!st[j]) st[j] = true, q.push(j), cnt[j] ++;
				if (cnt[j] > n) return false;
			}
		}
	}
	return true;
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, x, y, z; i <= m; ++ i)
		rd(x), rd(y), rd(z), add(y, x, z);
	if (!spfa()) return puts("NO") & 0;
	for (int i = 1; i <= n; ++ i) ot(dis[i], ' ');
	return 0;
}
