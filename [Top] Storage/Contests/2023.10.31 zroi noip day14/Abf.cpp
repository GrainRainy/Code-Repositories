#include <bits/stdc++.h>
using namespace std;
const int N = 50;
const int MOD = 998244353;
int n, a[10][N];
int ans;

int mid(int a, int b, int c, int d, int e) {
	vector<int> res;
	res.emplace_back(a), res.emplace_back(b), res.emplace_back(c);
	res.emplace_back(d), res.emplace_back(e);
	sort(res.begin(), res.end());
	return res[2] == 2;
}

void upd(int &x, const int &y) { if ((x += y) >= MOD) x -= MOD ; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= 5; ++ i)
		for (int j = 1; j <= n; ++ j)
			cin >> a[i][j];
//	for (int i = 1; i <= n; ++ i)
	for (int i = 2; i <= 2; ++ i)
		for (int j = 1; j <= n; ++ j)
			for (int k = 1; k <= n; ++ k)
				for (int l = 1; l <= n; ++ l)
					for (int m = 1; m <= n; ++ m) {
						if (mid(a[1][i], a[2][j], a[3][k], a[4][l], a[5][m]))
							cout << a[1][i] << ' ' << a[2][j] << ' ' << a[3][k] << ' ' << a[4][l] << ' ' << a[5][m] << '\n';
						upd(ans, mid(a[1][i], a[2][j], a[3][k], a[4][l], a[5][m])); 
					}
	return cout << ans << '\n', 0;
}
