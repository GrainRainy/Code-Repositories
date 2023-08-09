#include <bits/stdc++.h>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace IO;
using namespace std;
using PII = pair<int, int>;

const int N = 1e3 + 10;
int n, m, k, top, ans;
int gph[N][N];
char c[3];
map<int, PII> mp; 

bool check(int x, int y) {
	int res[2] = {0, 0};
	res[gph[x][y]] ++, res[gph[x + 1][y]] ++;
	res[gph[x][y + 1]] ++, res[gph[x + 1][y + 1]] ++;
	if (res[0] != res[1]) return false;
	return true;
}

int main() {
	input(n), input(m), input(k);
	memset(gph, 0xff, sizeof gph);
	if (n <= 10) {
		for (int i = 1, x, y; i <= k; ++ i) {
			cin >> c; input(x), input(y);
			if (c[0] == '+') gph[x][y] = 1;
			else gph[x][y] = 0; 
		}
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= m; ++ j)
				if (!(~gph[i][j])) mp[++ top] = {i, j};
		for (int s = 0; s < (1 << top); ++ s) {
			for (int i = 1; i <= top; ++ i)
				if (s >> (i - 1) & 1) gph[mp[i].first][mp[i].second] = 1;
				else gph[mp[i].first][mp[i].second] = 0;
			bool f = true;
			for (int i = 1; i < n; ++ i)
				for (int j = 1; j < m; ++ j)
					f &= check(i, j);
			if (f) ans ++;
		}
		cout << ans << endl;
	} else puts("0");
	return 0;
}

