#include <bits/stdc++.h>
#define DEBUG  cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 3e3 + 10;
int n, k, fa[N];
struct Segment { int l, r, v; }seg[N];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

namespace sub1 {
	int siz[N], ans = 0x3f3f3f3f, res;
	void solve() {
		for (int s = 0; s < 1 << n; ++ s) {
			for (int i = 1; i <= n; ++ i) fa[i] = i, siz[i] = 1;
			for (int i = 1; i <= n; ++ i) {
				if ((s >> i - 1) & 1) continue;
				for (int j = 1; j <= n; ++ j) {
					if (i == j) continue;
					if ((s >> j - 1) & 1) continue;
					if (seg[i].l > seg[j].r or seg[i].r < seg[j].l) continue;
					int x = find(i), y = find(j);
					if (x != y) fa[y] = x, siz[x] += siz[y];
				}
			}
			bool f = true;
			for (int i = 1; i <= n; ++ i) if (siz[i] > k) { f = false; break; }
			if (!f) continue;
			for (int i = 1; i <= n; ++ i) if ((s >> i - 1) & 1) res += seg[i].v;
			ans = min(ans, res), res = 0;
		}
		cout << ans << '\n';
	}
}

namespace sub2 {
	int mxv[N], ans;
	void solve() {
		for (int i = 1; i <= n; ++ i) fa[i] = i, mxv[i] = seg[i].v, ans += seg[i].v;
		for (int i = 1; i <= n; ++ i) 
			for (int j = 1; j <= n; ++ j) {
				if (i == j) continue;
				if (seg[i].l > seg[j].r or seg[i].r < seg[j].l) continue;
				int x = find(i), y = find(j);
				if (x != y) fa[y] = x, mxv[x] = max(mxv[x], mxv[y]);
			}
		for (int i = 1; i <= n; ++ i) if (find(i) == i) ans -= mxv[i];
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) cin >> seg[i].l >> seg[i].r >> seg[i].v;
//	if (n <= 20) 
		return sub1::solve(), 0;
	if (k == 1) return sub2::solve(), 0;
}
