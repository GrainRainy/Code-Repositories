#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e3 + 10;
int n, m, k, mod, ct[N], cn[N], q2[N] = {1};
bool rot, rsv;
int ans = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	if (m + n & 1) return puts("0") & 0;
	else if (n < m) swap(n, m), rot = true;
	for (int i = 1, x, y, v; i <= k; ++ i) {
		cin >> x >> y >> v;
		if (rot) swap(x, y);
		ct[x] ++, cn[x] += v == -1;
	}
	cin >> mod;
	for (int i = 1; i <= n; ++ i) 
		if ((q2[i] = q2[i - 1] << 1) >= mod) q2[i] -= mod;
	for (int i = 1; i <= n; ++ i) {
		if (!ct[i] and !rsv) { rsv = true; continue; }
		if (ct[i] == m and !(cn[i] & 1)) return puts("0") & 0;
		else if (ct[i] < m) ans = ((LL)ans * q2[m - ct[i] - 1]) % mod;
	}
	return cout << ans << '\n', 0;
} 
