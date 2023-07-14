#include <iostream>
#include <cstring>

using namespace std;
using LL = long long;

const int N = 12;
const int M = 1.2e3 + 10;
int t, n, m; char c;
bool gph[N][M], tmp[N][M];
int ans, cnt;

void flip(int x, int y) {
	tmp[x - 1][y] ^= 1, tmp[x + 1][y] ^= 1, tmp[x][y] ^= 1;
	tmp[x][y - 1] ^= 1, tmp[x][y + 1] ^= 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> t;
	while (t --) {
		ans = 0x3f3f3f3f;
		cin >> n >> m;
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= m; ++ j)
				cin >> c, gph[i][j] = c - 'A';

		for (int s = 0; s < (1 << n); ++ s) {
			cnt = 0;
			for (int i = 1; i <= n; ++ i)
				for (int j = 1; j <= m; ++ j)
					tmp[i][j] = gph[i][j];
			// init 
			for (int i = 1; i <= n; ++ i)
				if ((s >> (i - 1)) & 1) flip(i, 1), cnt ++;
			for (int j = 2; j <= m; ++ j) 
				for (int i = 1; i <= n; ++ i) 
					if (tmp[i][j - 1]) flip(i, j), cnt ++;
			bool judge = false;
			for (int i = 1; i <= n; ++ i) judge |= tmp[i][m];
			if (!judge) ans = min(ans, cnt);
		}
		cout << ans << endl;
	}
	return 0;
}
