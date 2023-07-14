#include <iostream>
#include <cstring>
#include <algorithm>

#define endl '\n'

using namespace std;

const int N = 40;
const int K = 110;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int n, m, k;
char gph[K][N][N];
int ansx[K + N * N], ansy[K + N * N], top;
struct Node {
	int cnt, id; 
	bool operator < (const Node &t) const {
		return cnt > t.cnt;
	}
}ary[K];

bool check(int v, int x, int y) {
	bool f = true;
	for (int i = 0; i < 4; ++ i) 
		f &= (gph[v][x][y] != gph[v][x + dx[i]][y + dy[i]]);
	return f;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int v = 1; v <= k + 1; ++ v) {
		for (int i = 1; i <= n; ++ i) cin >> gph[v][i] + 1;
		for (int i = 2; i < n; ++ i)
			for (int j = 2; j < m; ++ j)
				ary[v].cnt += check(v, i, j);
		ary[v].id = v;
	}
	sort(ary + 1, ary + k + 2);
	for (int v = 2, last, now; v <= k + 1; ++ v) {
		last = ary[v - 1].id, now = ary[v].id;
		for (int i = 2; i < n; ++ i)
			for (int j = 2; j < m; ++ j)
				if (gph[last][i][j] != gph[now][i][j]) 
					ansx[++ top] = i, ansy[top] = j;
		ansx[++ top] = ary[v].id, ansy[top] = 0;
	}
	cout << ary[1].id << endl << top << endl;
	for (int i = 1; i <= top; ++ i) {
		if (ansy[i]) cout << "1 " << ansx[i] << ' ' << ansy[i] << endl;
		else cout << "2 " << ansx[i] << endl;
	}
	return 0;
}
