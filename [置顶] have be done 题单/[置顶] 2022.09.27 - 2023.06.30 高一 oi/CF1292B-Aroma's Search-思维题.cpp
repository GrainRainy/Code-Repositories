#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 70 + 5;
LL ax, ay, bx, by, sx, sy, t;
LL x[N], y[N], n;
LL tmpt, tmpans, tmpd, ans;

LL dist(LL xa, LL ya, LL xb, LL yb) { 
	return llabs(xa - xb) + llabs(ya - yb);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
	cin >> sx >> sy >> t;
	while (x[n] <= sx or y[n] <= sy or dist(sx, sy, x[n], y[n]) <= t) {
		n ++;
		x[n] = ax * x[n - 1] + bx;
		y[n] = ay * y[n - 1] + by; 
	}
	for (int i = 0; i <= n; ++ i) {
		tmpans = 0, tmpt = t;
		tmpd = dist(sx, sy, x[i], y[i]);
		if (tmpd <= tmpt) tmpt -= tmpd, tmpans ++;
		else continue;
		for (int j = i; j; -- j) {
			tmpd = dist(x[j], y[j], x[j - 1], y[j - 1]);
			if (tmpd <= tmpt) tmpt -= tmpd, tmpans ++;
			else break;
		}
		for (int j = 1; j <= n; ++ j) {
			tmpd = dist(x[j], y[j], x[j - 1], y[j - 1]);
			if (tmpd <= tmpt) tmpt -= tmpd, tmpans += (j > i);
			else break;
		}
		ans = max(ans, tmpans);
	}
	cout << ans << endl;
	return 0;
}
