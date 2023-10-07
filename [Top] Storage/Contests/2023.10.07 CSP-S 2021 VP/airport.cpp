#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using PII = pair<int, int>;
const int N = 2e5 + 10;
int n, ma, mb;
struct Range { 
	int l, r; 
	bool operator < (const Range &t) const { return l < t.l; }
}a[N], b[N];
struct Fenwick {
	int tr[N];
	inline void add(int p, int v) { while (p <= n) tr[p] += v, p += p & -p; }
	int query(int r) { int res = 0; while (r) res += tr[r], r -= r & -r; return res; }
}t;
priority_queue<PII, vector<PII>, greater<PII>> q; 
int sa[N], sb[N];
int res;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	rd(n), rd(ma), rd(mb);
	for (int i = 1; i <= ma; ++ i) rd(a[i].l), rd(a[i].r);
	for (int i = 1; i <= mb; ++ i) rd(b[i].l), rd(b[i].r);
	sort(a + 1, a + ma + 1), sort(b + 1, b + mb + 1);
	for (int i = 1; i <= ma; ++ i) {
		while (q.size() and q.top().fi < a[i].l) t.add(q.top().se, -1), q.pop();
		int l = 1, r = ma + mb, mid;
		while (l < r) {
			mid = l + r >> 1;
			if (t.query(mid) < mid) r = mid;
			else l = mid + 1;
		}
		sa[l] ++;
		q.push({a[i].r, l}), t.add(l, 1);
	}
	memset(t.tr, 0, sizeof t.tr);
	while (q.size()) q.pop();
	for (int i = 1; i <= mb; ++ i) {
		while (q.size() and q.top().fi < b[i].l) t.add(q.top().se, -1), q.pop();
		int l = 1, r = ma + mb, mid;
		while (l < r) {
			mid = l + r >> 1;
			if (t.query(mid) < mid) r = mid;
			else l = mid + 1;
		}
		sb[l] ++;
		q.push({b[i].r, l}), t.add(l, 1);
	}
	for (int i = 1; i <= n; ++ i) sa[i] += sa[i - 1], sb[i] += sb[i - 1];
	for (int i = 0; i <= n; ++ i) res = max(res, sa[i] + sb[n - i]);
	return cout << res << '\n', 0;
}
