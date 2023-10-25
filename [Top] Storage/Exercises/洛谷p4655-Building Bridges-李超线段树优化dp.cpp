#include <bits/stdc++.h>
#define l(u) ((u) << 1)
#define r(u) ((u) << 1 | 1)
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
LL n, h[N], w[N], f[N], k[N], b[N];
int t[M << 2];
LL val(int id, int x) { return k[id] * x + b[id]; }

void add(int u, int tl, int tr, int id) {
	if (tl == tr) return t[u] = val(id, tl) < val(t[u], tl) ? id : t[u], void();
	int mid = tl + tr >> 1;
	if (val(id, mid) < val(t[u], mid)) swap(t[u], id);
	if (val(id, tl) < val(t[u], tl)) add(l(u), tl, mid, id);
	else if (val(id, tr) < val(t[u], tr)) add(r(u), mid + 1, tr, id);
}

LL query(int u, int tl, int tr, int p) {
	if (tl == tr) return val(t[u], p);
	int m = tl + tr >> 1;
	LL res = p <= m ? query(l(u), tl, m, p) : query(r(u), m + 1, tr, p);
	return min(val(t[u], p), res);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, b[0] = 1e18;
	for (int i = 1; i <= n; ++ i) cin >> h[i];
	for (int i = 1; i <= n; ++ i) cin >> w[i], w[i] += w[i - 1];
	k[1] = -2 * h[1], b[1] = h[1] * h[1] - w[1], add(1, 0, M, 1);
	for (int i = 2; i <= n; ++ i) {
		f[i] = h[i] * h[i] + w[i - 1] + query(1, 0, M, h[i]);
		k[i] = -2 * h[i], b[i] = f[i] + h[i] * h[i] - w[i], add(1, 0, M, i);
	}
	return cout << f[n] << '\n', 0;
}
