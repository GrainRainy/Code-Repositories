#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, w[N], pre[N], suf[N];
long long ans;
struct Node {
	int id, v;
	bool operator < (const Node &t) const { return v < t.v; }
};
priority_queue<Node> q;
bool st[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

int main() {
	rd(n), rd(k);
	if (k > n >> 1) return puts("Error!") & 0;
	for (int i = 1; i <= n; ++ i) {
		rd(w[i]), pre[i] = i - 1, suf[i] = i + 1;
		q.push({i, w[i]});
	}
	suf[n] = 1, pre[1] = n;
	while (k) {
		int u = q.top().id; q.pop();
		if (st[u]) continue;
		k --, st[pre[u]] = st[suf[u]] = true;
		ans += w[u], w[u] = w[pre[u]] + w[suf[u]] - w[u];
		pre[u] = pre[pre[u]], suf[u] = suf[suf[u]];
		suf[pre[u]] = pre[suf[u]] = u;
		q.push({u, w[u]});
	}
	return cout << ans << '\n', 0;
}
