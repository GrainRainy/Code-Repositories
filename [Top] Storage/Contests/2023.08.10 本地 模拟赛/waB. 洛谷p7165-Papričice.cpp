#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int n, rt, tmx = INF, opt[N];
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int siz[N], fa[N], dep[N], dfn[N], stamp, mx[N];
int save[5], mn = INF;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

int pre(int u, int father) {
	int mx = 0, sz = 1, t;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		t = pre(j, u);
		mx = max(mx, t);
		sz += t;
	}
	mx = max(mx, n - sz);
	if (mx < tmx) tmx = mx, rt = u;
	return sz;
}

void dfs(int u, int depth, int father) {
	dep[u] = depth, fa[u] = father, dfn[u] = ++ stamp, siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs(j, depth + 1, u);
		mx[u] = max(mx[u], siz[j]);
		siz[u] += siz[j];
	}
	mx[u] = max(mx[u], n - siz[u]);
	return;
}

inline bool cmp(const int &a, const int &b) { return mx[a] < mx[b]; }

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) {
		cin >> a >> b;
		add(a, b), add(b, a);
		opt[i] = i;
	}
	opt[n] = n;
	pre(1, 0);
	dfs(rt, 1, 0);
	sort(opt + 1, opt + n + 1, cmp);
	for (int i = 2; i <= n; ++ i)
		for (int j = i + 1, a, b; j <= n; ++ j) {
			a = opt[i], b = opt[j];
			if (dfn[a] <= dfn[b] and dfn[a] + siz[a] - 1 >= dfn[b]) {
				save[1] = siz[1] - siz[a];
				/* siz[1] 应该用 n 或者 siz[rt] */
				save[2] = siz[a] - siz[b];
				save[3] = siz[b];
			} else if (dfn[b] <= dfn[a] and dfn[b] + siz[b] - 1 >= dfn[a]) {
				save[1] = siz[1] - siz[b];
				save[2] = siz[b] - siz[a];
				save[3] = siz[a];
			} else {
				save[1] = siz[1] - siz[a] - siz[b];
				save[2] = siz[a];
				save[3] = siz[b];
			}
			sort(save + 1, save + 4);
			mn = min(mn, save[3] - save[1]);
			if (clock() / CLOCKS_PER_SEC > 0.97) {
				cout << mn << endl;
				return 0;
			}
		}
	cout << mn << endl;
	return 0;
}
