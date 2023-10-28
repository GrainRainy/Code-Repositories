#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e4 + 10;
const int L = 9e4;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, st, ed;
struct Range {
	int l, r, c;
	bool operator < (const Range &t) const { return r < t.r; }
}r[N];
struct Fenwick {
	LL tr[L + 10];
	inline void add(int p, LL v) { while (p <= L) tr[p] = min(tr[p], v), p += p & -p; }
	LL query(int p) { LL r = INF; while (p) r = min(r, tr[p]), p -= p & -p; return r; }
}t;
LL f[N], ans = INF;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> st >> ed;
	memset(t.tr, 0x3f, sizeof t.tr);
	for (int i = 1; i <= n; ++ i) cin >> r[i].l >> r[i].r >> r[i].c;
	sort(r + 1, r + n + 1);
	for (int i = 1; i <= n; ++ i) {
		f[i] = r[i].c + (r[i].l > st ? t.query(L - r[i].l + 1) : 0);
		t.add(L - r[i].r, f[i]);
		if (r[i].r >= ed) ans = min(ans, f[i]);
	}
	return cout << (ans == INF ? -1 : ans) << '\n', 0;
}
