#include <bits/stdc++.h>

#define __DEBUG__ print();

using namespace std;
using LL = long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 2e3 + 10;
int n, k;
LL tot[N];
LL f[N][N]; 

int main() {
	input(n), input(k);
	for (int i = 1; i <= n; i ++) {
		input(tot[i]); tot[i] += tot[i - 1];
	}
	if (k == tot[n]) return puts("1"), 0;
	
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; ++ i) f[i][0] = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= i; ++ j) {
			if (i == 1) f[i][j] = 1;
			else f[i][j] = min(f[i - 1][j], f[i - 1][j - 1] * tot[i] / tot[i - 1] + 1);
		}
	}	
	for (int i = n; i >= 0; -- i) {
		if (f[n][i] <= k) return cout << i << endl, 0;
	}
}
