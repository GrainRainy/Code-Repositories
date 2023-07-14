#include <bits/stdc++.h>
#define debug(x) cout << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x; 
	}
}

using namespace IO;
using namespace std;

const int N = 4e4 + 10;
int n, k, ans;
int head[N], idx;
struct Node { int nxt, to, w; }edge[N << 1];
int rt, mxrt, sum, siz[N];
int rem[N], dis[N];
bool del[N];

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void getRt(int u, int fa) {
	int mxu = 0;
	siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (del[j] or j == fa) continue;
		getRt(j, u);
		siz[u] += siz[j];
		mxu = max(mxu, siz[j]);
	}
	mxu = max(mxu, sum - mxu);
	if (mxu < mxrt) mxrt = mxu, rt = u;
}

void getDis(int u, int fa) {
	rem[++ rem[0]] = dis[u];
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa or del[j]) continue;
		dis[j] = dis[u] + edge[i].w;
		getDis(j, u);
	}
}

int calc(int u, int w) {
	rem[0] = 0, dis[u] = w;
	getDis(u, 0);
	sort(rem + 1, rem + 1 + rem[0]);
	int l = 1, r = rem[0], res = 0;
	while (l <= r) rem[l] + rem[r] <= k ? res += r - l, ++ l : -- r;
	return res;
}

void solve(int u) {
	del[u] = true;
	ans += calc(u, 0);
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (del[j]) continue;
		ans -= calc(j, edge[i].w);
		sum = siz[j], mxrt = n, rt = 0;
		getRt(j, 0);
		solve(rt);
	}
}

int main() {
	input(n);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, u, v, w; i < n; ++ i) {
		input(u), input(v), input(w);
		add(u, v, w), add(v, u, w);
	}
	input(k);
	sum = mxrt = n;
	getRt(1, 0);
	solve(rt);
	printf("%d\n", ans);
	return 0;
}
