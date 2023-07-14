#include <bits/stdc++.h>
#define ls (u << 1)
#define rs (u << 1 | 1)
#define fi first
#define se second
#define DEBUG cerr << "-- DEBUG --" << endl;
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
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
using PLI = pair<LL, int>;
const int N = 1e5 + 10;
const int GAP = 4e5 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, q, s;
int head[N << 3], idx;
struct Node { int nxt, to, w; }edge[N * 21];
int leaf[N];
LL dist[N << 3];
bool st[N << 3];

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void build(int u, int tl, int tr) {
	if (tl == tr) {
		leaf[tl] = u;
		add(u, u + GAP, 0), add(u + GAP, u, 0);
		return;
	}
	add(u, ls, 0), add(u, rs, 0);
	add(ls + GAP, u + GAP, 0), add(rs + GAP, u + GAP, 0);
	int mid = tl + tr >> 1;
	build(ls, tl, mid), build(rs, mid + 1, tr);
}

void connect(int u, int tl, int tr, int l, int r, int v, int w, bool type) {
	if (tl >= l and tr <= r) {
		if (type) add(u + GAP, leaf[v], w);
		else add(leaf[v], u, w);
		return;
	}
	int mid = tl + tr >> 1;
	if (r <= mid) connect(ls, tl, mid, l, r, v, w, type);
	else if (l > mid) connect(rs, mid + 1, tr, l, r, v, w, type);
	else connect(ls, tl, mid, l, mid, v, w, type), 
		 connect(rs, mid + 1, tr, mid + 1, r, v, w, type);
}

void dijkstra(int bg) {
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PLI, vector<PLI>, greater<PLI>> q;
	dist[bg] = 0, q.push({0, bg});
	while (q.size()) {
		int u = q.top().se; q.pop();
		if (st[u]) continue;
		st[u] = true;
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (dist[j] > dist[u] + edge[i].w) {
				dist[j] = dist[u] + edge[i].w;
				q.push({dist[j], j});
			}
		}
	}
}

int main() {
	input(n), input(q), input(s);
	memset(head, -1, sizeof head);
	build(1, 1, n);
	for (int i = 1, op, u, v, w, l, r; i <= q; ++ i) {
		input(op);
		if (op == 1) {
			input(v), input(u), input(w);
			add(leaf[v], leaf[u], w);
		} else {
			input(v), input(l), input(r), input(w);
			connect(1, 1, n, l, r, v, w, op & 1);
		}
	}
	dijkstra(leaf[s] + GAP);
	for (int i = 1; i <= n; ++ i)
		output(dist[leaf[i]] == INF ? -1 : dist[leaf[i]], " \n"[i == n]);
	return 0;
}
