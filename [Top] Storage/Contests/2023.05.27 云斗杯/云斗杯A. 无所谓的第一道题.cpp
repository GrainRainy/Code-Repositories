#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int n, ans;
char s[N][N];

bool judge(int x, int y) {
	return (x > 0 and x <= n and y > 0 and y <= n);
}

int calc(int x, int y, int len) {
	int nx = x + len - 1, ny = y;
	for (int i = 1; i <= len; ++ i) {
		if (!judge(x, y) or !judge(nx, ny) or s[x][y] == '0' or s[nx][ny] == '0')
			return 0;
		x ++, y ++, nx --, ny ++;
	}
	return 1;
}

void dfs(int x, int y) {
	for (int i = x + 1; i <= n; ++ i) 
		if (s[i][y] == '1') ans += calc(x, y, i - x + 1);
	return;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> s[i] + 1;
	
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			if (s[i][j] == '1') dfs(i, j);
	
	cout << ans << endl;
	return 0;
}
