#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
using namespace std;
const int MOD = 1e9 + 7;
int n, m, b[3];
int dis[1 << 25], dp[1 << 25];

inline void upd(int &x, int y) { (x += y) >= MOD and (x -= MOD); }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> dis[1 << i - 1];
	cin >> m;
	for (int i = 1; i <= m; ++ i) cin >> b[i];
	dp[0] = 1;
	for (int s = 1; s < 1 << n; ++ s) {
		dis[s] = dis[s ^ lowbit(s)] + dis[lowbit(s)];
		if (dis[s] == b[1] or dis[s] == b[2]) continue;
		for (int i = s; i; i ^= lowbit(i)) 
			upd(dp[s], dp[s ^ lowbit(i)]);
	}
	cout << dp[(1 << n) - 1] << endl;
	return 0;
} 
