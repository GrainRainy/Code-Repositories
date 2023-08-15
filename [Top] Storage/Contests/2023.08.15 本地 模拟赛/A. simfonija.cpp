#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
int n, k, a[N], b[N];
int mid, l, r;
LL mn = 0x3f3f3f3f3f3f3f3f;
int cp[N];

bool check(int x) {
	LL res = 0;
	for (int i = 1; i <= n; ++ i) cp[i] = abs(a[i] + x - b[i]);
	sort(cp + 1, cp + n + 1, greater<int>());
	for (int i = k + 1; i <= n; ++ i) res += cp[i];
	if (res < mn) {
		mn = res;
		return true;
	} else return false;
}

int main() {
	freopen("simfonija.in", "r", stdin);
	freopen("simfonija.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	for (int i = 1; i <= n; ++ i) {
		cin >> b[i];
		r = max(r, abs(b[i] - a[i]));
	}
	l = -r;
	while (l < r) {
		mid = l + r >> 1;
		if (check(mid - 1) < check(mid + 1)) l = mid;
		else r = mid; 
	}
	cout << mn << endl;
	return 0;
} 
