#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
}

using IO::rd;
using namespace std;
const int N = 1e2 + 10;
const int MOD = 1e9 + 7;
int n, prex[N];
struct Segment {
	int l, r; 
	bool operator < (const Segment &t) const {
		return l < t.l or l == t.l and r < t.r;
	}
}a[N];
int f[2][N << 1][N];

inline void upd(int &x, int y) { x += y; (x >= MOD) and (x -= MOD); }

int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) rd(a[i].l), rd(a[i].r);
	sort(a + 1, a + n + 1);
	f[0][0][0] = 1;
	for (int i = 0; i <= n; ++ i) {
		prex[i] = max(prex[max(i - 1, 0)], a[i].r);
		memset(f[i + 1 & 1], 0, sizeof f[i + 1 & 1]);
		for (int r = 0; r <= prex[i]; ++ r)
			for (int c = 0; c <= i; ++ c) {
				upd(f[i + 1 & 1][r][c], f[i & 1][r][c]);
				upd(f[i + 1 & 1][max(r, a[i + 1].r)][c + (a[i + 1].l >= r)], f[i & 1][r][c]);
			}
	}
	int ans = 0;
	for (int r = 1; r <= n << 1; ++ r)
		for (int c = 1; c <= n; ++ c)
			upd(ans, f[n & 1][r][c] * c % MOD);
	return cout << ans << '\n', 0;
}
