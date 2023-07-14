#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
} 

template <typename T> inline void output(T x, char ed = ' ') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
int n, m, l, r;
// basis 
int root, idx;
struct Node {
	int son[2], fa, val;
	int siz, tag;
	
	void init(int value, int father) {
		val = value, fa = father;
		siz = 1;
	}
}tr[N];

inline void PushUp(int u) {
	tr[u].siz = tr[tr[u].son[0]].siz + tr[tr[u].son[1]].siz + 1;
}

inline void PushDown(int u) {
	if (!tr[u].tag) return;
	swap(tr[u].son[0], tr[u].son[1]);
	tr[tr[u].son[0]].tag ^= 1;
	tr[tr[u].son[1]].tag ^= 1;
	tr[u].tag = 0;
}

void rotate(int x) {
	int y = tr[x].fa, z = tr[y].fa;
	int k = tr[y].son[1] == x; // 0 -> left son; 1 -> right son
	tr[z].son[tr[z].son[1] == y] = x, tr[x].fa = z;
	tr[y].son[k] = tr[x].son[k ^ 1], tr[tr[x].son[k ^ 1]].fa = y;
	tr[x].son[k ^ 1] = y, tr[y].fa = x;
	PushUp(y); PushUp(x);
}

void Splay(int x, int k) { // k == 0 refers to let x to the top 
	while (tr[x].fa != k) {
		int y = tr[x].fa, z = tr[y].fa;
		if (z != k) {
			if ((tr[y].son[1] == x) ^ (tr[z].son[1] == y)) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
	if (!k) root = x;
}

void insert(int val) {
	int u = root, father = 0;
	while (u) father = u, u = tr[u].son[val > tr[u].val];
	u = ++ idx;
	if (father) tr[father].son[val > tr[father].val] = u;
	tr[u].init(val, father);
	Splay(u, 0);
}

int find(int k) {
	int u = root;
	while (true) {
		PushDown(u);
		if (tr[tr[u].son[0]].siz >= k) u = tr[u].son[0];
		else if (tr[tr[u].son[0]].siz + 1 == k) return u;
		else k -= tr[tr[u].son[0]].siz + 1, u = tr[u].son[1];
	}
	return -1; // can't find 	
}

void print(int u) {
	PushDown(u);
	if (tr[u].son[0]) print(tr[u].son[0]);
	if (tr[u].val != 0 and tr[u].val != n + 1) output(tr[u].val);
	if (tr[u].son[1]) print(tr[u].son[1]);
}

int main() {
	input(n), input(m);
	for (int i = 0; i <= n + 1; i ++) insert(i); // add guard 
	while (m --) {
		input(l), input(r);
		l = find(l), r = find(r + 2);
		Splay(l, 0), Splay(r, l);
		tr[tr[r].son[0]].tag ^= 1;
	}
	print(root); puts("");
	return 0;
}
