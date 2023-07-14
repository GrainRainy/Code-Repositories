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
LL l, r;
int nums[N], top;
LL dp[N][N][N][2][2][2][2];

LL init(int p, int a, int b, bool c, bool d, bool _4, bool _8) {
// pos, last, lastlast, cont, is bigger, count4, count 8
	if (_4 and _8) return 0;
	if (p <= 0) return c;
	if (~dp[p][a][b][c][d][_4][_8]) return dp[p][a][b][c][d][_4][_8];
	// spj 
	int lim = !d ? nums[p] : 9;
	LL res = 0;
	for (int i = 0; i <= lim; i ++) {
		res += init(p - 1, i, a, c or (i == a and a == b), d or (i < lim), _4 or (i == 4), _8 or (i == 8));
	}
	return dp[p][a][b][c][d][_4][_8] = res;
}


LL calc(LL x) {
	if (x < 1e10) return 0;
	
	memset(dp, -1, sizeof dp);
	top = 0;
	do nums[++ top] = x % 10, x /= 10; while (x);
	LL res = 0;
	for (int i = 1; i <= nums[top]; i ++ )
		res += init(10, i, 0, 0, i < nums[top], i == 4, i == 8);
	return res;
}


int main() {
	
	
	input(l), input(r);
	cout << calc(r) - calc(l - 1) << endl;
	return 0;
} 
