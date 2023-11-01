#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL mx = 3162278;
int n, c[20], nc[20];
LL ans;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> s;
	for (auto t : s) c[t - '0'] ++;
	for (LL i = 0, x; i <= mx; ++ i) {
		x = i * i;
		if (log2(x) / log2(10) > n) break;
		for (int j = 0; j < 10; ++ j) nc[j] = 0;
		for (int j = 0; j < n; ++ j)
			nc[x % 10] ++, x /= 10;
		bool f = true;
		for (int j = 0; j < 10; ++ j)
			if (c[j] != nc[j]) { f = false; break; }
		ans += f;
	}
	return cout << ans << '\n', 0;
}
