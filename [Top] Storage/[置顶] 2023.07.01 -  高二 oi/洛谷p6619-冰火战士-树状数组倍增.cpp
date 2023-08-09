#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar()) ;
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
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
const int N = 2e6 + 10;
const int LOGN = 20;
int q, lis[N], n;
struct Person { int op, t, x, y; }p[N];
struct BIT {
	int a[N];
	int operator [] (int x) { return a[x]; }
	void modify(int x, int y) { while (x <= n) a[x] += y, x += lowbit(x); }
	LL query(int x) { 
		LL res = 0;
		while (x) res += a[x], x -= lowbit(x);
		return res;
	}
}tr0, tr1;

int main() {
	input(q);
	for (int i = 1; i <= q; ++ i) {
		input(p[i].op), input(p[i].t);
		if (p[i].op == 1) {
			input(p[i].x), input(p[i].y);
			lis[++ n] = p[i].x;
		}
	}
	sort(lis + 1, lis + n + 1);
	n = unique(lis + 1, lis + n + 1) - (lis + 1);
	LL ts = 0;
	for (int i = 1, k; i <= q; ++ i) {
		if (p[i].op == 1) {
			p[i].x = lower_bound(lis + 1, lis + n + 1, p[i].x) - lis;
			if (!p[i].t) tr0.modify(p[i].x, p[i].y);
			else tr1.modify(p[i].x + 1, p[i].y), ts += p[i].y;
		} else {
			k = p[i].t;
			if (!p[k].t) tr0.modify(p[k].x, -p[k].y);
			else tr1.modify(p[k].x + 1, -p[k].y), ts -= p[k].y;
		}
		LL s0 = 0, s1 = ts, ans0 = 0, ans1 = 0;
		int p0 = 0, p1 = 0;
		for (int j = LOGN; ~j; -- j) {
			int tp = p0 + (1 << j), ts0 = s0 + tr0[tp], ts1 = s1 - tr1[tp];
			if (tp > n) continue;
			if (ts0 < ts1) p0 = tp, s0 = ts0, s1 = ts1;
		}
		ans0 = s0, s0 = 0, s1 = ts;
		if (p0 < n) {
			ans1 = min(tr0.query(p0 + 1), ts - tr1.query(p0 + 1));
			for (int j = LOGN; ~j; -- j) {
				int tp = p1 + (1 << j), ts0 = s0 + tr0[tp], ts1 = s1 - tr1[tp];
				if (tp > n) continue;
				if (ts0 < ts1 or min(ts0, ts1) == ans1)
					p1 = tp, s0 = ts0, s1 = ts1;
			}
		}
		if (!max(ans0, ans1)) puts("Peace");
		else if (ans0 > ans1) output(lis[p0], ' '), output(ans0 << 1, '\n');
		else output(lis[p1], ' '), output(ans1 << 1, '\n');
	}
	return 0;
}
