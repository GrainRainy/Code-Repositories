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

using IO::input;
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
int n, m, w[N << 1];
int head[N << 1], idx;
struct Node { int nxt, to; }edge[N << 2];
int pos[N << 1]; LL sum[N << 1];
bool judge;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u, int id) {
	sum[pos[u] = id] += w[u];
	for (int i = head[u]; ~i; i = edge[i].nxt)
		if (!pos[edge[i].to]) dfs(edge[i].to, id);
}

void solve() {
	input(n), input(m);
	judge = true, idx = 0;
	memset(head, -1, sizeof(int) * ((n << 1) + 10));
	memset(pos, 0, sizeof(int) * ((n << 1) + 10));
	memset(sum, 0, sizeof(LL) * ((n << 1) + 10));
	for (int i = 1; i <= n << 1; ++ i) input(w[i]);
	for (int i = 1, t, u, v; i <= m; ++ i) {
		input(t), input(u), input(v);
		t & 1 ? (add(u + n, v), add(v, u + n), add(u, v + n), add(v + n, u)) : (add(u, v), add(v, u), add(u + n, v + n), add(v + n, u + n));
	}
	for (int i = 1; i <= n << 1; ++ i) if (!pos[i]) dfs(i, ++ pos[0]);
	for (int i = 1; i <= n; ++ i) pos[i] ^ pos[i + n] ? judge &= sum[pos[i]] == sum[pos[i + n]] : judge &= !(sum[pos[i]] & 1);
	return puts(judge ? "YES" : "NO"), void();
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
