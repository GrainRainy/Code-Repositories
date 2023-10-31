#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, x; i <= m; ++ i) cin >> x, a[x] = 1;
	for (int i = n; i; -- i) if (!a[i]) a[i] = a[i + 1] + 1;
	for (int i = 1; i <= n; ++ i) cout << a[i] - 1 << '\n';
	cout << '\n';
	return 0;
}
