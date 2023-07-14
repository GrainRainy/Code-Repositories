#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

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
const int N = 1e5 + 10;
int n, m, q, cnt[N], ans;
// bases 
int root, tTol;
struct SegmentTree {
	int lson, rson;
	int sum;
	vector<int> id;
	#define lson(x) tree[x].lson
	#define rson(x) tree[x].rson
	#define sum(x) tree[x].sum
	#define id(x) tree[x].id
}tree[N << 1];

inline int getInput(int x) {
	return (x + ans - 1) % n + 1;
}

inline void update(int u) {
	for (auto t : id(u)) {
		cnt[t] --;
		if (!cnt[t]) ans ++;
	}
}

int insert(int &u, int tl, int tr, int l, int r, int tmpId) {
	if (!u) u = ++ tTol;
	if (l <= tl and r >= tr) { id(u).push_back(tmpId); return 1; }
	int mid = tl + tr >> 1, res = 0;
	if (l <= mid) res += insert(lson(u), tl, mid, l, r, tmpId);
	if (r > mid) res += insert(rson(u), mid + 1, tr, l, r, tmpId);
	return res;
}

void modify(int &u, int tl, int tr, int pos, int val) {
	if (!u) u = ++ tTol;
	sum(u) += val;
	if (!sum(u) and id(u).size()) update(u);
	if (tl == tr) return;
	int mid = tl + tr >> 1;
	if (pos <= mid) modify(lson(u), tl, mid, pos, val);
	else modify(rson(u), mid + 1, tr, pos, val);
}

void print(int u, int tl, int tr) {
	cout << "Node " << u << "  Left " << tl << "  Right " << tr;
	cout << "  Val " << sum(u) << endl;
	int mid = tl + tr >> 1;
	if (lson(u)) print(lson(u), tl, mid);
	if (rson(u)) print(rson(u), mid + 1, tr);
}

int main() {
	input(n), input(m);
	for (int i = 1, x; i <= n; ++ i) {
		input(x);
		modify(root, 1, n, i, x);
	}
	for (int i = 1, l, r; i <= m; ++ i) {
		input(l), input(r);
		cnt[i] = insert(root, 1, n, l, r, i);
	}
//	print(root, 1, n);
	input(q);
	for (int i = 1, x; i <= q; ++ i) {
		input(x); x = getInput(x);
		modify(root, 1, n, x, -1);
		output(ans);
	}
//	print(root, 1, n);
	return 0;
}
