#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 15;
int l, r;
int dp[N][N];
int nums[N], top;

int calc(int pos, int pre, int _0, int big) {
	if (pos <= 0) return 1;
	if (!big and ~dp[pos][pre]) return dp[pos][pre];
	
	int res = 0;
	int lim = big ? nums[pos] : 9;
	for (int i = 0; i <= lim; i ++) {
		if (abs(i - pre) < 2) continue;
		if (_0 and !i) res += calc(pos - 1, -2, 1, big and i == lim);
		else res += calc(pos - 1, i, 0, big and i == lim);
	}
	if (!big and !_0) dp[pos][pre] = res;
	return res;
}

int query(int x) {
	memset(dp, -1, sizeof dp);
	
	top = 0;
	do nums[++ top] = x % 10, x /= 10; while (x);
	return calc(top, -114514, 1, 1);
}

int main() {
	input(l), input(r);
	cout << query(r) - query(l - 1) << '\n';
	return 0;
}
