#include <bits/stdc++.h>
using namespace std;
const short N = 25 + 5;
const short M = 5e2 + 10;
const short MOD = 5557;
short n, m, ans;
int t;
string s;
struct Save { short a, b, w; }save[M];

inline void upd(short &x, short y) {
	x += y;
	x < 0 ? x += MOD : x >= MOD ? x -= MOD : 0;
}

struct Matrix {
	int a[N << 1][N << 1], mx, my;
	int* operator [] (int x) { return a[x]; }
	Matrix(int n, int m) { mx = n, my = m; memset(a, 0, sizeof a); }
	Matrix operator * (Matrix t) {
		Matrix ans(mx, t.my);
		for (int i = 0; i <= mx; ++ i)
			for (int j = 0; j <= t.my; ++ j){
				for (int k = 0; k <= my; ++ k)
					ans[i][j] += a[i][k] * t[k][j];
				ans[i][j] %= MOD;
			}
		return ans;
	}
};

short hsh(string a) {
	short res = 0;
	for (auto c : a) {
		if (c == 'B') res |= 1 << 3;
		if (c == 'J') res |= 1 << 2;
		if (c == 'M') res |= 1 << 1;
		if (c == 'P') res |= 1;
	}
	return res;
}

short solve(short s) {
	Matrix a(n << 1, n << 1), b(1, n << 1);
	a[0][0] = b[1][1] = 1;
	for (int i = 1; i <= n; ++ i) a[i][i + n] ++;
	for (int i = 1; i <= m; ++ i) {
		a[save[i].a][save[i].b] ++;
		if ((save[i].w | s) == s) a[save[i].a + n][save[i].b] ++;
	}
	for (int i = 1; i <= n << 1; ++ i) a[i][0] = a[i][1];
	for (int i = 0; 1 << i <= t; ++ i) {
		if (t & (1 << i)) b = b * a;
		a = a * a;
	}
	return b[1][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (short i = 1, u, v; i <= m; ++ i) {
		cin >> u >> v >> s;
		save[i] = {u, v, hsh(s)};
	}
	cin >> t;
	for (short s = 0, f, tmp; s < 1 << 4; ++ s) {
		f = 1, tmp = s;
		while (tmp) { if (tmp & 1) f = -f; tmp >>= 1; }
		upd(ans, solve(s) * f);
	}
	return cout << ans << '\n', 0;
}
