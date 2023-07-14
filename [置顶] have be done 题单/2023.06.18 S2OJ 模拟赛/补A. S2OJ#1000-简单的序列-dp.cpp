#include <iostream>
#include <cstring>
using namespace std;
using LL = long long;

const int N = 2010;
const int L = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, m, cnt, mn, f[N][N], ans;
char s[L];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	cin >> s + 1;
	for (int i = 1; i <= m; ++ i) {
		if (s[i] == '(') cnt ++;
		else cnt --;
		mn = min(mn, cnt);
	}
	
	f[0][0] = 1;
	for (int i = 1; i <= n - m; ++ i) {
		f[i][0] = f[i - 1][1] % MOD;
		for (int j = 1; j <= i; ++ j)
			f[i][j] = ((LL)f[i - 1][j + 1] + f[i - 1][j - 1]) % MOD;
	}
	for (int i = 0; i <= n - m; ++ i)
		for (int j = 0; j <= i; ++ j)
			if (j + mn >= 0 and j + cnt <= n - m - i)
				ans = (ans + (LL)f[i][j] * f[n - m - i][j + cnt]) % MOD;
	cout << ans << endl;
	return 0;
}

