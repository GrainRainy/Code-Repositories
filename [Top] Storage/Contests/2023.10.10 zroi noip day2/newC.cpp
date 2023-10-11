#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using PII = pair<int, int>;
const int N = 2e3 + 10;
int n, m, dg[N], cp[N];
struct Save { int a, b; }sv[N];

namespace sub1 {
	int ans;
	string ss;
	void solve() {
		for (int s = (1 << m) - 1 ; ~s; -- s) {
			for (int i = 1; i <= n; ++ i) cp[i] = dg[i];
			for (int i = 1; i <= m; ++ i)
				if ((s >> m - i) & 1) cp[sv[i].a] --, cp[sv[i].b] --;
			int res = 0;
			for (int i = 1; i <= n; ++ i) res += cp[i] & 1;
			if (res > ans) {
				string tmp;
				for (int i = 1; i <= m; ++ i)
					tmp = tmp + (char)('0' + ((s >> m - i) & 1));
				ans = res, ss = tmp;
			}
		}
		cout << ss << '\n';
		cout << ans << '\n';
		return;
	}
}

namespace sub2 {
	int head[N], idx, f[N][2];
	vector<int> ss[N][2];
	struct Node { int nxt, to, id; }edge[N << 1];
	bool st[N];
	
	inline void add(int a, int b, int c) {
		edge[++ idx].nxt = head[a];
		edge[idx].id = c;
		edge[head[a] = idx].to = b;
	}
	
	bool cmp(vector<int> a, vector<int> b) { // a  «∑Ò±» b ¡”  
		sort(a.begin(), a.end()), sort(b.begin(), b.end());
		for (int i = 0; i < a.size() and i < b.size(); ++ i)
			if (a[i] < b[i]) return false;
			else if (a[i] > b[i]) return true;
		return a.size() > b.size();
	}
	
	void dp(int u, int fa) {
		vector<int> res, sit[N], sita, sitb;
		priority_queue<PII> q;
		res.emplace_back(0);
		for (int i = head[u], v; ~i; i = edge[i].nxt) {
			if ((v = edge[i].to) == fa) continue;
			dp(v, u);
			res[0] += f[v][0], q.push({f[v][1] - f[v][0], edge[i].id});
		}
		while (q.size()) {
			res.emplace_back(res.back() + q.top().first);
			sit[res.size() - 1] = sit[res.size() - 2];
			sit[res.size() - 1].emplace_back(q.top().second);
			q.pop();
		}
		int resa = 0, resb = 0;
		for (int i = 0; i < res.size(); i += 2) {
			if (res[i] > resa) resa = res[i], sita = sit[i];
			else if (res[i] == resa and cmp(sita, sit[i])) sita = sit[i];
		}
		for (int i = 1; i < res.size(); i += 2) {
			if (res[i] > resb) resb = res[i], sitb = sit[i];
			else if (res[i] == resb and cmp(sitb, sit[i])) sita = sit[i];
		}
		if (res.size() == 1) f[u][0] = 1;
		else if (res.size() & 1) { 
			if (resa + 1 > resb) f[u][0] = resa + 1, ss[u][0] = sita;
			else if (resa + 1 < resb) f[u][0] = resb, ss[u][0] = sitb;
			else f[u][0] = resb, ss[u][0] = cmp(sita, sitb) ? sitb : sita; 
			if (resa > resb + 1) f[u][1] = resa, ss[u][1] = sita;
			else if (resa < resb + 1) f[u][1] = resb + 1, ss[u][1] = sitb;
			else f[u][1] = resb, ss[u][1] = cmp(sita, sitb) ? sitb : sita;
		} else {
			if (resa + 1 > resb) f[u][1] = resa + 1, ss[u][1] = sita;
			else if (resa + 1 < resb) f[u][1] = resb, ss[u][1] = sitb;
			else f[u][1] = resb, ss[u][1] = cmp(sita, sitb) ? sitb : sita; 
			if (resa > resb + 1) f[u][0] = resa, ss[u][0] = sita;
			else if (resa < resb + 1) f[u][0] = resb + 1, ss[u][0] = sitb;
			else f[u][0] = resb, ss[u][0] = cmp(sita, sitb) ? sitb : sita;
		}
	}

	void solve() {
		memset(head, -1, sizeof(int) * (n + 10));
		for (int i = 1; i <= m; ++ i) add(sv[i].a, sv[i].b, i);
		dp(1, 0);
		cout << f[1][1] << '\n';
		for (auto t : ss[1][1]) st[t] = 1;
		for (int i = 1; i <= m; ++ i) cout << st[i];
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++ i) {
		cin >> sv[i].a >> sv[i].b;
		sv[i].a ++, sv[i].b ++, dg[sv[i].a] ++, dg[sv[i].b] ++;
	}
//	if (m < 20) 
		return sub1::solve(), 0;
	if (m == n - 1) 
		return sub2::solve(), 0;
	else for (int i = 1; i <= n; ++ i) cout << '0';
	return cout << '\n', 0;
}
