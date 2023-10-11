#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e2 + 10;
const int M = 2.5e3 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k;
struct save { int a, b, w; }sv[M];

struct Matrix {
	int mx, my;
	LL a[N][N];
	LL* operator [] (int x) { return a[x]; }
	void init() {
		for (int i = 1; i <= mx; ++ i)
			for (int j = 1; j <= my; ++ j)
				a[i][j] = INF;
		for (int i = 1; i <= mx; ++ i) a[i][i] = 0;
	}
	Matrix operator * (Matrix &b) {
		Matrix tmp, ans;
		ans.mx = mx, tmp.mx = b.mx, tmp.my = ans.my = b.my;
		for (int i = 1; i <= b.mx; ++ i)
			for (int j = 1; j <= b.my; ++ j)
				tmp[i][j] = b[j][i], ans[i][j] = INF;
		for (int i = 1; i <= mx; ++ i)
			for (int j = 1; j <= b.my; ++ j)
				for (int k = 1; k <= my; ++ k)
					ans[i][j] = min(ans[i][j], a[i][k] + tmp[j][k]);
		return ans;
	}
}o, l;

Matrix qpow(Matrix a, int b) {
	Matrix res;
	res.mx = a.mx, res.my = a.my, res.init();
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	l.mx = l.my = o.mx = o.my = n;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			l[i][j] = o[i][j] = i == j ? 0 : INF;
	for (int i = 1; i <= m; ++ i) {
		cin >> sv[i].a >> sv[i].b >> sv[i].w;
		o[sv[i].a][sv[i].b] = sv[i].w;
	}
	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i)
			if (i != k) for (int j = 1; j <= n; ++ j)
				o[i][j] = min(o[i][j], o[i][k] + o[k][j]);
	if (!k) return cout << o[1][n] << '\n', 0;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			l[i][j] = o[i][j];
	for (int i = 1; i <= m; ++ i)
		for (int a = 1; a <= n; ++ a)
			for (int b = 1; b <= n; ++ b)
				l[a][b] = min(l[a][b], o[a][sv[i].a] + o[sv[i].b][b] - sv[i].w);
	return cout << qpow(l, k)[1][n] << '\n', 0;
}
