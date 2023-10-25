#include <bits/stdc++.h>
using namespace std;
const int N = 8e3 + 10;
int n;
char a[N];
bool st[N][N];
vector<int> l[N];
long long ans;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> a + 1;
	for (int i = 1; i <= n; ++ i) {
		int j = 0;
		while (i - j > 0 and a[i - j] == a[i + 1 + j]) {
//			l[i - j].push_back(i + 1 + j);
			st[i - j][i + 1 + j] = true;
//			cout << i - j << ' ' << i + 1 + j << '\n';
			j ++;
		}
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = i + 1; j < n; ++ j) {
			if (st[i][j]) 
				for (int k = j + 2; k <= n; ++ k)
					if (st[j + 1][k]) st[i][k] = true;
		}
//	for (int i = 1; i <= n; ++ i)
//		for (int j = 1; j <= n; ++ j)
//			if (st[i][j]) cout << i << ' ' << j << '\n';
	for (int i = 1; i <= n; ++ i) 
		for (int j = i; j <= n; ++ j)
			ans += st[i][j];
	cout << ans << '\n';
}
