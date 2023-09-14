#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
#define DEBUG cerr << "-- DEBUG --\n";
namespace IO {
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
}

using namespace IO;
using namespace std;
const int N = 5e4 + 10;
int t, n, head[N], idx;
struct Node { int nxt, to, w; }edge[N << 2];
int mx, dis[N];
bool st[N];

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = c;
	edge[head[a] = idx].to = b;
}

void spfa() {
	queue<int> q;
	for (int i = 1; i <= mx; ++ i) q.push(i), dis[i] = 0, st[i] = true;
	while (q.size()) {
		int u = q.front(); q.pop(), st[u] = false;
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (dis[j] < dis[u] + edge[i].w) {
				dis[j] = dis[u] + edge[i].w;
				if (!st[j]) q.push(j), st[j] = true;
			}
		}
	}
}

void solve() {
	rd(n);
	for (int i = 1, a, b, c; i <= n; ++ i, mx = max(mx, b + 1)) 
		rd(a), rd(b), rd(c), add(a, b + 1, c);
	for (int i = 1; i <= mx; ++ i) add(i - 1, i, 0), add(i, i - 1, -1);
	spfa(), ot(dis[mx]);
	memset(st, 0, sizeof(bool) * (mx + 10));
	memset(head, -1, sizeof(int) * (mx + 10));
	mx = idx = 0;
}

int main() {
	rd(t);
	memset(head, -1, sizeof head);
	while (t --) {
		solve();
		if (t) putchar('\n'); 
	}
	return 0;
}

