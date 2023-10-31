#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int MOD = 998244353;
int n, cnt[6], ans;
pair<int, int> ary[N * 5];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

void upd(int &x, const int &y) { if ((x += y) >= MOD) x -= MOD; }
int main() {
	rd(n);
	for (int i = 1, x; i <= 5; ++ i)
		for (int j = 1; j <= n; ++ j)
			rd(x), ary[(i - 1) * n + j] = {x, i};
	sort(ary + 1, ary + n * 5 + 1);
	for (int i = 1; i <= n * 5; ++ i) {
		for (int a = 1; a <= 5; ++ a)
			if (a != ary[i].second and cnt[a]) for (int b = a + 1; b <= 5; ++ b)
				if (b != ary[i].second and cnt[b]) for (int c = 1; c <= 5; ++ c)
					if (c != a and c != b and c != ary[i].second)
						for (int d = c + 1; d <= 5; ++ d) if (d != a and d != b and d != ary[i].second)
							upd(ans, (LL)ary[i].first * cnt[a] % MOD * cnt[b] % MOD * (n - cnt[c]) % MOD * (n - cnt[d]) % MOD);
		cnt[ary[i].second] ++;
	}
	return cout << ans << '\n', 0;
}
