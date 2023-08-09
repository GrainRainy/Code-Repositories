#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define DEBUG puts("__DEBUG__");
#define debug(x) cerr << #x << ' ' << x << endl;
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
const int N = 1e5 + 10;
int n, m; LL res;
struct Dot {
	int val, dt, ans; // dt -> del time 
}ary[N];
int ton[N];
int tree[N];

void modify(int pos, int val) {
	for (; pos <= n; pos += lowbit(pos))
		tree[pos] += val;
}

int query(int pos) {
	int res = 0;
	for (; pos; pos -= lowbit(pos)) res += tree[pos];
	return res;
}

bool cmp1(const Dot &a, const Dot &b) { return a.val < b.val; }
bool cmp2(const Dot &a, const Dot &b) { return a.dt < b.dt; }

void solve(int l, int r) {
	if (l == r) return;
	int mid = l + r >> 1;
	solve(l, mid), solve(mid + 1, r);
	sort(ary + l, ary + 1 + mid, cmp1);
	sort(ary + mid + 1, ary + 1 + r, cmp1);
	int i = l, j = mid + 1;
	for (; i <= mid; ++ i) {
		while (ary[i].val > ary[j].val and j <= r) 
			modify(ary[j].dt, 1), j ++;
		ary[i].ans += query(m + 1) - query(ary[i].dt);
	}
	for (int i = mid + 1; i < j; ++ i) modify(ary[i].dt, -1);
	
	i = mid, j = r;
	for (; j > mid; -- j) {
		while (ary[j].val < ary[i].val and i >= l) 
			modify(ary[i].dt, 1), i --;
		ary[j].ans += query(m + 1) - query(ary[j].dt); 
	}
	for (int j = mid; j > i; -- j) modify(ary[j].dt, -1);
}

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) 
		input(ary[i].val), ton[ary[i].val] = i;
	for (int i = 1, tmp; i <= m; ++ i) {
		input(tmp);
		ary[ton[tmp]].dt = i;
	}
	for (int i = 1; i <= n; ++ i) if (!ary[i].dt) ary[i].dt = m + 1;
	for (int i = 1; i <= n; ++ i) {
		res += query(n) - query(ary[i].val);
		modify(ary[i].val, 1);
	}
	for (int i = 1; i <= n; ++ i) modify(ary[i].val, -1);
	solve(1, n);
	sort(ary + 1, ary + n + 1, cmp2);
	for (int i = 1; i <= m; ++ i) {
		output(res);
		res -= ary[i].ans;
	}
	return 0;
}
