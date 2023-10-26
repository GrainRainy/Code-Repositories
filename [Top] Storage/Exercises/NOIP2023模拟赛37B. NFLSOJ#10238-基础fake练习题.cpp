#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
namespace IO{
	template<typename T> inline void rd(T &x){
		x=0;bool f=0;char c=0;
		while(c<'0'||c>'9') f|=c=='-',c=getchar();
		while('0'<=c&&c<='9') x=x*10+(c^48),c=getchar();
		x=f?-x:x;
	}
	template<typename T,typename ...Args> inline void rd(T &x,Args &...args){rd(x),rd(args...);}
	template<typename T> inline void wt(char c,T x){
		int stk[114],top=0;
		if(x<0) x=-x,putchar('-');
		do stk[++top]=x%10,x/=10; while(x);
		while(top) putchar(stk[top--]+'0');
		putchar(c);
	}
	template<typename T,typename ...Args> inline void wt(char c,T x,Args ...args){wt(c,x),wt(c,args...);}
	template<typename T,typename ...Args> inline void wt(char s,char c,T x,Args ...args){wt(c,x),wt(c,args...),putchar(s);}
};
using namespace IO;
using namespace std;
const int N = 3e5 + 10;
int n, m, ans, c[N], head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
int siz[N], fa[N], dep[N], hs[N], dfn[N], nc[N], top[N], stamp;
struct SegmentTree { int mn, tg; }tree[N << 2];
#define l(u) ((u) << 1)
#define r(u) ((u) << 1 | 1)
#define tg(x) tree[x].tg
#define mn(x) tree[x].mn
vector<int> dn[N];

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void dfs1(int u, int father, int depth) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == father) continue;
		dfs1(v, u, depth + 1);
		siz[u] += siz[v];
		if (siz[v] > siz[hs[u]]) hs[u] = v;
	}
}

void dfs2(int u, int t) {
	top[u] = t, dfn[u] = ++ stamp, nc[stamp] = c[u];
	if (hs[u]) dfs2(hs[u], t);
	for (int i = head[u], v; ~i; i = edge[i].nxt) 
		if (!top[v = edge[i].to]) dfs2(v, v);
}

void pushdown(int u) {
	mn(l(u)) += tg(u), mn(r(u)) += tg(u);
	tg(l(u)) += tg(u), tg(r(u)) += tg(u);
	return tg(u) = 0, void();
}

void build(int u, int tl, int tr) {
	if (tl == tr) return mn(u) = nc[tl], void();
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
	mn(u) = min(mn(l(u)), mn(r(u)));
}

void modify(int u, int tl, int tr, int l, int r, int v) {
	if (l <= tl and tr <= r) return mn(u) += v, tg(u) += v, void();
	int mid = tl + tr >> 1;
	if (tg(u)) pushdown(u);
	if (l <= mid) modify(l(u), tl, mid, l, r, v);
	if (r > mid) modify(r(u), mid + 1, tr, l, r, v);
	mn(u) = min(mn(l(u)), mn(r(u)));
}

int query(int u, int tl, int tr, int l, int r) {
	if (tl > r or tr < l) return 0x3f3f3f3f;
	if (l <= tl and tr <= r) return mn(u);
	int mid = tl + tr >> 1;
	if (tg(u)) pushdown(u);
	return min(query(l(u), tl, mid, l, r), query(r(u), mid + 1, tr, l, r));
}

void updPath(int a, int b, int v) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		modify(1, 1, n, dfn[top[a]], dfn[a], v), a = fa[top[a]];
	}
	if (dep[a] < dep[b]) swap(a, b);
	return modify(1, 1, n, dfn[b], dfn[a], v);
}

int qryPath(int a, int b) {
	int res = 0x3f3f3f3f;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		res = min(res, query(1, 1, n, dfn[top[a]], dfn[a])), a = fa[top[a]];
	}
	if (dep[a] < dep[b]) swap(a, b);
	return min(res, query(1, 1, n, dfn[b], dfn[a]));
}

bool cmp(const int &a, const int &b) { return dep[a] < dep[b]; }
void calc(int u) {
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if ((v = edge[i].to) != fa[u]) calc(v);
	sort(dn[u].begin(), dn[u].end(), cmp);
	for (auto t : dn[u]) if (qryPath(u, t)) ans ++, updPath(u, t, -1);
	return;
}

int main() {
	freopen("fake.in", "r", stdin);
	freopen("fake.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> c[i], head[i] = -1;
	for (int i = 1, a, b; i < n; ++ i)
		cin >> a >> b, add(a, b), add(b, a);
	dfs1(1, 0, 1), dfs2(1, 1);
	for (int i = 1, a, b; i <= m; ++ i) {
		cin >> a >> b;
		if (dep[a] > dep[b]) swap(a, b);
		dn[a].emplace_back(b);
	}
	build(1, 1, n), calc(1);
	return cout << ans << '\n', 0;
}
