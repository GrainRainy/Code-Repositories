#include <bits/stdc++.h>
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
const int N = 6e5 + 10;
const int LOGS = 24;
int n, m, s[N];
char op[3];
int tot;
struct Trie {
	int rt, s[2], tag;
	#define rt(x) tree[x].rt
	#define l(x) tree[x].s[0]
	#define r(x) tree[x].s[1]
	#define tag(x) tree[x].tag 
}tree[N * LOGS];

void insert(int cur, int pre, int pos, int idx) {
	if (pos < 0) return tag(cur) = idx, void();
	int c = (s[idx] >> pos) & 1;
	tree[cur].s[c ^ 1] = tree[pre].s[c ^ 1];
	tree[cur].s[c] = ++ tot;
	insert(tree[cur].s[c], tree[pre].s[c], pos - 1, idx);
	tag(cur) = max(tag(l(cur)), tag(r(cur)));
}

int query(int cur, int lim, int pos, int val) {
	if (pos < 0) return s[tag(cur)];
	int c = (val >> pos) & 1;
	if (tag(tree[cur].s[c ^ 1]) >= lim) return query(tree[cur].s[c ^ 1], lim, pos - 1, val);
	else return query(tree[cur].s[c], lim, pos - 1, val);
}

int main() {
	input(n), input(m);
	tag(0) = -1, rt(0) = ++ tot;
	insert(rt(0), 0, 23, 0);
	for (int i = 1; i <= n; ++ i) {
		input(s[i]);
		s[i] ^= s[i - 1];
		rt(i) = ++ tot;
		insert(rt(i), rt(i - 1), 23, i);
	}
	for (int i = 1, l, r, x; i <= m; ++ i) {
		cin >> op;
		if (*op == 'A') {
			input(x);
			rt(++ n) = ++ tot;
			s[n] = s[n - 1] ^ x;
			insert(rt(n), rt(n - 1), 23, n);
		} else {
			input(l), input(r), input(x);
			output(query(rt(r - 1), l - 1, 23, s[n] ^ x) ^ s[n] ^ x);
		}
	}
}
