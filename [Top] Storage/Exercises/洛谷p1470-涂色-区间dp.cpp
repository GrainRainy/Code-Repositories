#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 10;
int n, f[N][N];
char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s + 1, n = strlen(s + 1);
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; ++ i) f[i][i] = 1;
	for (int len = 2; len <= n; ++ len)
		for (int l = 1; l + len - 1 <= n; ++ l) {
			if (s[l] == s[l + len - 1]) 
				f[l][l + len - 1] = min(f[l][l + len - 2], f[l + 1][l + len - 1]);
			for (int mid = l; mid < l + len; ++ mid)
				f[l][l + len - 1] = min(f[l][l + len - 1], f[l][mid] + f[mid + 1][l + len - 1]);
		}
	return cout << f[1][n] << '\n', 0;	
}
