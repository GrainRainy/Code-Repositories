#include <bits/stdc++.h>
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
const int N = 2e6 + 10;
int num, t, n, k;
bool dp[N];
map<int, vector<int>> mp;

void solve() {
	input(n), input(k);
	if (k == 1) return puts("NO"), void();
	if (num == 7) {
		if (n % k) return puts("NO"), void();
		return puts("YES"), void();
	}
	auto pr = mp[k];
	for (int i = 2; i <= k / i; ++ i) {
		if (!(k % i)) pr.push_back(i);
		while (!(k % i)) k /= i;
	}
	if (k != 1) pr.push_back(k);
	if (num == 8) {
		if (n % pr[0]) return puts("NO"), void();
		return puts("YES"), void();
	}
	if (n <= 2e16) {
		memset(dp, 0, sizeof(bool) * (n + 10));
		dp[0] = true;
		for (int t : pr) {
			if (!(n % t)) return puts("YES"), void();
			for (int j = t; j <= n; ++ j)
				dp[j] |= dp[j - t];
		}
		if (dp[n]) return puts("YES"), void();
		else return puts("NO"), void();
	} else return puts("YES"), void();
}

int main() {
	input(num), input(t);
	while (t --) solve();
	return 0;
}
