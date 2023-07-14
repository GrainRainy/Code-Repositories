#include <bits/stdc++.h>
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

const int N = 2e4 + 10;
int n;
int head[N], idx;
struct Node { int nxt, to, w; }edge[N << 1];
int rt;
int siz[N], mx[N], d[N], t[3];
bool del[N];
int sum, ans;

inline void add(int a, int b, int w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

void getRt(int u, int fa) {
	siz[u] = 1, mx[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa or del[j]) continue;
		getRt(j, u);
		siz[u] += siz[j];
		mx[u] = max(mx[u], siz[j]);
	}
	mx[u] = max(mx[u], sum - mx[u]);
	if (mx[u] < mx[rt]) rt = u;
}

void getDis(int u, int fa) {
	t[d[u]] ++;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa or del[j]) continue;
		d[j] = (d[u] + edge[i].w) % 3;
		getDis(j, u);
	}
}

int calc(int u, int w) {
	t[0] = t[1] = t[2] = 0;
	d[u] = w;
	getDis(u, 0);
	return t[1] * t[2] * 2 + t[0] * t[0];
}

void solve(int u) {
	ans += calc(u, 0);
	del[u] = true;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (del[j]) continue;
		ans -= calc(j, edge[i].w);
		rt = 0, sum = siz[j];
		getRt(j, 0);
		solve(rt);
	}
}

int main() {
	input(n);
	memset(head, -1, sizeof head);
	for (int i = 1, x, y, w; i < n; ++ i) {
		input(x), input(y), input(w);
		add(x, y, w % 3), add(y, x, w % 3);
	}
	sum = mx[rt] = n;
	getRt(1, 0);
	solve(rt);
	int g = __gcd(ans, n * n);
	printf("%d/%d\n", ans / g, n * n / g);
	return 0;
}
