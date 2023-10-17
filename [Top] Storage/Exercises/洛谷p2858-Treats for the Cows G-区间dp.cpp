#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int n, s[N], f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) 
		cin >> s[i], f[i][i] = s[i], s[i] += s[i - 1];
	for (int len = 1; len <= n; ++ len)
		for (int l = 1; l + len - 1 <= n; ++ l)
			f[l][l + len - 1] = max(f[l + 1][l + len - 1] + s[l + len - 1] - s[l - 1],
									f[l][l + len - 2] + s[l + len - 1] - s[l - 1]);
	return cout << f[1][n] << '\n', 0;	
}
