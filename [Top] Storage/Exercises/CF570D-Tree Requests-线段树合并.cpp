#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 5e5 + 10;
int n, m, fa[N], head[N], dep[N], idx, ttp;
struct Node { int nxt, to; }edge[N];
struct SegmentTree { int l, r, s, cnt; }tree[N * 20];
#define l(x) tree[x].l
#define r(x) tree[x].r
#define s(x) tree[x].s
#define cnt(x) tree[x].cnt
vector<pair<int, int>> q[N];
bool ans[N];
char s[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a], edge[head[a] = idx].to = b;
}

void dfs(int u, int depth) {
	dep[u] = depth;
	for (int i = head[u]; ~i; i = edge[i].nxt) dfs(edge[i].to, depth + 1);
}

int insert(int tl, int tr, int pos, int tp) {
	int u = ++ ttp;
	if (tl == tr) return s(u) ^= 1 << tp, cnt(u) ++, u;
	int mid = tl + tr >> 1;
	if (pos <= mid) l(u) = insert(tl, mid, pos, tp);
	else r(u) = insert(mid + 1, tr, pos, tp);
	return u;
}

int merge(int x, int y, int tl, int tr) {
	if (!x or !y) return x | y;
	if (tl == tr) {
		s(x) ^= s(y), cnt(x) = 0;
		for (int i = 0; i < 26; ++ i)
			if (s(x) >> i & 1) cnt(x) ++;
		return x;
	}
	int mid = tl + tr >> 1;
	l(x) = merge(l(x), l(y), tl, mid);
	r(x) = merge(r(x), r(y), mid + 1, tr);
	return x;
}

int query(int u, int tl, int tr, int pos) {
	if (tl == tr) return cnt(u);
	int mid = tl + tr >> 1;
	if (pos <= mid) return query(l(u), tl, mid, pos);
	else return query(r(u), mid + 1, tr, pos);
}

int solve(int u) {
	int tru = insert(1, n, dep[u], s[u] - 'a');
	for (int i = head[u]; ~i; i = edge[i].nxt)
		merge(tru, solve(edge[i].to), 1, n);
	if (q[u].size()) for (auto t : q[u])
		ans[t.second] = query(tru, 1, n, t.first) < 2;
	return tru;
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 2; i <= n; ++ i) rd(fa[i]), add(fa[i], i);
	cin >> s + 1;
	for (int i = 1, a, b; i <= m; ++ i) rd(a), rd(b), q[a].push_back({b, i});
	dfs(1, 1);
	solve(1);
	for (int i = 1; i <= m; ++ i) puts(ans[i] ? "Yes" : "No");
	return 0;
}
