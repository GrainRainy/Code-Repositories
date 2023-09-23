#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 10;
const int L = 1e6 + 10;
int n, tr[L][26], fail[L], node[N], sm[L], ttp;
int head[L], idx;
struct Node { int nxt, to; }edge[L];
string s[N];

void insert(string s, int id) {
	int p = 0;
	for (auto t : s) {
		if (!tr[p][t - 'a']) tr[p][t - 'a'] = ++ ttp;
		p = tr[p][t - 'a'], sm[p] ++;
	}
	node[id] = p;
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
}

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u) {
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		dfs(v = edge[i].to), sm[u] += sm[v];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> s[i], insert(s[i], i);
	build();
	memset(head, -1, sizeof(int) * (ttp + 10));
	for (int i = 1; i <= ttp; ++ i) add(fail[i], i);
	dfs(0);
	for (int i = 1; i <= n; ++ i) cout << sm[node[i]] << '\n';
	return 0;
}
