#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e3 + 10;
const int M = 1e5 + 10;
const int MOD = 1e9 + 7;
int h, w, n, fac[M << 1] = {1}, fav[M << 1], dp[N];
struct Node {
	int x, y;
	bool operator < (const Node &t) const { return x == t.x ? y < t.y : x < t.x; }
}d[N];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int C(int n, int m) { return (LL)fac[n] * fav[m] % MOD * fav[n - m] % MOD; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> h >> w >> n;
	for (int i = 1; i <= h + w; ++ i) fac[i] = (LL)fac[i - 1] * i % MOD;
	fav[h + w] = qpow(fac[h + w], MOD - 2);
	for (int i = h + w; i; -- i) fav[i - 1] = (LL)fav[i] * i % MOD;
	for (int i = 1; i <= n; ++ i) cin >> d[i].x >> d[i].y;
	d[n + 1].x = h, d[n + 1].y = w, sort(d + 1, d + n + 2);
	dp[0] = 1;
	for (int i = 1; i <= n + 1; ++ i) {
		dp[i] = C(d[i].x + d[i].y - 2, d[i].y - 1);
		for (int j = 1; j < i; ++ j)
			if (d[j].y <= d[i].y) 
				upd(dp[i], MOD - (LL)dp[j] * C(d[i].x - d[j].x + d[i].y - d[j].y, d[i].x - d[j].x) % MOD);
	}
	return cout << dp[n + 1] << '\n', 0;	
}
