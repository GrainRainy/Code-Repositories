#include <bits/stdc++.h>
#define fi first
#define se second
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e5 + 10;
char s[N << 1];
int sp, m, ans[N];
vector<pair<int, int>> q[N];
int tr[N][26], cp[N][26], ed[N], id[N], etp;
int fail[N], ttp, head[N], idx;
struct Node { int nxt, to; }edge[N];
int dfn[N], siz[N], stamp;

struct BIT {
	int tr[N];
	inline void add(int p, int v) { while (p <= stamp) tr[p] += v, p += p & -p; }
	int query(int r) { int res = 0; while (r) res += tr[r], r -= r & -r; return res; }
}t;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void insert(int u) {
	while (s[sp] == 'P') ed[u] = ++ etp, id[etp] = u, sp ++;
	while (s[sp] and s[sp] != 'B') {
		int sn = s[sp] - 'a'; sp ++;
		if (!tr[u][sn]) cp[u][sn] = tr[u][sn] = ++ ttp;
		insert(tr[u][sn]);
	}
	sp ++;
}

void build() {
	queue<int> q;
	for (int i = 0; i < 26; ++ i) if (tr[0][i]) q.push(tr[0][i]);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; ++ i) {
			if (!tr[u][i]) tr[u][i] = tr[fail[u]][i];
			else fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
		}
	}
	for (int i = 1; i <= ttp; ++ i) add(fail[i], i);
}

void init(int u) {
	dfn[u] = ++ stamp, siz[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt)
		init(edge[i].to), siz[u] += siz[edge[i].to];
}

void dfs(int u) {
	t.add(dfn[u], 1);
	if (ed[u]) {
		for (auto tmp : q[u]) 
			ans[tmp.se] = t.query(dfn[tmp.fi] + siz[tmp.fi] - 1) - t.query(dfn[tmp.fi] - 1);
	}
	for (int i = 0; i < 26; ++ i) if (cp[u][i]) dfs(cp[u][i]);
	t.add(dfn[u], -1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s >> m;
	memset(head, -1, sizeof head);
	insert(0), build();
	for (int i = 1, x, y; i <= m; ++ i) {
		cin >> x >> y;
		q[id[y]].push_back({id[x], i});
	} 
	init(0), dfs(0);
	for (int i = 1; i <= m; ++ i) cout << ans[i] << '\n';
	return 0;
}
