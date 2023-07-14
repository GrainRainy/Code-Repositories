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

const int N = 2e3 + 10;
const int L = 1e5 + 10;
const int MOD = 1e9 + 7;
int n, m, tmp, minn, ans;
char s[L];
int f[N][N];

int main() {
	input(n), input(m);
	cin >> s + 1;
	for (int i = 1; i <= m; i ++) {
		if (s[i] == '(') tmp ++;
		else tmp --;
		minn = min(minn, tmp);
	}
	
	f[0][0] = 1;
	for (int i = 1; i <= 2000; i ++) {
		f[i][0] = f[i - 1][1];
		for (int j = 1; j <= i; j ++) {
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j + 1]) % MOD;
		}
	}
	
	for (int i = 0; i <= n - m; i ++) {
		for (int j = 0; j <= i; j ++) {
			if (j + minn >= 0 && j + tmp <= n -  m - i)
				ans = (ans + (LL)f[i][j] * f[n - m - i][j + tmp] % MOD) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
