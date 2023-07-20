#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using IO::input;
using namespace std;
const int N = 3e2 + 10;
const int LOGN = 10;
int n, m, ans;
int dis[LOGN + 5][N][N], now[N][N], pre[N][N];

bool judge() {
	for (int i = 1; i <= n; ++ i)
		if (now[i][i] > 0) return true;
	return false;
}

int main() {
	input(n), input(m);
	memset(dis, 0xcf, sizeof dis);
	memset(pre, 0xcf, sizeof pre);
	for (int i = 1; i <= n; ++ i) pre[i][i] = dis[0][i][i] = 0;
	for (int i = 1, x, y, z, w; i <= m; ++ i) {
		input(x), input(y), input(z), input(w);
		dis[0][x][y] = z, dis[0][y][x] = w;
	}
	
	for (int s = 1; s <= LOGN; ++ s)
		for (int k = 1; k <= n; ++ k)
			for (int i = 1; i <= n; ++ i)
				for (int j = 1; j <= n; ++ j) 
					dis[s][i][j] = max(dis[s][i][j], dis[s - 1][i][k] + dis[s - 1][k][j]);
	
	for (int s = LOGN; ~s; -- s) {
		memset(now, 0xcf, sizeof now);
		for (int k = 1; k <= n; ++ k)
			for (int i = 1; i <= n; ++ i)
				for (int j = 1; j <= n; ++ j)
					now[i][j] = max(now[i][j], pre[i][k] + dis[s][k][j]);
		if (judge()) continue;
		else {
			for (int i = 1; i <= n; ++ i)
				for (int j = 1; j <= n; ++ j)
					pre[i][j] = now[i][j];
			ans += 1 << s;
		}
	}
	return printf("%d\n", ans >= n ? 0 : ans + 1), 0;
}
