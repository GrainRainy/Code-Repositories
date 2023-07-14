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

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
int n;
char a[N];
LL f[N][4];

int main() {
	cin >> a + 1;
	n = strlen(a + 1);
	
	f[1][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		if (a[i] == '?'){
			f[i + 1][0] = (f[i + 1][0] + f[i][0] * 3) % MOD;
			f[i + 1][1] = (f[i + 1][1] + f[i][1] * 3) % MOD;
			f[i + 1][2] = (f[i + 1][2] + f[i][2] * 3) % MOD;
			f[i + 1][3] = (f[i + 1][3] + f[i][3] * 3) % MOD;
		}
		else {
			f[i + 1][0] = (f[i + 1][0] + f[i][0]) % MOD;
			f[i + 1][1] = (f[i + 1][1] + f[i][1]) % MOD;
			f[i + 1][2] = (f[i + 1][2] + f[i][2]) % MOD;
			f[i + 1][3] = (f[i + 1][3] + f[i][3]) % MOD;
		}
		
		if (a[i] == '?') {
			f[i + 1][1] = (f[i + 1][1] + f[i][0]) % MOD;
			f[i + 1][2] = (f[i + 1][2] + f[i][1]) % MOD;
			f[i + 1][3] = (f[i + 1][3] + f[i][2]) % MOD;
		}
		if (a[i] == 'A') f[i + 1][1] = (f[i + 1][1] + f[i][0]) % MOD;
		if (a[i] == 'B') f[i + 1][2] = (f[i + 1][2] + f[i][1]) % MOD;
		if (a[i] == 'C') f[i + 1][3] = (f[i + 1][3] + f[i][2]) % MOD;
	}
	cout << f[n + 1][3] << endl;
	return 0;
}
