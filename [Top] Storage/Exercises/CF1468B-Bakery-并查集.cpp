#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
LL n, m, a[N], k[N], ct[N], fa[N], ans[N];
struct cmp {
	bool operator () (const int &x, const int &y) const {
		return a[x] * ct[y] ^ a[y] * ct[x] ? a[x] * ct[y] > a[y] * ct[x] : x < y;
	}
};
set<int, cmp> st;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
	rd(n), rd(m);
	for (int i = 1; i <= n; ++ i) rd(a[i]);
	for (int i = 1; i <= m; ++ i) rd(k[i]);
	for (int i = 1; i <= n; ++ i) ct[i] = 1, fa[i] = i, st.insert(i);
	for (int i = m, nw, nxt; i; -- i) {
		while (st.size()) {
			nw = *st.begin();
			if (a[nw] <= k[i] * ct[nw]) break;
			st.erase(nw), nxt = find(nw + 1), fa[nw] = nxt;
			if (nxt) st.erase(nxt), a[nxt] += a[nw], ct[nxt] += ct[nw], st.insert(nxt);
			else ct[n + 1] += ct[nw];
			ans[i] = max({ans[i], ct[n + 1] - 1, ct[nxt] - 1});
		}
		ans[i] = max(ans[i], ans[i + 1]);
	}
	for (int i = 1; i <= m; ++ i) ot(ans[i], " \n"[i == m]);
	return 0;
}
