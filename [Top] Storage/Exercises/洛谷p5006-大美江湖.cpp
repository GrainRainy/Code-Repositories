#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
const int dx[5] = {0, 0, 0, -1, 1};
const int dy[5] = {0, -1, 1, 0, 0};
int n, m, q, nx, ny, st, de, mhp, mst, mde, del;
char g[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> g[i] + 1;
	cin >> mhp >> mst >> mde >> nx >> ny >> st >> de >> q;
	for (int i = 1, op, d; i <= q; ++ i) {
		cin >> op;
		if (op == 1) cout << del << ' ' << st << ' ' << de << '\n';
		else {
			cin >> d;
			nx += dx[d], ny += dy[d];
			if (g[nx][ny] == 'R') del = max(del - 10, 0);
			if (g[nx][ny] == 'Q') st += 5;
			if (g[nx][ny] == 'Y') de += 5;
			if (g[nx][ny] == 'M')
				del += max(1, (int)(ceil((double)mhp / max(1, st - mde)) * max(1, mst - de)));
		}
	}
	return 0;
}
