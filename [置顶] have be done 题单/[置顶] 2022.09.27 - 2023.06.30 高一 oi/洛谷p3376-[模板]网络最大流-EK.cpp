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
using LL = long long;

const int N = 200 + 10;
const int M = 5e3 + 10;
const int INF = (1 << 29);
int n, m, s, t, u, v, w;
int head[N], idx = 1;
struct Node { int nxt, to; LL w; }edge[M << 1];
int pre[N], pos[N][N];
LL incf[N], maxFlow;
bool vis[N];

inline void add(int a, int b, LL w) {
	edge[++ idx].nxt = head[a];
	edge[idx].w = w;
	edge[head[a] = idx].to = b;
}

bool bfs() {
	for (int i = 1; i <= n; ++ i) vis[i] = false;
	queue<int> q;
	q.push(s), vis[s] = true, incf[s] = INF;
	while (q.size()) {
		auto u = q.front(); q.pop();
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			if (!edge[i].w) continue;
			j = edge[i].to;
			if (vis[j]) continue;
			incf[j] = min(incf[u], edge[i].w);
			pre[j] = i;
			q.push(j), vis[j] = true;
			if (j == t) return true;
		}
	}
	return false;
}

void update() {
	int x = t, i;
	while (x != s) {
		i = pre[x];
		edge[i].w -= incf[t];
		edge[i ^ 1].w += incf[t];
		x = edge[i ^ 1].to;
	}
	maxFlow += incf[t];
}

int main() {
	input(n), input(m), input(s), input(t);
	memset(head, -1, sizeof head);
	for (int i = 1; i <= m; ++ i) {
		input(u), input(v), input(w);
		if (pos[u][v]) edge[pos[u][v] - 1].w += w;
		else add(u, v, w), add(v, u, 0), pos[u][v] = idx;
	}
	while (bfs()) update();
	cout << maxFlow << endl;
	return 0;
}
