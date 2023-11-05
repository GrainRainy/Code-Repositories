#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
int n, mx, lim, a[N], stk[N], top;
LL ans = 1;
bool st[N];
set<int> pre, nw;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int main() {
	rd(n);
	for (int i = 2; i <= 10000; ++ i)
		if (!st[i]) {
			stk[++ top] = i;
			for (int j = i; j <= 10000; j += i)
				st[j] = true;
		}
	for (int i = 1, tmp; i <= n; ++ i) {
		rd(a[i]), tmp = a[i];
		if (i == 1) continue;
		for (int j = 1; j <= top and stk[j] <= a[i - 1]; ++ j) {
			int c = 0;
			while (!(a[i - 1] % stk[j])) a[i - 1] /= stk[j], c ^= 1;
			if (c) nw.insert(stk[j]);
		}
		for (int j = 1; j <= top and stk[j] <= a[i]; ++ j) {
			int c = 0;
			while (!(a[i] % stk[j])) a[i] /= stk[j], c ^= 1;
			if (c and nw.find(stk[j]) != nw.end()) nw.erase(stk[j]);
			else if (c) nw.insert(stk[j]);
		}
		vector<int> res;
		for (auto t : pre) {
			if (nw.find(t) != nw.end()) {
				ans = ans * t % MOD;
				nw.erase(t), res.emplace_back(t);
			}
		}
		for (auto t : res) {
			assert(pre.find(t) != pre.end());
			pre.erase(t);
		}
		for (auto t : pre) ans = ans * t % MOD;
		pre = nw, nw.clear(), a[i] = tmp;
	}
	for (auto t : pre) ans = ans * t % MOD;
	return cout << ans << '\n', 0;
}
