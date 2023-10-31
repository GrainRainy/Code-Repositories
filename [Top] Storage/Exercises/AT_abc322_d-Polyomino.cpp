#include <bits/stdc++.h>
using namespace std;
int n, cnt, cd[5][5][5], mp[15][15], cp[5][5];
char c;

void rot(int id) {
	for (int i = 1; i <= 4; ++ i)
		for (int j = 1; j <= 4; ++ j)
			cp[j][4 - i + 1] = cd[id][i][j];
	memcpy(cd[id], cp, sizeof cp);
}

void dfs(int pos) {
	if (pos == 4) {
		for (int i = 5; i <= 8; ++ i)
			for (int j = 5; j <= 8; ++ j)
				if (mp[i][j] != 1) return;
		puts("Yes"), exit(0);
	}
	for (int c = 1; c <= 4; ++ c) {
		rot(pos);
		for (int i = 2; i <= 8; ++ i)
			for (int j = 2; j <= 8; ++ j) {
				for (int a = 1; a <= 4; ++ a)
					for (int b = 1; b <= 4; ++ b)
						mp[i + a - 1][j + b - 1] += cd[pos][a][b];
				dfs(pos + 1);
				for (int a = 1; a <= 4; ++ a)
					for (int b = 1; b <= 4; ++ b)
						mp[i + a - 1][j + b - 1] -= cd[pos][a][b];
			}
	}			
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 3; ++ i)
		for (int j = 1; j <= 4; ++ j)
			for (int k = 1; k <= 4; ++ k)
				cin >> c, cnt += (cd[i][j][k] = c == '#');
	if (cnt == 16) dfs(1);
	return puts("No") & 0;
}
