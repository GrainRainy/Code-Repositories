#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 3e5 + 10;
int n, m, stp[N], head[N], idx;
struct Node { int nxt, to; LL w; }edge[N];

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

inline void add(int a, int b, LL w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

bool check(LL lim) {
	queue<int> q;
	memset(stp, 0, sizeof(int) * (n + 10));
	q.push(1), stp[1] = 1;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = head[u], v; ~i; i = edge[i].nxt) {
			v = edge[i].to;
			if (edge[i].w * stp[u] > lim) continue;
			if (!stp[v] or stp[v] > stp[u] + 1) {
				stp[v] = stp[u] + 1;
				q.push(v);
			}
		}
	}
	return stp[n];
}

int main() {
	rd(n), rd(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b, w; i <= m; ++ i)
		rd(a), rd(b), rd(w), add(a, b, w);
	LL l = 1, r = 3e14, mid;
	while (l < r) {
		mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	return cout << l << '\n', 0;
}
