#include <bits/stdc++.h>
#define __DEBUG__ puts("__DEBUG__");
#define debug(x) cout << #x << ' ' << x << endl;
#define lowbit(x) ((x) & (-x))
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

using namespace std;
using namespace IO;
const int N = 1e5 + 10;
const int K = 2e5 + 10;
int n, k, pos;
struct Dots {
	int a, b, c, cnt, ans;
}ary[N], bry[N];
int tree[K], ans[N];

bool cmp1(const Dots &a, const Dots &b) {
	if (a.a != b.a) return a.a < b.a;
	if (a.b != b.b) return a.b < b.b;
	return a.c < b.c;
}

bool cmp2(const Dots &a, const Dots &b) {
	if (a.b != b.b) return a.b < b.b;
	return a.c < b.c;
}

void modify(int pos, int val) {
	for (; pos <= k; pos += lowbit(pos)) tree[pos] += val;
}

int query(int r) {
	int res = 0;
	for (; r; r -= lowbit(r)) res += tree[r];
	return res;
}

void cdq(int l, int r) {
	if (l == r) return;
	int mid = l + r >> 1;
	cdq(l, mid), cdq(mid + 1, r);
	sort(bry + l, bry + mid + 1, cmp2);
	sort(bry + mid + 1, bry + r + 1, cmp2);
	int i = mid + 1, j = l;
	for (; i <= r; ++ i) {
		while (bry[j].b <= bry[i].b and j <= mid)
			modify(bry[j].c, bry[j].cnt), j ++;
		bry[i].ans += query(bry[i].c);
	}
	for (int i = l; i < j; ++ i) modify(bry[i].c, -bry[i].cnt);
}

int main() {
	input(n), input(k);
	for (int i = 1, a, b, c; i <= n; ++ i) {
		input(a), input(b), input(c);
		ary[i] = {a, b, c};
	}
	sort(ary + 1, ary + 1 + n, cmp1);
	for (int i = 1; i <= n; ++ i) {
		if (ary[i].a == ary[i - 1].a and ary[i].b == ary[i - 1].b and ary[i].c == ary[i - 1].c) {
			bry[pos].cnt ++;
		} else bry[++ pos] = {ary[i].a, ary[i].b, ary[i].c, 1};
	}
	cdq(1, pos);
	for (int i = 1; i <= pos; ++ i)
		ans[bry[i].ans + bry[i].cnt - 1] += bry[i].cnt;
	for (int i = 0; i < n; ++ i) output(ans[i]);
	return 0;
}
