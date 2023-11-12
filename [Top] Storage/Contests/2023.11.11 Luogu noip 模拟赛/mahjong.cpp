#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 2e5 + 10;
int n, m, k, a[N], x, y, l, r;
vector<int> ps[N];

namespace sub2 {
	bool sol() { // beginner win or not 
		auto it = lower_bound(ps[x].begin(), ps[x].end(), l);
		return (*it - l + 1) & 1;
	}
}

namespace sub1 {
	int dfs(int pos, bool per) { // 1->alice, 0->D, -1->bob; 1->alic, 0->bob 
		if (pos > r) return 0;
		if (x == y) {
			auto it = lower_bound(ps[x].begin(), ps[x].end(), pos);
			if (it == ps[x].end() or *it > r) return 0;
			if (sub2::sol()) return per ? 1 : -1;
			return per ? -1 : 1;
		} else if (per) {
			int state = -1, tmpx = x;
			if (a[pos] == x) return 1;
			if (a[pos] != y) state = max(state, dfs(pos + 1, 0));
			if (x != y) x = a[pos], state = max(state, dfs(pos + 1, 0)), x = tmpx;
			return state;
		} else {
			int state = 1, tmpy = y;
			if (a[pos] == y) return -1;
			if (a[pos] != x) state = min(state, dfs(pos + 1, 1));
			if (x != y) y = a[pos], state = min(state, dfs(pos + 1, 1)), y = tmpy;
			return state;
		}
	}
}

int main() {
	freopen("mahjong.in", "r", stdin);
	freopen("mahjong.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], ps[a[i]].emplace_back(i);
	for (int i = 1; i <= m; ++ i) {
		cin >> x >> y >> l >> r;
		if (x == y) {
			auto it = lower_bound(ps[x].begin(), ps[x].end(), l);
			if (it == ps[x].end() or *it > r) puts("D");
			else if (sub2::sol()) puts("A");
			else puts("B");
		} else if (k == 2) {
			if (a[l] == x) puts("A");
			else {
				x = a[l ++];
				auto it = lower_bound(ps[x].begin(), ps[x].end(), l);
				if (it == ps[x].end() or *it > r) puts("D");
				else if (sub2::sol()) puts("B");
				else puts("A");
			}
		} else {
			int op = sub1::dfs(l, true);
			if (!op) puts("D");
			else if (op > 0) puts("A");
			else puts("B");
		}
	}
	return 0;
}
