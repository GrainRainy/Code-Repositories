#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, ans;
vector<int> a;
map<vector<int>, bool> mp;

void dfs() {
	for (int i = 0; i < n - 1; ++ i) {
		if (__gcd(a[i], a[i + 1]) == 1) {
			swap(a[i], a[i + 1]);
			if (mp.find(a) == mp.end()) {
				ans ++;
				mp[a] = true;
				dfs();
			}
			swap(a[i], a[i + 1]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1, tmp; i <= n; ++ i)
		cin >> tmp, a.push_back(tmp);
	mp[a] = true, ans ++;
	dfs();
	cout << ans << '\n';
	return 0;
}
