#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 1e4 + 10;
const int M = 64 + 36;
const int MOD = 998244353;
int n, w, p[N];
int id[N], stk[M], tp;
int ta[N], tap, tb[N], tbp, tc[N], tcp;
int val[M];
__int128 f[N][M];

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> w;
	for (int i = 1; i <= n; ++ i) cin >> p[i];
	for (int i = 1; i <= w / i; ++ i)
		if (!(w % i)) {
			stk[++ tp] = i, id[i] = tp;
			if (i != w / i) stk[++ tp] = w / i, id[w / i] = tp;
		}
	sort(stk + 1, stk + tp + 1);
	f[0][tp] = 1;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= tp; ++ j) {
			tap = tbp = tcp = 0;
			for (int k = 1; k <= p[i] / k; ++ k)
				if (!(p[i] % k)) {
					ta[++ tap] = k;
					if (k != p[i] / k) ta[++ tap] = p[i] / k;
				}
			for (int k = 1; k <= j and stk[k] <= stk[j] / stk[k]; ++ k)
				if (!(stk[j] % stk[k])) {
					tb[++ tbp] = stk[k];
					if (stk[k] != stk[j] / stk[k]) tb[++ tbp] = stk[j] / stk[k];
				}
			for (int a = 1; a <= tap; ++ a)
				for (int b = 1; b <= tbp; ++ b)
					tc[++ tcp] = ta[a] * tb[b];
			sort(tc + 1, tc + tcp + 1);
			val[j] = unique(tc + 1, tc + tcp + 1) - tc - 1;
		}
		for (int j = 1; j <= tp; ++ j) {
			for (int k = j; k <= tp; ++ k)
				if (!(stk[k] % stk[j])) {
					auto it = lower_bound(stk + 1, stk + tp + 1, stk[k] / stk[j]);
					f[i][j] = max(f[i][j], f[i - 1][k] * val[it - stk]);
				}
		}
	}
	__int128 res = f[n][1] % MOD;
	cout << (int)res << '\n';
	return 0;
}
