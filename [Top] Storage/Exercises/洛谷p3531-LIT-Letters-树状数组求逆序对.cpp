#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
int n, c[30][N], cc[30];
char a[N], b[N];
LL tr[N], ans;

inline void add(int p, int v) { while (p <= n) tr[p] += v, p += p & -p; }
LL query(int p) { LL r = 0; while (p) r += tr[p], p -= p & -p; return r; }
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> a + 1 >> b + 1;
	for (int i = 1; i <= n; ++ i) c[a[i] - 'A'][++ c[a[i] - 'A'][0]] = i;
	for (int i = 1, tmp; i <= n; ++ i) 
		tmp = c[b[i] - 'A'][++ cc[b[i] - 'A']], ans += query(n) - query(tmp - 1), add(tmp, 1);
	return cout << ans << '\n', 0;
}
