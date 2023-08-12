#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
int n, k;
LL sum[N][20], ans;

inline int mp(int x) {
	if (x == 2) return 1; if (x == 3) return 2;
	if (x == 5) return 3; if (x == 7) return 4;
	if (x == 11) return 5; if (x == 13) return 6;
	if (x == 17) return 7; if (x == 19) return 8;
	return 0;
}

void pre(int x, int id) {
	for (int i = 2, cnt; i <= x / i; ++ i) {
		if (!(x % i)) {
			cnt = 0;
			while (!(x % i)) cnt ++, x /= i;
			sum[id][mp(i)] += cnt;
		}
	}
	if (x != 1) sum[id][mp(x)] ++;
}

inline bool judge(int l, int r) {
	for (int i = 1; i <= 8; ++ i)
		if ((sum[r][i] - sum[l - 1][i]) % k) return false;
	return true;
}

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1, x; i <= n; ++ i) 
		cin >> x, pre(x, i);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= 8; ++ j)
			sum[i][j] += sum[i - 1][j];
	for (int i = 1; i <= n; ++ i)
		for (int j = i; j <= n; ++ j)
			if (judge(i, j)) ans ++;
	cout << ans << endl;
	return 0;
}
