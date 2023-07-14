#include <bits/stdc++.h>
#define debug(x) cout << #x << ' ' << x << endl;
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

const int N = 2e5 + 10;
int n, m, q, ary[N], num[N];
int rt[N], idx;
struct SegmentTree {
	int l, r, cnt;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define cnt(x) tree[x].cnt
}tree[N * 20];

int find(int val) {
	return lower_bound(num + 1, num + 1 + m, val) - num;
}

void insert(int &now, int pre, int tl, int tr, int val) {
	now = ++ idx; tree[now] = tree[pre];
	cnt(now) ++;
	if (tl == tr) return;
	int mid = tl + tr >> 1;
	if (val <= mid) return insert(l(now), l(pre), tl, mid, val);
	else return insert(r(now), r(pre), mid + 1, tr, val);
}

int query(int u, int pre, int tl, int tr, int k) {
	if (tl == tr) return tl;
	int mid = tl + tr >> 1;
	if (k <= cnt(l(u)) - cnt(l(pre))) return query(l(u), l(pre), tl, mid, k);
	else return query(r(u), r(pre), mid + 1, tr, k - cnt(l(u)) + cnt(l(pre)));
}

int main() {
	input(n), input(q);
	for (int i = 1, tmp; i <= n; ++ i) {
		input(tmp);
		ary[i] = num[i] = tmp;
	}
	sort(num + 1, num + 1 + n);
	m = unique(num + 1, num + 1 + n) - num - 1;
	for (int i = 1; i <= n; ++ i)
		insert(rt[i], rt[i - 1], 1, m, find(ary[i]));
	int l, r, k;
	while (q --) {
		input(l), input(r), input(k);
		output(num[query(rt[r], rt[l - 1], 1, m, k)]);
	}
	return 0;
}
