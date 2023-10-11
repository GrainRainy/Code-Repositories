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
		return;
	}
}

namespace sub2 {
	int head[N], idx, f[N][2];
	struct Node { int nxt, to; }edge[N << 1];
	
	inline void add(int a, int b) {
		edge[++ idx].nxt = head[a];
		edge[head[a] = idx].to = b;
	}
	
	void dp(int u, int fa) {
		vector<int> res;
		priority_queue<int> q;
		res.emplace_back(0);
		for (int i = head[u], v; ~i; i = edge[i].nxt) {
			if ((v = edge[i].to) == fa) continue;
			dp(v, u);
			res[0] += f[v][0], q.push(f[v][1] - f[v][0]);
		}
		while (q.size()) res.emplace_back(res.back() + q.top()), q.pop();
		int resa = 0, resb = 0;
		for (int i = 0; i < res.size(); i += 2) resa = max(resa, res[i]);
		for (int i = 1; i < res.size(); i += 2) resb = max(resb, res[i]);
		if (res.size() == 1) f[u][0] = 1;
		else if (res.size() & 1) { 
			f[u][0] = max(resa + 1, resb);
			f[u][1] = max(resa, resb + 1);
		} else {
			f[u][0] = max(resa, resb + 1);
			f[u][1] = max(resa + 1, resb);
		}
	}
	
	void solve() {
		memset(head, -1, sizeof(int) * (n + 10));
		for (int i = 1; i <= m; ++ i) add(sv[i].a, sv[i].b);
		dp(1, 0);
		cout << f[1][1] << '\n';
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
//		return sub1::solve(), 0;
	if (m == n - 1) 
		return sub2::solve(), 0;
	else for (int i = 1; i <= n; ++ i) cout << '0';
	return cout << '\n', 0;
}
