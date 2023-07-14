#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std; 
using LL = long long;

template <typename T> inline void input (T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e6 + 10;
const int MOD = 998244353;
int id, n, m, u, v;
LL f[N], sum[N];
vector<LL> gph[N];

int main() {
	input(id), input(n), input(m);
	for (int i = 1; i <= m; ++ i) {
		input(u), input(v);
		gph[u].push_back(v);
	}
	
	for (int i = 1; i <= n; ++ i) {
		f[i] = gph[i].size() + 1;
		for (auto t : gph[i]) {
			f[i] = (f[i] + sum[i - 1] - sum[t - 1]) % MOD + MOD;
		}
		sum[i] = (sum[i - 1] + f[i]) % MOD;
	}
	printf("%d\n", sum[n]);
	return 0;
}
