#include <bits/stdc++.h>
using namespace std;
const int V = 1 << 17;
const int MOD = 998244353;
int n, mx, f[V] ,s[V];

void upd(int &x, int y) { if ((x += y) >= MOD) x -= MOD; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, f[0] = 1;
	mx = n > 10000 ? 1 << 11 : 1 << 16;
	for (int i = 1, a; i <= n; ++ i) {
		cin >> a, f[i] = 1;
		for(int j = mx-1 ; j; j --)
			if((j & a) == j) upd(f[i], s[j]);
		upd(s[a], f[i]);
	}
	for (int i = 1; i <= n; ++ i) cout << f[i] << '\n';
//	cerr << "with time " << (double)clock() / CLOCKS_PER_SEC << '\n';
	return 0;
}
