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
		do st[ ++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top -- ] | '0');
		putchar(ed);
	}
}

using namespace std;
using namespace IO;

const int N = 1e5 + 10;
int n, b;
struct Item {
	int id, val, len;
	bool type; // 0 refers to the boot, 1 refers to the snow 
	bool operator < (const Item &t) {
		if (val == t.val) return type < t.type;
		return val > t.val;
	}
}item[N << 1];
// basis 
int tTop, rt;
int lson[N << 1], rson[N << 1];
int mx[N << 1], lm[N << 1], rm[N << 1], tag[N << 1];
// Segment Tree 

void pushUp(int u, int tl, int tr) {
	int mid = tl + tr >> 1;
	if (rm[lson[u]] == mid - tl + 1) lm[u] = rm[lson[u]] + lm[rson[u]];
	else lm[u] = lm[lson[u]];
	if (lm[rson[u]] == tr - mid) rm[u] = lm[rson[u]] + rm[lson[u]];
	else rm[u] = rm[rson[u]];
	mx[u] = max({mx[lson[u]], mx[rson[u]], rm[lson[u]] + lm[rson[u]]});
}

void modifyDot(int &u, int tl, int tr, int pos) { // change to 1 
	if (!u) u = ++ tTop;
	if (tl == tr and tr == pos) 
		return mx[u] = lm[u] = rm[u] = tag[u] = 1, void();
	int mid = tl + tr >> 1;
	if (pos <= mid) modifyDot(lson[u], tl, mid, pos);
	else modifyDot(rson[u], mid + 1, tr, pos);
	pushUp(u, tl, tr);
} 

int main() {
	input(n), input(b);
	for (int i = 1; i <= n; ++ i) {
		item[i].id = i;
		input(item[i].val);
		item[i].type = 1;
	}
	for (int i = 1; i <= b; ++ i) {
		item[i].id = i;
		input(item[i + n].val);
		input(item[i + n].len);
	}
	
	sort(item + 1, item + 1 + n + b);
	
	for (int i = 1; i <= n + b; ++ i) {
		if (!item[i].type) output(mx[1] < item[i].len);
		else modifyDot(rt, 1, n, item[i].id);
	}
	return 0;
}
