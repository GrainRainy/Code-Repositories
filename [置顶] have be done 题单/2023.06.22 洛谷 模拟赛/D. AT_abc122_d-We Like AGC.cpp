#include <bits/stdc++.h>
#define __DEBUG__ puts("__DEBUG__");
using namespace std;
using LL = long long;
const int N = 100 + 10;
const int L = 8;
const int MOD = 1e9 + 7;

int n;
LL f[N][L][L][L];
void update(LL &x, LL y) { x + y > MOD ? x = x + y - MOD : x += y; }
bool check(int a, int b, int c) {
	bool f = false;
	f |= (a == 1 and b == 3 and c == 2);
	f |= (a == 1 and b == 2 and c == 3);
	f |= (a == 3 and b == 1 and c == 2);
	return !f;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 3; i <= n; ++ i) 
		for (int a = 1; a <= 4; ++ a)
			for (int b = 1; b <= 4; ++ b)
				for (int c = 1; c <= 4; ++ c) {
					if (!check(a, b, c)) continue;
					if (i == 3) f[i][a][b][c] = 1;
					else for (int l = 1; l <= 4; ++ l)
						if (check(l, a, b) and !(l == 1 and b == 3 and c == 2) and !(l == 1 and a == 3 and c == 2))
							update(f[i][a][b][c], f[i - 1][l][a][b]);
//							f[i][a][b][c] = (f[i][a][b][c] + f[i - 1][l][a][b]) % MOD;
				}
	LL ans = 0;
	for (int a = 1; a <= 4; ++ a)
		for (int b = 1; b <= 4; ++ b)
			for (int c = 1; c <= 4; ++ c)
				if (check(a, b, c)) 
//				ans = (ans + f[n][a][b][c]) % MOD;
					update(ans, f[n][a][b][c]);
	cout << ans << endl;
	return 0;
}

