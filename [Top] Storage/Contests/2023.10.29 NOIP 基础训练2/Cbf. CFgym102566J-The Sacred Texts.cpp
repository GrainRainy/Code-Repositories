#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 20;
const int M = 1e5 + 10;
int n, m, q, gh[N][M];
LL sm[N][M];

LL qry(int a, int b, int c, int d) {
//	if (sm[c][d] - sm[a - 1][d] - sm[c][b - 1] + sm[a - 1][b - 1] == 10)
//		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	return sm[c][d] - sm[a - 1][d] - sm[c][b - 1] + sm[a - 1][b - 1];
}

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j) {
			cin >> gh[i][j];
			sm[i][j] = gh[i][j] + sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1];
		}
	cin >> q;
	for (int i = 1, op, a, b, c, d, v; i <= q; ++ i) {
		cin >> op;
		if (op == 1) {
			cin >> a >> b >> v;
			LL dt = v - gh[a][b];
			gh[a][b] = v;
			for (int pa = a; pa <= n; ++ pa)
				for (int pb = b; pb <= m; ++ pb)
					sm[pa][pb] += dt;
		} else {
			cin >> a >> b >> c >> d;
			LL mx = -1e18;
			for (int pa = a; pa <= c; ++ pa)
				for (int pb = b; pb <= d; ++ pb)
					for (int pc = pa; pc <= c; ++ pc)
						for (int pd = pb; pd <= d; ++ pd)
							mx = max(mx, qry(pa, pb, pc, pd));
			cout << mx << '\n';
		}
	}
	return 0;
}
