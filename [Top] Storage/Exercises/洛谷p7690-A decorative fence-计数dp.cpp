#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 20 + 5;
LL n, c, f[N][N][N];
bool st[N];

void solve() {
	cin >> n >> c;
	memset(st, 0, sizeof st);
	int last, k;
	for (int i = 1; i <= n; ++ i) {
		if (f[n][i][1] >= c) {
			last = i, k = 1;
			break;
		} else c -= f[n][i][1];
		if (f[n][i][0] >= c) {
			last = i, k = 0;
			break;
		} else c -= f[n][i][0];
	}
	st[last] = 1;
	cout << last << ' ';
	for (int i = 2; i <= n; ++ i) {
		int cnt = 0;
		k ^= 1;
		for (int j = 1; j <= n; ++ j) {
			if (st[j]) continue;
			cnt ++;
			if (!k and j < last or k and j > last) {
				if (f[n - i + 1][cnt][k] >= c) {
					last = j;
					break;
				} else c -= f[n - i + 1][cnt][k];
			}
		}
		st[last] = true;
		cout << last << ' ';
	}
	return cout << '\n', void();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	f[1][1][0] = f[1][1][1] = 1;
	for (int i = 2; i <= 20; ++ i)
		for (int j = 1; j <= i; ++ j) {
			for (int k = 1; k < j; ++ k) f[i][j][1] += f[i - 1][k][0];
			for (int k = j; k < i; ++ k) f[i][j][0] += f[i - 1][k][1];
		}
	while (t --) solve();
	return 0;
}
