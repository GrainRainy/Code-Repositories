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

using IO::input;
using namespace std;
using LL = long long;
const int N = 35 + 5;
int n, m, ans = 0x3f3f3f3f;
LL gph[N];
map<LL, int> mp;

int main() {
	input(n), input(m);
	gph[1] = 1;
	for (int i = 2; i <= n; ++ i) gph[i] = gph[i - 1] << 1;
	for (int i = 1, a, b; i <= m; ++ i) {
		input(a), input(b);
		gph[a] |= 1ll << b - 1;
		gph[b] |= 1ll << a - 1;
	}
	for (int s = 0; s < 1 << n / 2; ++ s) {
		LL t = 0; int cnt = 0;
		for (int i = 1; i <= n / 2; ++ i) 
			if ((s >> i - 1) & 1) t ^= gph[i], cnt ++;
		mp.find(t) == mp.end() ? mp[t] = cnt : mp[t] = min(mp[t], cnt);
	}
	for (int s = 0; s < 1 << n - n / 2; ++ s) {
		LL t = 0; int cnt = 0;
		for (int i = 1; i <= n - n / 2; ++ i)
			if ((s >> i - 1) & 1) t ^= gph[n / 2 + i], cnt ++;
		if (mp.find(((1ll << n) - 1) ^ t) != mp.end())
			ans = min(ans, mp[((1ll << n) - 1) ^ t] + cnt);
	}
	return printf("%lld\n", ans), 0;
}
