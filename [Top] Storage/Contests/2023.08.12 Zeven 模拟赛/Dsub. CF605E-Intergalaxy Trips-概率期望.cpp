#include <bits/stdc++.h>
#define debug(x) cout << #x << ' ' << x << endl;
using namespace std;
const int N = 1e3 + 10;
int n, path[N];
bool st[N];
double p[N][N], f[N];
int id;

namespace sub3 {
	bool judge = true;
	void solve() {
		for (int i = n - 1; i; -- i) 
			f[i] = f[i + 1] + 1.0 / p[i][i + 1];
		cout << f[1] << endl;
		return;
	}
}

int main() {
	freopen("trip.in", "r", stdin);
	freopen("trip.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j) {
			cin >> p[i][j];
			p[i][j] /= 100;
			if (j != i + 1 and p[i][j])
				sub3::judge = false;
		}
	if (sub3::judge) return sub3::solve(), 0;
	path[1] = n, st[n] = true;
	double mn, prep, tmpf; int id;
	for (int i = 2; i <= n; ++ i) {
		mn = 1e9 + 10, id = 0;
		for (int j = 1; j <= n; ++ j) {
			if (st[j]) continue;
			prep = tmpf = 1;
			for (int k = 1; k < i; ++ k) {
				tmpf += prep * p[j][path[k]] * f[path[k]];
				prep *= 1 - p[j][path[k]];
			}
			tmpf /= (1 - prep);
			if (tmpf < mn) mn = tmpf, id = j;
		}
		f[id] = mn, path[i] = id, st[id] = true;
		if (id == 1) {
			printf("%.15lf\n", f[1]);
			return 0;
		}
	}	
	return 0;
}
