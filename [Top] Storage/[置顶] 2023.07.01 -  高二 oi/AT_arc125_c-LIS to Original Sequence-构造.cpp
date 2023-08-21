#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, k, a[N], q[N], h = 1, t;
bool st[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= k; ++ i) cin >> a[i], st[a[i]] = true;
	for (int i = 1; i <= n; ++ i) if (!st[i]) q[++ t] = i;
	for (int i = 1; i < k; ++ i) {
		cout << a[i] << ' ';
		if (h <= t and q[h] < a[i]) cout << q[h ++] << ' ';
	}
	for (int i = t; i >= h; -- i) {
		if (st[a[k]] and q[i] < a[k]) 
			cout << a[k] << ' ', st[a[k]] = false;
		cout << q[i] << ' ';
	}
	if (st[a[k]]) cout << a[k] << endl;
}
