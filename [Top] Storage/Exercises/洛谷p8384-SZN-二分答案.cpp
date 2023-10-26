#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, res[N], dg[N], c, sa, head[N], etp, l = 1, r, mid;
struct Node { int nxt, to; }edge[N << 1];

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void dfs(int u, int fa) {
	vector<int> val; res[u] = 0;
	for (int i = head[u], v; ~i; i = edge[i].nxt) {
		if ((v = edge[i].to) == fa) continue;
		dfs(v, u);
		val.emplace_back(res[v] + 1);
	}
	sort(val.begin(), val.end());
	int l = 0, r = val.size() - 1;
	while (l <= r) {
		if (l < r and val[l] + val[r] <= mid) c ++, l ++, r --;
		else if (val[r] >= mid) c ++, r --;
		else if (!res[u]) res[u] = val[r --];
		else c ++, res[u] = val[r --];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, r = n - 1;
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i)
		cin >> a >> b, add(a, b), add(b, a), dg[a] ++, dg[b] ++;
	for (int i = 1; i <= n; ++ i) sa -= dg[i] / 2;
	while (l < r) {
		mid = l + r >> 1, c = 0;
		dfs(1, 0);
		c + (bool)res[1] > sa + n - 1 ? l = mid + 1 : r = mid;
	}
	return cout << sa + n - 1 << ' ' << l << '\n', 0;
}
