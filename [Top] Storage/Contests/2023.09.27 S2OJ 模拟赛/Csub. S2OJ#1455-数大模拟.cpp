#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, k, a[N];

namespace sub2 {
	int cnt = 0;
	void solve() {
		for (int i = 1; i <= n; ++ i) cnt += a[i];
		n -= cnt;
		while (cnt --) cout << "1 ";
		for (int i = 1; i <= n; ++ i) cout << "0 ";
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	if (k >= n) return sub2::solve(), 0;
	vector<int> v;
	while (k --) {
		v.clear();
		for (int i = 2; i <= n; ++ i)
			if (!a[i - 1] and a[i]) v.push_back(i);
		for (auto t : v) a[t - 1] = 1, a[t] = 0;
	}
	for (int i = 1; i <= n; ++ i) cout << a[i] << ' ';
	cout << '\n';
	return 0;
}
