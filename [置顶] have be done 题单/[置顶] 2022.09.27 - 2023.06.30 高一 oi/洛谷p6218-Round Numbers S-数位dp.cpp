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

const int N = 32; // LOGN 
int l, r;
int nums[N], top;
int dp[N][N][N][2];

int calc(int pos, int cnt0, int cnt1, bool pob, bool _0) {
	if (pos <= 0) return (_0 or cnt0 >= cnt1);
	if (!pob and !_0 and ~dp[pos][cnt0][cnt1][pob]) return dp[pos][cnt0][cnt1][pob];
	
	LL res = 0, lim = pob ? nums[pos] : 1;
	for (int i = 0; i <= lim; i ++) {
		if (_0 and !i) res += calc(pos - 1, 0, 0, (pob and i == lim), 1);
		else res += calc(pos - 1, cnt0 + (i == 0), cnt1 + (i == 1), (pob and i == lim), 0);
	}
	if (!pob and !_0) dp[pos][cnt0][cnt1][pob] = res;
	return res;
}

int query(int x) {
	memset(dp, -1, sizeof dp);
	
	top = 0;
	do nums[++ top] = x & 1, x >>= 1; while (x);
	return calc(top, 0, 0, 1, 1);
}

int main() {
	input(l, r);
	cout << query(r) - query(l - 1) << endl;
	return 0;
}
