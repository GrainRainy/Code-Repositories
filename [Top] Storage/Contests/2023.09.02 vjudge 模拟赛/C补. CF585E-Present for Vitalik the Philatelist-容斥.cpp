#include <bits/stdc++.h>
template <typename T> inline void rd(T &x) {
	#ifdef __LINUX__
	#define getchar() getchar_unlocked()
	#endif
	#ifdef __WINDOWS__
	#define getchar() _getchar_nolock()
	#endif
	x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}
using namespace std;
using LL = long long;
const int N = 5e5 + 10;
const int L = 1e7 + 10;
const int MOD = 1e9 + 7;
int n, c[L], q2[N] = {1}, f[L], h[L], mx;

int main() {
	rd(n);
	for (int i = 1, tmp; i <= n; ++ i) {
		rd(tmp), c[tmp] ++;
		mx = max(mx, tmp);
		if ((q2[i] += q2[i - 1] + q2[i - 1]) >= MOD) q2[i] -= MOD;
	}
	for (int i = mx, ca; i; -- i) {
		ca = 0;
		for (int j = i; j <= mx; j += i) ca += c[j];
		f[i] = q2[ca] - 1;
		for (int j = i << 1; j <= mx; j += i) 
			if ((f[i] -= f[j]) < 0) f[i] += MOD;
		for (int j = i; j <= mx; j += i) 
			if ((h[i] += f[j]) >= MOD) h[i] -= MOD;
		h[i] = (LL)h[i] * ca % MOD;
		for (int j = i << 1; j <= mx; j += i) 
			if ((h[i] -= h[j]) < 0) h[i] += MOD;
	}
	if ((h[1] -= (LL)f[1] * n % MOD) < 0) h[1] += MOD;
	return cout << h[1] << '\n', 0;
}
