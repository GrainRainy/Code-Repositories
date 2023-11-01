#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, h[N], sn[N], tn, sx[N], tx, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> h[i];
		while (tn and h[sn[tn]] > h[i]) tn --;
		while (tx and h[sx[tx]] < h[i]) tx --;
		int tmp = lower_bound(sn + 1, sn + tn + 1, sx[tx]) - sn;
		if (tmp < tn + 1) ans = max(ans, i - sn[tmp] + 1);
		sn[++ tn] = sx[++ tx] = i;
	}
	return cout << ans << '\n', 0;
}
