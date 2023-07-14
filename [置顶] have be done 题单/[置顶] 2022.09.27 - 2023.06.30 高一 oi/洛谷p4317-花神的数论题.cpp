#include <bits/stdc++.h>
#define enter putchar('\n')

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar(); bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T, typename... Args> void input(T &x, Args&... args) {
	input(x), input(args...);
}
template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 60;
const int MOD = 10000007;
LL n;
LL nums[N], top;
LL cnt[N], dp[N][N][N][2];

LL qpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

LL calc(int pos, int cnt, int tot, bool big) {
	if (pos <= 0) return (cnt == tot);
	if (~dp[pos][cnt][tot][big]) return dp[pos][cnt][tot][big];
	
	LL res = 0, lim = big ? nums[pos] : 1;
	for (int i = 0; i <= lim; ++ i) {
		res += calc(pos - 1, cnt + (i == 1), tot, big and (i == lim));
	}
	return dp[pos][cnt][tot][big] = res;
}

LL query(LL x) {
	top = 0;
	do nums[++ top] = x & 1, x >>= 1; while (x);
	
	LL res = 1;
	for (int i = 1; i <= 50; i ++) {
		memset(dp, -1, sizeof dp);
		cnt[i] = calc(top, 0, i, 1);
	}
	
	for (int i = 1; i <= top; i ++) {
		res = res * qpow(i, cnt[i]) % MOD;
	}
	return res;
}

int main() {
	input(n);
	cout << query(n) << endl;
	return 0;
}
