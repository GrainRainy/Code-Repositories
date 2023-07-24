#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar()) ;
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
}

using IO::input;
using namespace std;
const int N = 1e6 + 10;
const int MOD = 998244353;
using LL = long long;
int n, a, ans;
int tree[N], fac[N] = {1};

void upd(int &x, int y) { (x += y) >= MOD and (x -= MOD); }
void modify(int x, int y) { while (x <= n) tree[x] += y, x += x & -x; }
int query(int r) {
	int res = 0;
	while (r) res += tree[r], r -= r & -r;
	return res;
}

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) {
		fac[i] = (LL)fac[i - 1] * i % MOD;
		modify(i, 1);
	}
	for (int i = 1; i <= n; ++ i) {
		input(a);
		upd(ans, (LL)query(a - 1) * fac[n - i] % MOD);
		modify(a, -1);
	}
	return cout << ans + 1 << '\n', 0; 
} 
