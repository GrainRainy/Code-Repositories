#include <iostream>
#include <cstring>
#include <algorithm>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar())
			f |= (c == '-');
		for (; isdigit(c); c = getchar())
			x = x * 10 + (c ^ '0');
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
using LL = long long;

const int N = 1e6 + 10;
LL n, ary[N], top;
struct Seg {
	LL rt, l, r, avr, siz;
}seg[N];
int lson[N], rson[N], dis[N];
LL ans;

int merge(int a, int b) {
	if (!a or !b) return a | b;
	if (ary[b] > ary[a]) swap(a, b);
	rson[a] = merge(rson[a], b);
	if (dis[lson[a]] < dis[rson[a]]) swap(lson[a], rson[a]);
	dis[a] = dis[rson[a]] + 1;
	return a;
}

inline int del(int x) {
	return merge(lson[x], rson[x]);
}

int main() {
	input(n);
	dis[0] = -1;
	for (int i = 1; i <= n; ++ i)
		input(ary[i]), ary[i] -= i;
	// init 
	for (int i = 1; i <= n; ++ i) {
		seg[++ top] = {i, i, i, ary[i], 1};
		while (top != 1 and seg[top - 1].avr > seg[top].avr) {
			top --;
			seg[top].siz += seg[top + 1].siz, seg[top].r = seg[top + 1].r;
			seg[top].rt = merge(seg[top].rt, seg[top + 1].rt);
			while (seg[top].siz > (seg[top].r - seg[top].l + 2) / 2) {
				seg[top].siz --;
				seg[top].rt = del(seg[top].rt);
			}
			seg[top].avr = ary[seg[top].rt];
		}
	}
	
	for (int i = 1, pos = 1; i <= n; ++ i) {
		if (seg[pos].r < i) pos ++;
		ans += abs(seg[pos].avr - ary[i]);
	}
	output(ans);
	for (int i = 1, pos = 1; i <= n; ++ i) {
		if (seg[pos].r < i) pos ++;
		output(seg[pos].avr + i, ' ');
	}
	return puts(""), 0;
}
