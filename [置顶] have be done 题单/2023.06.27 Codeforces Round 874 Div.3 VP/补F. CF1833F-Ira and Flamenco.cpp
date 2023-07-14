#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;
int n, m, k, ary[N], bry[N], cnt[N];
int pre[N], suf[N], ans;

inline void upd(int &a, int b) {
	(LL)a + b > MOD ? a += -MOD + b : a += b;
}

void solve() {
	input(n), input(m); ans = 0;
	for (int i = 1; i <= n; ++ i) input(ary[i]);
	sort(ary + 1, ary + n + 1);
	memcpy(bry, ary, sizeof(int) * (n + 10));
	k = unique(bry + 1, bry + 1 + n) - bry - 1;
	for (int i = 1; i <= k; ++ i)
		cnt[i] = upper_bound(ary + 1, ary + n + 1, bry[i]) - lower_bound(ary + 1, ary + n + 1, bry[i]);
	pre[0] = suf[k + 1] = 1;
	for (int i = 1; i <= k; ++ i) {
		if (i % m) pre[i] = (LL)pre[i - 1] * cnt[i] % MOD;
		else pre[i] = cnt[i];
	}
	for (int i = k; i; -- i) {
		if (i % m == m - 1) suf[i] = cnt[i];
		else suf[i] = (LL)suf[i + 1] * cnt[i] % MOD;
	}
	for (int i = m; i <= k; ++ i) {
		if (bry[i] - bry[i - m + 1] == m - 1) {
			if (i % m == m - 1) upd(ans, pre[i]);
			else upd(ans, (LL)pre[i] * suf[i - m + 1] % MOD);
		}
	}
	return output(ans);
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
