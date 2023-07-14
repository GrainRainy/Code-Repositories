#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
using PII = pair<int, int>;
const int N = 7e2 + 10;
const int INF = 0x3f3f3f3f;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n, m, y, v, t;
char gph[N][N];
int vvis[N][N], lim[N][N], vis[N][N];

int to(int x, int y) { return x * m + y; }
PII ot(int x) { return {x / m, x % m}; }
bool judge(int x, int y) { return x >= 0 and x < n and y >= 0 and y < m; }

void init(int s) {
	memset(vvis, 0x3f, sizeof vvis);
	queue<PII> q;
	int tmpx = ot(s).first, tmpy = ot(s).second;
	vvis[tmpx][tmpy] = 0; q.push({tmpx, tmpy});
	while (q.size()) {
		tmpx = q.front().first, tmpy = q.front().second;
		q.pop();
		for (int i = 0, nx, ny; i < 4; ++ i) {
			nx = tmpx + dx[i], ny = tmpy + dy[i];
			if (judge(nx, ny) and gph[nx][ny] != 'I' and vvis[nx][ny] == INF) {
				vvis[nx][ny] = vvis[tmpx][tmpy] + 1;
				q.push({nx, ny});
			} 
		}
	}
}

void spread() {
	for (int i = 0, tmpm; i < n; ++ i) {
		for (int j = 0, k; j < m;) {
			if (gph[i][j] != 'I') {
				tmpm = vvis[i][j];
				for (k = j; k < m - 1 and gph[i][k + 1] != 'I';)
					tmpm = min(tmpm, vvis[i][++ k]);
				while (j <= k) lim[i][j ++] = tmpm;
			} else j ++;
		}
	}
	
	for (int j = 0, tmpm; j < m; ++ j) {
		for (int i = 0, k; i < n;) {
			if (gph[i][j] != 'I') {
				tmpm = vvis[i][j];
				for (k = i; k < n - 1 and gph[k + 1][j] != 'I';) 
					tmpm = min(tmpm, vvis[++ k][j]);
				while (i <= k) lim[i][j] = min(lim[i][j], tmpm), ++ i;
			} else i ++;
		}
	}
}

void dfs(int s) {
	memset(vis, 0x3f, sizeof vis);
	queue<PII> q;
	int tmpx = ot(s).first, tmpy = ot(s).second;
	vis[tmpx][tmpy] = 0; q.push({tmpx, tmpy});
	while (q.size()) {
		tmpx = q.front().first, tmpy = q.front().second;
		tmpx = q.front().first, tmpy = q.front().second;
		q.pop();
		for (int i = 0, nx, ny; i < 4; ++ i) {
			nx = tmpx + dx[i], ny = tmpy + dy[i];
			if (judge(nx, ny) and gph[nx][ny] != 'I' and lim[nx][ny] > vis[tmpx][tmpy] + 1 and vis[nx][ny] == INF) {
				vis[nx][ny] = vis[tmpx][tmpy] + 1;
				q.push({nx, ny});
			} 
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++ i) {
		cin >> gph[i];
		for (int j = 0; j < m; ++ j) {
			if (gph[i][j] == 'Y') y = to(i, j);
			if (gph[i][j] == 'V') v = to(i, j);
			if (gph[i][j] == 'T') t = to(i, j);
		}			
	}
	init(v), spread();
	dfs(y);
	cout << ((vis[ot(t).first][ot(t).second] < 0x3f3f3f3f) ? "YES" : "NO") << endl;
	return 0;
}
