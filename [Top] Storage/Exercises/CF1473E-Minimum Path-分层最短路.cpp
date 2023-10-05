#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PLI = pair<LL, int>;
const int N = 2e5 + 10;
int n, m, head[N << 2], idx;
struct Node { int nxt, to, w; }edge[N * 18];
LL dis[N << 2];
bool st[N << 2];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void djikstra() {
	priority_queue<PLI, vector<PLI>, greater<PLI>> q;
	memset(dis, 0x3f, sizeof(LL) * ((n << 2) + 10));
	dis[1] = 0, q.push({0, 1});
	while (q.size()) {
		int u = q.top().second; q.pop();
		if (st[u]) continue;
		st[u] = true;
		for (int i = head[u], v; ~i; i = edge[i].nxt) {
			v = edge[i].to;
			if (dis[v] > dis[u] + edge[i].w) {
				dis[v] = dis[u] + edge[i].w;
				q.push({dis[v], v});
			}
		}
	}
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * ((n << 2) + 10));
	for (int i = 1, a, b, w; i <= m; ++ i) {
		rd(a), rd(b), rd(w);
		add(a, b, w), add(b, a, w), add(a + n, b + n, w), add(b + n, a + n, w);
		add(a + n * 2, b + n * 2, w), add(b + n * 2, a + n * 2, w);
		add(a + n * 3, b + n * 3, w), add(b + n * 3, a + n * 3, w);
		add(a, b + n, 0), add(b, a + n, 0);
		add(a, b + n * 2, w << 1), add(b, a + n * 2, w << 1);
		add(a, b + n * 3, w), add(b, a + n * 3, w);
		add(a + n, b + n * 3, w << 1), add(b + n, a + n * 3, w << 1);
		add(a + n * 2, b + n * 3, 0), add(b + n * 2, a + n * 3, 0);
	}
	djikstra();
	for (int i = 2; i <= n; ++ i) ot(dis[i + n * 3], " \n"[i == n]);
	return 0;
}
