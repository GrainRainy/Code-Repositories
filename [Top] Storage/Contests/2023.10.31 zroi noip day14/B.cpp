#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, c, head[N], etp;
struct Node { int nxt, to; }edge[N << 1];
bool st[N];

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

bool dfs(int u, int fa) {
	st[u] = true;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == fa) continue;
		if (st[v]) return true;
		if (dfs(v, u)) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(head, -1, sizeof head);
	for (int i = 1, a, b; i <= m; ++ i) {
		cin >> a >> b;
		if (a != b) add(a, b), add(b, a);
	}
	for (int i = 1; i <= n; ++ i) 
		if (!st[i] and dfs(i, 0)) return puts("Yes") & 0;
	return puts("No") & 0;
}
