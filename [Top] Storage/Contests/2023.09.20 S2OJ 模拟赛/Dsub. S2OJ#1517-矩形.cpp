#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, q;
int sm[N][N];
struct Square { int a, b, c, d; }a[N];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void add(int a, int b, int c, int d) {
	sm[a][b] ++, sm[c + 1][d + 1] ++;
	sm[a][d + 1] --, sm[c + 1][b] --;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
		add(a[i].a, a[i].b, a[i].c, a[i].d);
	}
	for (int i = 1, v, r, d; i <= m; ++ i) {
		cin >> v >> r >> d;
		while (d --) {
			a[r].a += dx[v], a[r].c += dx[v];
			a[r].b += dy[v], a[r].d += dy[v];
			add(a[r].a, a[r].b, a[r].c, a[r].d);
		}
	}
	for (int i = 1; i <= 100; ++ i)
		for (int j = 1; j <= 100; ++ j)
			sm[i][j] += sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1];	
	int a, b;
	while (q --) {
		cin >> a >> b;
		cout << sm[a][b] << '\n';
	}
	return 0;
}
