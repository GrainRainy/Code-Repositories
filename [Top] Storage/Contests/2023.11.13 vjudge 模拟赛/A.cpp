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
	while (q.size()) q.pop();
	for (int i = 1; i <= n; ++ i) cin >> v[i].tot, mid += v[i].tot;
	mid /= m;
	for (int i = 1, a, b; i <= n; ++ i) {
		a = floor(v[i].tot / mid), b = ceil(v[i].tot / mid);
		long double va = v[i].tot / a, vb = v[i].tot / b;
		if (a and a * (va - mid) * (va - mid) < b * (vb - mid) * (vb - mid)) {
			v[i].nc = a, ans += a * (va - mid) * (va - mid);
		} else v[i].nc = b, ans += b * (vb - mid) * (vb - mid);
		cnt += v[i].nc;
	}
	if (cnt > m) {
		for (int i = 1; i <= n; ++ i) {
			if (v[i].nc == 1) continue;
			long double nc = v[i].nc, nv = v[i].tot / nc, wv = v[i].tot / (nc - 1);
			v[i].dt = -nc * (nv - mid) * (nv - mid) + (nc - 1) * (wv - mid) * (wv - mid);
			q.push(v[i]);
		}
		while (cnt > m) {
			ans += q.top().dt, cnt --;
			Node nw = q.top(); q.pop();
			if (nw.nc == 2) continue;
			double nc = -- nw.nc, nv = nw.tot / nc, wv = nw.tot / (nc - 1);
			nw.dt = -nc * (nv - mid) * (nv - mid) + (nc - 1) * (wv - mid) * (wv - mid);
			q.push(nw);
		}
	} else if (cnt < m) {
		for (int i = 1; i <= n; ++ i) {
			long double nc = v[i].nc, nv = v[i].tot / nc, wv = v[i].tot / (nc + 1);
			v[i].dt = -nc * (nv - mid) * (nv - mid) + (nc + 1) * (wv - mid) * (wv - mid);
			q.push(v[i]);
		}
		while (cnt < m) {
			ans += q.top().dt, cnt ++;
			Node nw = q.top(); q.pop();
			long double nc = ++ nw.nc, nv = nw.tot / nc, wv = nw.tot / (nc + 1);
			nw.dt = -nc * (nv - mid) * (nv - mid) + (nc + 1) * (wv - mid) * (wv - mid);
			q.push(nw);
		}
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
