#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 3e5 + 10;
int n, l, r, mid, head[N], etp, dg[N], f[N];
struct Node { int nxt, to; }edge[N << 1];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b) {
	edge[++ etp] = {head[a], b};
	head[a] = etp;
}

void dp(int u, int fa) {
	f[u] = dg[u] - (bool)fa - mid;
	for (int i = head[u], v; ~i; i = edge[i].nxt)
		if ((v = edge[i].to) != fa)
			dp(v, u), f[u] += max(0, f[v]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) {
		cin >> a >> b, dg[a] ++, dg[b] ++;
		r = max({r, dg[a], dg[b]});
		add(a, b), add(b, a);
	}
	l = dg[1];
	while (l < r) {
		mid = l + r >> 1, dp(1, 0);
		if (f[1] <= 0) r = mid;
		else l = mid + 1;
	}
	return cout << l << '\n', 0;
}
