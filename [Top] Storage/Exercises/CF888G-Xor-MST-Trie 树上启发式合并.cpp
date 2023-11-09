#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
const int LN = 18 + 2;
int n, mx, w[N], rt, ttp;
struct Node {
	int l, r, c, s[2];
	#define l(x) tr[x].l
	#define r(x) tr[x].r
	#define c(x) tr[x].c
	#define s(x, y) tr[x].s[y]
}tr[N * LN];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

void ins(int &u, int id, int dep) {
	if (!u) u = ++ ttp, l(u) = id;
	r(u) = id, c(u) ++;
	if (!(~dep)) return;
	ins(s(u, (w[id] >> dep) & 1), id, dep - 1);
}

int qry(int u, int v, int dep) {
	if (!(~dep)) return 0;
	if (s(u, (v >> dep) & 1)) return qry(s(u, (v >> dep) & 1), v, dep - 1);
	return qry(s(u, ((v >> dep) & 1) ^ 1), v, dep - 1) + (1 << dep);
}

LL dfs(int u, int dep) {
	if (!(~dep)) return 0;
	if (s(u, 0) and s(u, 1)) {
		int ans = 0x3f3f3f3f, l, r, tg;
		l = c(s(u, 0)) < c(s(u, 1)) ? l(s(u, 0)) : l(s(u, 1));
		r = c(s(u, 0)) < c(s(u, 1)) ? r(s(u, 0)) : r(s(u, 1));
		tg = c(s(u, 0)) < c(s(u, 1)) ? s(u, 1) : s(u, 0);
		for (int i = l; i <= r; ++ i) ans = min(ans, qry(tg, w[i], dep - 1));
		return dfs(s(u, 0), dep - 1) + dfs(s(u, 1), dep - 1) + ans + (1 << dep);
	} else return dfs(s(u, 0) | s(u, 1), dep - 1);
}

int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) 
		rd(w[i]), mx = max(mx, w[i]);
	mx = log2(mx) + 1;
	sort(w + 1, w + n + 1);
	for (int i = 1; i <= n; ++ i) ins(rt, i, mx);
	return cout << dfs(rt, mx) << '\n', 0;
}
