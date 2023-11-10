#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, f[N], pre[N];
struct Node {
	int x, y, z;
	bool operator < (const Node &t) const {
		return x ^ t.x ? x < t.x : y ^ t.y ? y < t.y : z < t.z;
	}
}p[N];
bool st[N];
int cnt, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) 
		cin >> p[i].x >> p[i].y >> p[i].z, f[i] = 1;
	sort(p + 1, p + n + 1);
	for (; cnt < n; ans ++) {
		for (int i = 1; i <= n; ++ i) f[i] = 1, pre[i] = 0;
		for (int i = 1; i <= n; ++ i) {
			if (st[i]) continue;
			for (int j = 1; j < i; ++ j)
				if (!st[j] and p[j].x < p[i].x and p[j].y < p[i].y and p[j].z < p[i].z)
					if (f[j] + 1 > f[i]) f[i] = f[j] + 1, pre[i] = j;
		}
		int mxp = 0;
		for (int i = 1; i <= n; ++ i) if (!st[i] and f[i] > f[mxp]) mxp = i;
		if (!ans) cout << f[mxp] << '\n';
		while (mxp) cnt ++, st[mxp] = true, mxp = pre[mxp];
	}
	return cout << ans << '\n', 0;
}
