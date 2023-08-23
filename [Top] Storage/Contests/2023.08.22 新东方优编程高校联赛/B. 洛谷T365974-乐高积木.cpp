#include <bits/stdc++.h>
using namespace std;
const int N = 10 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int k, n, m;
struct Node {
	int x, y;
	bool operator < (const Node &t) const {
		return x < t.x or x == t.x and y < t.y;
	}
};
using lego = set<Node>;
set<lego> a[N];
int ans[N][N][N];

lego mve(const lego &p) {
	lego ans;
	int mx = p.begin()->x, my = p.begin()->y;
	for (auto t : p) mx = min(mx, t.x), my = min(my, t.y);
	for (auto t : p) ans.insert({t.x - mx, t.y - my});
	return ans;
}

lego rotate(const lego &p) {
	lego ans;
	for (auto t : p) ans.insert({t.y, -t.x});
	return mve(ans);
}

lego flip(const lego &p) {
	lego ans;
	for (auto t : p) ans.insert({t.x, -t.y});
	return mve(ans);
}

void check(const lego &u, const Node &p) {
	lego nw = u;
	nw.insert(p); nw = mve(nw);
	int len = nw.size();
	for (int i = 0; i < 4; ++ i) {
		if (a[len].find(nw) != a[len].end()) return;
		nw = rotate(nw);
	}
	nw = flip(nw);
	for (int i = 0; i < 4; ++ i) {
		if (a[len].find(nw) != a[len].end()) return;
		nw = rotate(nw);
	}
	a[len].insert(nw);
}

void pre() {
	lego ori; ori.insert({0, 0});
	a[1].insert(ori);
	for (int i = 2; i <= 10; ++ i)
		for (auto p : a[i - 1])
			for (auto t : p) 
				for (int j = 0; j < 4; ++ j) {
					Node tmp = {t.x + dx[j], t.y + dy[j]};
					if (p.find(tmp) == p.end()) check(p, tmp);
				}
	for (int k = 1; k <= 10; ++ k)
		for (int n = 1; n <= k; ++ n)
			for (int m = 1; m <= k; ++ m) {
				int cnt = 0;
				for (auto const &p : a[k]) {
					int mx = 0, my = 0;
					for (auto t : p) 
						mx = max(t.x, mx), my = max(t.y, my);
					if (min(mx, my) <= min(n - 1, m - 1))
						if (max(mx, my) <= max(n - 1, m - 1))
							cnt ++;
				}
				ans[k][n][m] = cnt;
			}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	pre();
	int t; cin >> t;
	while (t --) cin >> k >> n >> m, cout << ans[k][n][m] << '\n';
	return 0;
}
