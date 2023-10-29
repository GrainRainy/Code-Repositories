#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e5 + 10;
const int M = 20 + 5;
const int MOD = 1e4 + 7;
int n, c, a[N], b[N], q, p, na, nb;
short tree[N << 2][M];
#define l(u) ((u) << 1)
#define r(u) ((u) << 1 | 1)

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

void upd(short &x, int y) { if ((x += y) >= MOD) x -= MOD; }
template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

void pushup(int u) {
	for (int i = 0; i <= c; ++ i) tree[u][i] = 0;
	for (int i = 0; i <= c; ++ i)
		for (int j = 0; j <= c; ++ j) 
			upd(tree[u][min(i + j, c)], (int)tree[l(u)][i] * tree[r(u)][j] % MOD);
}

void build(int u, int tl, int tr) {
	if (tl == tr) return tree[u][0] = b[tl], tree[u][1] = a[tl], void();
	int mid = tl + tr >> 1;
	build(l(u), tl, mid), build(r(u), mid + 1, tr);
	return pushup(u);
}

void modify(int u, int tl, int tr, int p, int a, int b) {
	if (tl == tr) return tree[u][0] = b, tree[u][1] = a, void();
	int mid = tl + tr >> 1;
	if (p <= mid) modify(l(u), tl, mid, p, a, b);
	else modify(r(u), mid + 1, tr, p, a, b);
	return pushup(u);
}

int main() {
	rd(n), rd(c);
	for (int i = 1; i <= n; ++ i) rd(a[i]), a[i] %= MOD;
	for (int i = 1; i <= n; ++ i) rd(b[i]), b[i] %= MOD;
	build(1, 1, n), rd(q);
	while (q --) {
		rd(p), rd(na), rd(nb);
		modify(1, 1, n, p, na % MOD, nb % MOD);
		ot(tree[1][c]);
	}
	return 0;
}
