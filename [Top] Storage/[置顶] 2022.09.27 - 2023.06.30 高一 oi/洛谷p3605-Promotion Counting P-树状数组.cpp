#include <iostream>
#include <cstring>
#include <algorithm>

#define lowbit(x) ((x) & -(x))
#define __DEBUG__ puts("__DEBUG__");

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
using LL = long long;

const int N = 1e5 + 10;
int n, ary[N], tmp[N];
// basis 
int head[N], idx;
struct Node {
	int nxt, to;
}edge[N << 1];
LL tree[N];
int ans[N];

inline void add(int u, int v) {
	edge[++ idx].nxt = head[u];
	edge[head[u] = idx].to = v;
}

void modify(int pos, int val) {
	for (pos; pos <= n; pos += lowbit(pos))
		tree[pos] += val;
	return;
}

int query(int x) {
	int res = 0; 
	for (; x; x -= lowbit(x)) 
		res += tree[x];
	return res;
}

void dfs(int u) {
	ans[u] -= query(n) - query(ary[u]);
	for (int i = head[u]; ~i; i = edge[i].nxt) dfs(edge[i].to);
	ans[u] += query(n) - query(ary[u]);
	modify(ary[u], 1);
	return;
}

int main() {
	input(n);
	memset(head, -1, sizeof (int) * (n + 10));
	for (int i = 1; i <= n; ++ i)
		input(ary[i]), tmp[i] = ary[i];
	sort(tmp + 1, tmp + 1 + n);
	for (int i = 1; i <= n; ++ i) 
		ary[i] = lower_bound(tmp + 1, tmp + 1 + n, ary[i]) - tmp;
	// lis
	for (int i = 2, u; i <= n; ++ i) input(u), add(u, i);
	dfs(1);
	for (int i = 1; i <= n; ++ i) output(ans[i]);
	return 0;
}
