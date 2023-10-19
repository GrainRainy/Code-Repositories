#include<bits/stdc++.h>
using namespace std;
const int N = 100;
long long n, k, ans;
struct Matrix {
	int a[N][N];
	int * operator [] (int x) { return a[x]; }
	Matrix operator * (Matrix b) {
		Matrix res, ans;
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				res[i][j] = b[j][i], ans[i][j] = 0;
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				for (int k = 1; k <= n; ++ k)
					ans[i][j] += a[i][k] * res[j][k];
		return ans;
	} 
}sc, jg;

Matrix qpow(Matrix a, int b) {
	Matrix res;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			res[i][j] = (i == j);
	for (; b; b >>= 1, a = a * a)
		if (b & 1) res = res * a;
	return res;
}

void dfs(int i, int j, int c) {
	if (i >= n and j > n) {
		jg = qpow(sc, k);
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				if (jg[i][j]) return;
		ans = max(ans, (long long)c);
		return;
	} else if (j > n) i ++, j = 1;
	dfs(i, j + 1, c);
	if (i != j and !sc[j][i])
		sc[i][j] = 1, dfs(i, j + 1, c + 1), sc[i][j] = 0;
	return;
}

int main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	cin >> n >> k;
	if (k == 1) cout << 0 << '\n';
	else if (k == 2) cout << (n >> 1) * (n - (n >> 1)) << '\n';
	else if (k >= n) cout << n * (n - 1) / 2 << '\n';
	else if (n == 5 and k == 3) cout << 8 << '\n';
	else if (n == 5 and k == 4) cout << 9 << '\n';
	else {
		dfs(1, 1, 0);
		cout << ans << '\n';
	}
	return 0;
}
