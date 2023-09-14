#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 10;
const int M = 2e4 + 10;
int n, b[N], c[N], m, f[M], fm[N][M];
int tl, hd, q[M], v[M], k, k1, val, mx;

void print(int x, int y) {
	if (!x) return;
	print(x - 1, fm[x][y]);
	cout << (y - fm[x][y]) / b[x] << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> b[i];
	for (int i = 1; i <= n; ++ i) cin >> c[i];
	cin >> m;
	memset(f, 0x3f, sizeof(int) * (m + 10)), f[0] = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int d = 0; d < b[i]; ++ d) {
			mx = (m - d) / b[i];
			for (hd = 1, tl = 0, k = mx; k >= max(0, mx - c[i]); -- k) {
				val = f[k * b[i] + d] - k;
				while (tl and v[tl] > val) tl --;
				v[++ tl] = val, q[tl] = k;
			}
			for (k1 = mx; ~k1; -- k1, -- k) {
				while (hd <= tl and q[hd] > k1) hd ++;
				if (hd <= tl) f[k1 * b[i] + d] = v[hd] + k1;
				fm[i][k1 * b[i] + d] = q[hd] * b[i] + d;
				if (k < 0) continue;
				val = f[k * b[i] + d] - k;
				while (hd <= tl and v[tl] > val) tl --;
				v[++ tl] = val, q[tl] = k;
			}
		}
	}
	cout << f[m] << '\n';
	return print(n, m), 0;
}
