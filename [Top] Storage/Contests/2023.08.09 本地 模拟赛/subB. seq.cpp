#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int m, n;
set<int> s;
int k, mn, mx, top;
long long a[20];

int main() {
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> m;
	for (int i = 1, x; i <= m; ++ i) {
		cin >> x, s.insert(x);
		top = max(top, x);
	}
	cin >> n;
	while (n --) {
		mn = mx = -1;
		cin >> a[0] >> a[1] >> k;
		if (s.find(0) != s.end()) mn = mx = 0;
		if (s.find(1) != s.end()) {
			if (mn == -1 or a[1] < a[0]) mn = 1;
			if (mn == -1 or a[1] > a[0]) mx = 1;
		}
		for (int i = 2; i <= top; ++ i) {
			a[i] = a[i - 2] + a[i - 1] * k;
			if (s.find(i) != s.end()) {
				if ((mn == -1) or a[mn] > a[i]) mn = i;
				if ((mx == -1) or a[mx] < a[i]) mx = i;
			}
		}
		cout << mx << ' ' << mn << '\n';
	}
	return 0;
}
