#include <bits/stdc++.h>
#define fi first
#define se second
template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

using namespace std;
using LL = long long;
using PLI = pair<LL, int>;
const int N = 1e5 + 10;
int n, a, b, mx, w[N], nums[N];
LL sum;
PLI tr[N];
void add(int p, int v) { while (p <= n) tr[p].fi += v, tr[p].se ++, p += p & -p; }
PLI query(int p) {
	int pos = 0; LL res = 0;
	for (int i = mx; ~i; -- i)
		if (pos + (1 << i) <= n and p > tr[pos + (1 << i)].se)
			pos += (1 << i), res += tr[pos].fi, p -= tr[pos].se;
	return {res + (LL)p * nums[pos + 1], nums[pos + 1]};
}

int main() {
	rd(n), rd(a), rd(b); mx = log2(n);
	for (int i = 1; i <= n; ++ i) rd(w[i]), nums[i] = w[i];
	sort(nums + 1, nums + n + 1);
	nums[0] = unique(nums + 1, nums + n + 1) - nums - 1;
	for (int i = 1; i <= n; ++ i) {
		add(lower_bound(nums + 1, nums + nums[0] + 1, w[i]) - nums, w[i]);
		sum += w[i];
		int pos = ceil((double)b * i / (a + b));
		PLI nw = query(pos);
		ot(a * ((LL)pos * nw.se - nw.fi) + b * ((LL)sum - nw.fi - (i - pos) * (LL)nw.se));
	}
	return 0;
}
