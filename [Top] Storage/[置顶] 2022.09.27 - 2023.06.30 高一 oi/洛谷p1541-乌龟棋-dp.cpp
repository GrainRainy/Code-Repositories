#include <bits/stdc++.h>
using namespace std;

const int N = 360;
const int L = 45;
int n, m, w[N], cnt[5];
int f[2][L][L][L];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> w[i];
	for (int i = 1, tmp; i <= m; ++ i) cin >> tmp, cnt[tmp] ++;
	f[0][0][0][0] = w[1];
	for (int a = 0; a <= cnt[1]; ++ a)
		for (int b = 0; b <= cnt[2]; ++ b)
			for (int c = 0; c <= cnt[3]; ++ c)
				for (int d = 0, val; d <= cnt[4]; ++ d) {
					val = 1 + a + b * 2 + c * 3 + d * 4;
					int &t = f[a & 1][b][c][d];
					if (a > 0) t = max(t, f[(a - 1) & 1][b][c][d] + w[val]);
					if (b > 0) t = max(t, f[a & 1][b - 1][c][d] + w[val]);
					if (c > 0) t = max(t, f[a & 1][b][c - 1][d] + w[val]);
					if (d > 0) t = max(t, f[a & 1][b][c][d - 1] + w[val]);
				}
	cout << f[cnt[1] & 1][cnt[2]][cnt[3]][cnt[4]] << endl;
}
