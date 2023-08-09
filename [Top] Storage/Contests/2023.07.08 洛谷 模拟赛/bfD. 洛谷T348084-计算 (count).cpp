#include <bits/stdc++.h>
#define int long long
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace IO;
using namespace std;
using LL = long long;
const int MOD = 998244353;
int n, m;
vector<int> nums;
int ary[210], cnt;

void div(int u) {
	for (int i = 1; i <= u; ++ i)
		if (!(u % i)) nums.push_back(i);
}

void dfs(int pos) {
	if (pos == (m << 1) + 1) {
		LL sum = 1;
		for (int i = 1; i <= (m << 1); ++ i)
			sum *= ary[i];
		if (sum <= pow(n, m)) cnt = (cnt + 1) % MOD;
		return;
	}
	for (auto t : nums) {
		ary[pos] = t;
		dfs(pos + 1);
		ary[pos] = 0;
	}
	return;
}

signed main() {
	input(n), input(m);
	div(n);
	dfs(1);
	printf("%d\n", cnt);
	return 0;
}
