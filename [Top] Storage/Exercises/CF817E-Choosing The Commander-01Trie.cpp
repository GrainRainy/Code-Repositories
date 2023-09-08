#include <bits/stdc++.h>
template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
} 

template <typename T> inline void ot(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

using namespace std;
const int N = 1e5 + 10;
const int LOGL = 28;
int q, op, p, l;
int tr[N * LOGL][2], cnt[N * LOGL], tot = 1;

void insert(int u) {
	int p = 1;
	for (int i = 26; ~i; -- i) {
		if (!tr[p][(u >> i) & 1]) tr[p][(u >> i) & 1] = ++ tot; 
		p = tr[p][(u >> i) & 1], cnt[p] ++;
	}
}

void del(int u) {
	int p = 1;
	for (int i = 26; ~i; -- i) 
		p = tr[p][(u >> i) & 1], cnt[p] --;
}

int query(int q, int l) {
	int res = 0, p = 1;
	for (int i = 26; ~i; -- i) {
		if (!((l >> i) & 1)) p = tr[p][(q >> i) & 1];
		else res += cnt[tr[p][(q >> i) & 1]], p = tr[p][!((q >> i) & 1)];
		if (!p) break;
	}
	return res;
}

int main() {
	rd(q);
	while (q --) {
		rd(op), rd(p);
		if (op == 1) insert(p);
		if (op == 2) del(p);
		if (op == 3) rd(l), ot(query(p, l));
	}
	return 0;
}
