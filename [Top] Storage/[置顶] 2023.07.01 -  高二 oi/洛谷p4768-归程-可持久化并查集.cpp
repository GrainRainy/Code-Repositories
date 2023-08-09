#include <bits/stdc++.h>
#define fi first
#define se second
#define __DEBUG__ puts("__DEBUG__");
#define debug(x) cout << #x << ' ' << x << endl;
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
using PII = pair<int, int>;
const int N = 2e5 + 10;
const int M = 4e5 + 10;
const int LOGM = 20;
int n, m, q, k, s, ans;
int head[N], idx;
struct Node { int nxt, to, w; }edge[M << 1];
int dis[N]; bool st[N];
// the shortest path 
struct Save {
	int u, v, a;
	bool operator < (const Save &t) const {
		return a > t.a;
	}
}save[M];
int version[M];
int tot, rtfa[M], rtdep[M], rtmn[M];
struct Persistable {
	int l, r, val;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define val(x) tree[x].val
}tree[M * LOGM * 3];
// persistable dsu 

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void dijkstra(int u) {
	memset(st, 0, sizeof(bool) * (n + 10));
	memset(dis, 0x3f, sizeof(int) * (n + 10));
	priority_queue<PII, vector<PII>, greater<PII>> q;
	dis[u] = 0; q.push({0, u});
	while (q.size()) {
		int ver = q.top().se; q.pop();
		if (st[ver]) continue;
		st[ver] = true;
		for (int i = head[ver], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (dis[j] > dis[ver] + edge[i].w) {
				dis[j] = dis[ver] + edge[i].w;
				q.push({dis[j], j});
			}
		}
	}
}

void build(int &u, int tl, int tr, bool type) {
	u = ++ tot;
	if (tl == tr and !type) return val(u) = tl, void();
	else if (tl == tr and type) return val(u) = dis[tl], void();
	int mid = tl + tr >> 1;
	build(l(u), tl, mid, type), build(r(u), mid + 1, tr, type);
}

void modify(int &u, int pre, int tl, int tr, int pos, int val) {
	u = ++ tot; tree[u] = tree[pre];
	if (tl == tr) return val(u) = val, void();
	int mid = tl + tr >> 1;
	if (pos <= mid) modify(l(u), l(pre), tl, mid, pos, val);
	else modify(r(u), r(pre), mid + 1, tr, pos, val);
}

int query(int u, int tl, int tr, int pos) {
	if (tl == tr) return val(u);
	int mid = tl + tr >> 1;
	if (pos <= mid) return query(l(u), tl, mid, pos);
	else return query(r(u), mid + 1, tr, pos);
}

int find(int ver, int x) {
	int tmp = query(rtfa[ver], 1, n, x);
	return x == tmp ? x : x = find(ver, tmp);
}

void merge(int now, int pre, int a, int b) {
	a = find(pre, a);
	b = find(pre, b);
	if (a == b) {
		rtfa[now] = rtfa[pre];
		rtdep[now] = rtdep[pre];
		rtmn[now] = rtmn[pre];
	} else {
		int depa = query(rtdep[pre], 1, n, a);
		int depb = query(rtdep[pre], 1, n, b);
		int mna = query(rtmn[pre], 1, n, a);
		int mnb = query(rtmn[pre], 1, n, b);
		if (depa == depb) {
			modify(rtfa[now], rtfa[pre], 1, n, a, b);
			modify(rtdep[now], rtdep[pre], 1, n, b, depb + 1);
			modify(rtmn[now], rtmn[pre], 1, n, b, min(mna, mnb));
		} else {
			if (depa > depb) swap(depa, depb), swap(a, b);
			modify(rtfa[now], rtfa[pre], 1, n, a, b);
			modify(rtmn[now], rtmn[pre], 1, n, b, min(mna, mnb));
			rtdep[now] = rtdep[pre];
		}
	}
}

void solve() {
	input(n), input(m);
	memset(head, -1, sizeof(int) * (n + 10));
	ans = tot = idx = 0;
	for (int i = 1, u, v, l, a; i <= m; ++ i) {
		input(u), input(v), input(l), input(a);
		save[i] = {u, v, a};
		add(u, v, l), add(v, u, l);
	}
	dijkstra(1);
	sort(save + 1, save + 1 + m);
	build(rtfa[0], 1, n, false), build(rtmn[0], 1, n, true);
	for (int i = 1; i <= m; ++ i) {
		merge(i, i - 1, save[i].u, save[i].v);
		version[i] = save[i].a;
	}
	input(q), input(k), input(s);
	for (int i = 1, v, p; i <= q; ++ i) {
		input(v), input(p);
		v = (v + ans * k - 1) % n + 1;
		p = (p + ans * k) % (s + 1);
		int ver = lower_bound(version + 1, version + 1 + m, p, greater<int>()) - 1 - version;
		ans = query(rtmn[ver], 1, n, find(ver, v));
		output(ans);
	}
	return void();
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("return6.in", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif
	int t; input(t);
	while (t --) solve();
	return 0;
}
