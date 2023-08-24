#include <iostream>
#include <cstring>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int MOD = 998244353;
int n, ans; string s;
LL f[N], p[N];
bool st[N];

void init() {
	p[0] = 1;
	for (int i = 1; i <= n; ++ i)
		p[i] = p[i - 1] * 2 % MOD;
	return; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> s;
	init();
	for (int len = 1, cnt = 0; len < n; ++ len) {
		if (!(n % len)) {
			cnt = 0;
			memset(st, true, sizeof(bool) * (len + 10));
			for (int i = 0; i < n; ++ i) if (s[i] == '.') st[i % len] = false;
			for (int i = 0; i < len; ++ i) if (st[i]) cnt ++;
			f[len] = p[cnt];
			for (int i = 1; i < len; ++ i) if (!(len % i)) f[len] -= f[i];
			f[len] = (f[len] % MOD + MOD) % MOD;
		}
	}
	for (int i = 1; i < n; ++ i) ans = (ans + f[i]) % MOD;
	cout << ans << endl;
	return 0;
}
