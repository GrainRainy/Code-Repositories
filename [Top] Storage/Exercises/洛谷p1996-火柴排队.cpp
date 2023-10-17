#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
using namespace std;
const int N = 1e5 + 10;
const int MOD = 1e8 - 3;
int n, tr[N], ans;
struct Ary { int v, id, rk; }a[N], b[N];
bool cmp1(Ary a, Ary b) { return a.v < b.v; }
bool cmp2(Ary a, Ary b) { return a.id < b.id; }
inline void add(int p, int v) { while (p <= n) tr[p] += v, p += p & -p; }
int query(int p) { int r = 0; while (p) r += tr[p], p -= p & -p; return r; }
void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i].v, a[i].id = i;
	for (int i = 1; i <= n; ++ i) cin >> b[i].v, b[i].id = i;
	sort(a + 1, a + n + 1, cmp1), sort(b + 1, b + n + 1, cmp1);
	for (int i = 1; i <= n; ++ i) a[i].rk = i;
	sort(a + 1, a + n + 1, cmp2);
	for (int i = 1; i <= n; ++ i) b[a[i].rk].rk = i;
	sort(b + 1, b + n + 1, cmp2);
	for (int i = 1; i <= n; ++ i)
		upd(ans, query(n) - query(b[i].rk - 1)), add(b[i].rk, 1);
	return cout << ans << '\n', 0;
}
