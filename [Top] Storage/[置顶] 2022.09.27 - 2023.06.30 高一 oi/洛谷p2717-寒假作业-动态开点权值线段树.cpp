#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x; 
}

const int N = 2e5 + 10;
const int M = 1e7 + 10;
const LL INF = 1e15;
LL n, t, a[N], ans; 
// basis 
LL cnt[M];
LL rt, lson[M], rson[M], tTop;
// Segment Tree 

void insert(LL &u, LL tl, LL tr, LL val) {
	if (!u) u = ++ tTop;
	cnt[u] ++;
	if (tl == tr) return;
	LL mid = tl + tr >> 1;
	if (val <= mid) insert(lson[u], tl, mid, val);
	else insert(rson[u], mid + 1, tr, val);
}
LL query(LL u, LL tl, LL tr, LL l, LL r) {
	if (tl >= l and tr <= r) return cnt[u];
	LL mid = tl + tr >> 1, res = 0;
	if (l <= mid) res += query(lson[u], tl, mid, l, r);
	if (r > mid) res += query(rson[u], mid + 1, tr, l, r);
	return res;
}

int main() {
	input(n), input(t);
	for (int i = 1; i <= n; ++ i) {
		input(a[i]); a[i] -= t;
		a[i] += a[i - 1];
	}
	
	for (int i = n; i; -- i) {
		insert(rt, 1, INF << 1, a[i] + INF);
		ans += query(rt, 1, INF << 1, a[i - 1] + INF, INF << 1);
	}
	cout << ans << endl;
	return 0;
}
