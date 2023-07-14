#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 50;
const int MOD = 10007;
int n, m, k, cnt;
int a[N];

void dfs(int u) {
	if (u == n + 1) {
		LL mul = 1;
		for (int i = 1; i <= n; ++ i) mul *= a[i];
		if (!(mul % k) and __gcd(mul / k, (LL)k) == 1) 
			cnt = (cnt + 1) % MOD;
		return;
	}
	for (int i = 1; i <= m; ++ i) {
		a[u] = i; dfs(u + 1); a[u] = 0;
	}
}

int main() {
	cin >> n >> m >> k;
	dfs(1);
	cout << cnt << endl;
	return 0;
}
