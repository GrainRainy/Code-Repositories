#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[40], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
const int N = 1e5 + 10;
int n, len;
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int dfn[N], node[N], stamp; // dfn 
int cnt, lim, res[N], ans[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u, int father) {
	dfn[u] = ++ stamp, node[stamp] = u;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == father) continue;
		dfs(j, u);
	}
}

void dp() {
	for (int i = n, u, mxa, mxb; i; -- i) {
		u = node[i];
		mxa = mxb = 0;
		for (int j = head[u], k; ~j; j = edge[j].nxt) {
			k = edge[j].to;
			if (res[k] >= lim) cnt ++;
			else if (res[k] >= mxa) mxb = mxa, mxa = res[k];
			else if (res[k] > mxb) mxb = res[k];
		}
		if (mxa + mxb + 1 >= lim) cnt ++;
		else res[u] = mxa + 1;
	}
}

int calc(int limit) {
	memset(res, 0, sizeof(int) * (n + 10));
	cnt = 0, lim = limit;
	dp();
	return cnt;
}

int main() {
	input(n); len = sqrt(n * log2(n));
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) {
		input(a), input(b);
		add(a, b), add(b, a);
	}
	dfs(1, 0);
	debug(len)
	for (int i = 1; i <= len; ++ i) ans[i] = calc(i);
	for (int i = 0, l, r, mid, pre = n + 1; i <= n / len; ++ i) {
		l = len + 1, r = pre;
		while (l < r) {
			mid = l + r >> 1;
			if (calc(mid) > i) l = mid + 1;
			else r = mid;
		}
		for (int j = l; j < pre; ++ j) ans[j] = i; 
		pre = l;
	}
	for (int i = 1; i <= n; ++ i) output(ans[i], '\n');
	return 0;
}
