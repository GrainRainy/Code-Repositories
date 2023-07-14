#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
using namespace std;
const int N = (1 << 11) + 10;
int n, m, a, b, c, dq, delta;
char op[3];
struct BIT {
	int tree[N][N];
	void modify(int x, int y, int val) {
		for (int i = x; i <= n; i += lowbit(i))
			for (int j = y; j <= m; j += lowbit(j))
				tree[i][j] += val;
	}
	int query(int x, int y) {
		int res = 0;
		for (int i = x; i; i -= lowbit(i))
			for (int j = y; j; j -= lowbit(j))
				res += tree[i][j];
		return res;
	}
}d, di, dj, dij; // d, di, dj, dij 

void modify(int x, int y, int val) {
	d.modify(x, y, val);
	di.modify(x, y, val * x);
	dj.modify(x, y, val * y);
	dij.modify(x, y, val * x * y);
}

void modifyRange(int a, int b, int c, int dq, int val) {
	modify(a, b, val);
	modify(a, dq + 1, -val);
	modify(c + 1, b, -val);
	modify(c + 1, dq + 1, val);
}

int query(int x, int y) {
	return d.query(x, y) * (x * y + x + y + 1)
		 - di.query(x, y) * (y + 1)
		 - dj.query(x, y) * (x + 1)
		 + dij.query(x, y);
}

int queryRange(int a, int b, int c, int d) {
	return query(c, d) - query(a - 1, d)
		 - query(c, b - 1) + query(a - 1, b - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> op >> n >> m;
	while (cin >> op) {
		cin >> a >> b >> c >> dq;
		if (*op != 'L') cout << queryRange(a, b, c, dq) << '\n';
		else cin >> delta, modifyRange(a, b, c, dq, delta);
	}
	return 0;
}
