#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 5;
const int MOD = 1e4;
int n, m, st, ed, k, nfish;
void upd(int &x, int y) { if ((x += y) >= MOD) x-= MOD; }
struct Matrix {
	int a[N][N];
	int * operator [] (int x) { return a[x]; }
	Matrix operator * (Matrix b) {
		Matrix tmp, res;
		memset(res.a, 0, sizeof res.a);
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				tmp[i][j] = b[j][i];
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				for (int k = 1; k <= n; ++ k)
					upd(res[i][j], a[i][k] * tmp[j][k] % MOD);
		return res;
	}
}ori, t[12], trans, res;

Matrix qpow(Matrix a, int b) {
	Matrix res;
	for (int i = 1; i <= n; ++ i) res[i][i] = 1;
	for (; b; b >>= 1, a = a * a) if (b & 1) res = res * a;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> st >> ed >> k, ori[1][st + 1] = 1;
	for (int i = 1, a, b; i <= m; ++ i) {
		cin >> a >> b;
		for (int j = 0; j < 12; ++ j)
			t[j][a + 1][b + 1] = t[j][b + 1][a + 1] = 1;
	}
	cin >> nfish;
	for (int i = 1, cnt; i <= nfish; ++ i) {
		cin >> cnt;
		for (int j = 0, p; j < cnt; ++ j) {
			cin >> p;
			for (int a = j; a < 12; a += cnt)
				for (int b = 1; b <= n; ++ b)
					t[a][b][p + 1] = 0;
		}
	}
	for (int i = 1; i <= n; ++ i) trans[i][i] = 1;
	for (int i = 1; i < 12; ++ i) trans = trans * t[i];
	trans = trans * t[0], ori = ori * qpow(trans, k / 12);
	for (int i = 1; i <= k % 12; i ++) ori = ori * t[i];
	return cout << ori[1][ed + 1] << '\n', 0;
}
