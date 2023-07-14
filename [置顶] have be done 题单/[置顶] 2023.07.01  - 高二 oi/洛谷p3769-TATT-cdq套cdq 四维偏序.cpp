#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define debug(x) cerr << #x << ' ' << x << endl;
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

const int N = 5e4 + 10;
int n, m;
int lis[N], id[N];
struct Dots {
	int a, b, c, d;
	int id, dp; bool tag;
}ary[N], tmp[N];
int tree[N];

void modify(int pos, int val) {
	for (; pos <= n; pos += lowbit(pos)) 
		tree[pos] = max(tree[pos], val);
}

int query(int r) {
	int res = 0;
	for (; r; r -= lowbit(r)) res = max(res, tree[r]);
	return res;
}

void del(int pos) {
	for (; pos <= n; pos += lowbit(pos))
		tree[pos] = 0;
}

bool cmp1(const Dots &a, const Dots &b) {
	if (a.a != b.a) return a.a < b.a;
	if (a.b != b.b) return a.b < b.b;
	if (a.c != b.c) return a.c < b.c;
	return a.d < b.d;
}

bool cmp2(const Dots &a, const Dots &b) {
	if (a.b != b.b) return a.b < b.b;
	if (a.c != b.c) return a.c < b.c;
	if (a.d != b.d) return a.d < b.d;
	return a.tag < b.tag;
}

bool cmp3(const int &a, const int &b) {
	if (ary[a].c != ary[b].c) return ary[a].c < ary[b].c;
	if (ary[a].d != ary[b].d) return ary[a].d < ary[b].d;
	return ary[a].tag < ary[b].tag;
}

void cdq2(int l, int r) {
	if (l == r) return ary[l].dp = max(ary[l].dp, 1), void();
	int mid = l + r >> 1;
	cdq2(l, mid);
	for (int i = l; i <= r; ++ i) id[i] = i;
	sort(id + l, id + mid + 1, cmp3);
	sort(id + mid + 1, id + r + 1, cmp3);
	int i = mid + 1, j = l;
	for (; i <= r; ++ i) {
		while (ary[id[i]].c >= ary[id[j]].c and j <= mid) {
			if (!ary[id[j]].tag) modify(ary[id[j]].d, ary[id[j]].dp);
			j ++;
		}
		if (ary[id[i]].tag) 
			ary[id[i]].dp = max(ary[id[i]].dp, query(ary[id[i]].d) + 1);
	}
	for (int i = l; i <= j; ++ i) 
		if (!ary[id[i]].tag) del(ary[id[i]].d);
	cdq2(mid + 1, r);
}

void cdq1(int l, int r) {
	if (l == r) return;
	int mid = l + r >> 1;
	cdq1(l, mid);
	for (int i = l; i <= mid; ++ i) ary[i].tag = 0;
	for (int i = mid + 1; i <= r; ++ i) ary[i].tag = 1;
	sort(ary + l, ary + r + 1, cmp2);
	cdq2(l, r);
	for (int i = l; i <= r; ++ i) tmp[i] = ary[i];
	for (int i = l; i <= r; ++ i) ary[tmp[i].id] = tmp[i];
	cdq1(mid + 1, r);
}

int main() {
	input(n);
	for (int i = 1, a, b, c, d; i <= n; ++ i) {
		input(a), input(b), input(c), input(d);
		ary[i] = {a, b, c, d, 0, 0, 0};
		lis[i] = d;
	}
	sort(lis + 1, lis + 1 + n);
	sort(ary + 1, ary + 1 + n, cmp1);
	m = unique(lis + 1, lis + 1 + n) - lis - 1;
	for (int i = 1; i <= n; ++ i)
		ary[i].d = lower_bound(lis + 1, lis + 1 + m, ary[i].d) - lis;
	for (int i = 1; i <= n; ++ i) ary[i].id = i;
	cdq1(1, n);
	int res = 0;
	for (int i = 1; i <= n; ++ i) res = max(res, ary[i].dp);
	printf("%d\n", res);
	return 0;
}
