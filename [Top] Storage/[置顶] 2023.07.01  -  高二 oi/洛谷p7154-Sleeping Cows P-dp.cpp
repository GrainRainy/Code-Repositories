#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using PII = pair<int, int>;
using LL = long long;
const int N = 3e3 + 10;
const int MOD = 1e9 + 7;
int n, mxj; PII a[N << 1];
int f[2][N][2];

inline void upd(int &a, int b) {
	a += b; (a >= MOD) and (a -= MOD);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1, tmp; i <= n; ++ i) {
		cin >> tmp;
		a[i] = {tmp, 0};
	}
	for (int i = 1, tmp; i <= n; ++ i) {
		cin >> tmp;
		a[i + n] = {tmp, 1};
	}
	sort(a + 1, a + (n << 1) + 1);
	f[0][0][0] = 1;
	for (int i = 1; i <= n << 1; ++ i) {
		memset(f[i & 1], 0, sizeof(int) * ((mxj << 1) + 10));
		if (!a[i].se) {
			mxj ++;
			for (int j = 0; j <= mxj; ++ j) {
				upd(f[i & 1][j + 1][0], f[i - 1 & 1][j][0]);
				upd(f[i & 1][j][1], f[i - 1 & 1][j][0]);
				upd(f[i & 1][j][1], f[i - 1 & 1][j][1]);
				upd(f[i & 1][j + 1][1], f[i - 1 & 1][j][1]);
			}
		} else for (int j = 0; j <= mxj; ++ j) {
					upd(f[i & 1][j][0], f[i - 1 & 1][j][0]);
					if (j > 0) {
						upd(f[i & 1][j - 1][0], (LL)f[i - 1 & 1][j][0] * j % MOD);
						upd(f[i & 1][j - 1][1], (LL)f[i - 1 & 1][j][1] * j % MOD);
					}
				}
	}
	cout << (f[n << 1 & 1][0][0] + f[n << 1 & 1][0][1]) % MOD << endl;
	return 0;
}
