#include <bits/stdc++.h> 
using namespace std;
using PII = pair<int, int>;
const int N = 1e5 + 10;
int n, a[N], mxp;
PII f[N], ans;
vector<int> nms;

void upd(PII &a, const PII &b) { if (b > a) a = b; }
struct Fenwick {
	PII tr[N];
	void add(int p, PII v) { while (p <= n) upd(tr[p], v), p += p & -p;	}
	PII qry(int p) { PII r = {0, 0}; while (p) upd(r, tr[p]), p -= p & -p; return r; }
}t;

void solve() {
	cin >> n, ans = {0, 0}, nms.clear();
	for (int i = 1; i <= n; ++ i) 
		cin >> a[i], nms.emplace_back(a[i]);
	memset(t.tr, 0, sizeof t.tr);
	sort(nms.begin(), nms.end());
	nms.erase(unique(nms.begin(), nms.end()), nms.end());
	for (int i = 1; i <= n; ++ i) 
		a[i] = lower_bound(nms.begin(), nms.end(), a[i]) - nms.begin() + 1;
	for (int i = 1; i <= n; ++ i) {
		auto pre = t.qry(a[i]);
		f[i] = {1, i}, upd(f[i], {pre.first + 1, pre.second}), t.add(a[i], f[i]);
	}
	for (int i = 1; i <= n; ++ i) {
		if (f[i].first > ans.first) ans = {f[i].first, i - f[i].second + 1 - f[i].first};
		else if (f[i].first == ans.first and i - f[i].second + 1 - f[i].first < ans.second)
			ans = {f[i].first, i - f[i].second + 1 - f[i].first};
	}
	cout << ans.first << ' ' << ans.second << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
