#include <iostream>
#include <cstring>
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

const int L = 20;
const int N = 200;
LL a, b, f[L][N][N];
int stk[L], mod;


LL dp(int pos, int sum, int rem, bool lim) {
// position, sum, remainder, limits
	if (sum + 9 * pos < mod) return 0;
	if (!lim and ~f[pos][sum][rem]) return f[pos][sum][rem];
	if (!pos) return sum == mod & rem == 0;
	LL res = 0, mx = lim ? stk[pos] : 9;
	for (int i = 0; i <= mx and i + sum <= mod; i ++)
		res += dp(pos - 1, sum + i, (rem * 10 + i) % mod, lim & (i == stk[pos]));
	if (!lim) f[pos][sum][rem] = res;
	return res;
}

LL calc(LL u) {
	int top = 0;
	while (u) stk[++ top] = u % 10, u /= 10;

	LL ans = 0;
	for (mod = 1; mod <= top * 9; ++ mod) {
		memset(f, 0xff, sizeof f);
		ans += dp(top, 0, 0, 1);
	}
	return ans;
}

int main() {
	input(a), input(b);
	cout << calc(b) - calc(a - 1) << endl;
	return 0;
}
