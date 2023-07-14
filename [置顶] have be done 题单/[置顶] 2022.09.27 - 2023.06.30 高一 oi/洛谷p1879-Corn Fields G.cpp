#include <bits/stdc++.h>
#define ET putchar('\n')

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

const int N = 15;
const int PN = 5e3;
const int MOD = 1e8; 

int n, m, tmp, gph[N];
vector<int> state;
int dp[N][PN];

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			input(tmp); 
			gph[i] = (gph[i] << 1) + tmp;
		}
	}
	for (int i = 0; i < (1 << m); ++ i) {
		if (!(i & (i << 1)) and !(i & (i >> 1)))
			state.push_back(i);
	}
	
	gph[0] = 4095;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		for (auto t : state) 
			if ((t & gph[i]) == t) 
				for (auto pre : state) 
					if (((pre & gph[i - 1]) == pre) and !(t & pre))
						dp[i][t] = (dp[i][t] + dp[i - 1][pre]) % MOD;
	}
	// 
	
	LL ans = 0;
	for (auto t : state) ans = (ans + dp[n][t]) % MOD;
	output(ans);
	return 0;
}
