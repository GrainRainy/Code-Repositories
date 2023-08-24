#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;

int n, a[N], b[N];
struct LowbitTree {
	LL tree[N << 1];
	inline void add(int x, int v) { while (x <= n + n + 1) tree[x] += v, x += x & -x; }
	LL query(int r) {
		int res = 0;
		while (r) res += tree[r], r -= r & -r;
		return res;
	} 
}lt;

bool check(int u) {
	int pre = 0; LL ans = 0;
	lt.add(n, 1);
	for (int i = 1; i <= n; ++ i) {
		pre += (a[i] >= u ? 1 : -1);
		ans += lt.query(pre + n + 1);
		lt.add(pre + n + 1, 1);
	}
	for (int i = 1; i <= n << 1; ++ i) lt.tree[i] = 0;
	if (ans << 1 > (LL)n * (n + 1) / 2) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1);
	int l = 1, r = n, mid;
	while (l < r) {
		mid = l + r + 1 >> 1;
		check(b[mid]) ? l = mid : r = mid - 1;
	}
	return cout << b[l] << endl, 0;
}
