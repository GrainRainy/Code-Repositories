#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 2e5 + 10;
int sub, n, m, cnt;
struct Node {
	long double tot, nc, dt;
	bool operator > (const Node &t) const {
		return dt > t.dt;
	}
}v[N];
priority_queue<Node, vector<Node>, greater<Node>> q;
long double mid, ans;

void solve() {
	cin >> n >> m, ans = mid = cnt = 0;
	while (q.size()) {
		q.pop();
		if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-1);
	}
	if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-2);
	for (int i = 1; i <= n; ++ i) cin >> v[i].tot, mid += v[i].tot;
		if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-1);
	mid /= m;
	if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-1);
	for (int i = 1; i <= n; ++ i) {
		v[i].nc = 1;
		if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-1);
		long double nv = v[i].tot, wv = v[i].tot / 2;
		if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-1);
		v[i].dt = -(nv - mid) * (nv - mid) + 2 * (wv - mid) * (wv - mid);
		if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-1);
		ans += (nv - mid) * (nv - mid);
		if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-1);
		q.push(v[i]);
		if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-1);
	}
	if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-3);
	while (cnt < m - n) {
		if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-4);
		ans += q.top().dt, cnt ++;
		if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-1);
		Node nw = q.top(); q.pop();
		if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-1);
		long double nc = ++ nw.nc, nv = nw.tot / nc, wv = nw.tot / (nc + 1);
		nw.dt = -nc * (nv - mid) * (nv - mid) + (nc + 1) * (wv - mid) * (wv - mid);
		if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-1);
		q.push(nw);
		if ((double)clock() / CLOCKS_PER_SEC > 2.8) cout << cnt << '\n', exit(-1);
	}
	return printf("Case #%d: %.10Lf\n", sub, ans / m), void();
}

int main() {
//	freopen("a.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) ++ sub, solve();
	return 0;
}
