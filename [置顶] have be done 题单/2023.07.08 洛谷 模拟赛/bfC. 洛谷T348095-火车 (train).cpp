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
const int N = 5e5 + 10;
int n, m;
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int p[N];
vector<int> path;
bool fd = false;
bool st[N];
int cnt;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

int dfs(int u, int fa, int tar) {
	if (u == tar) {
		int tmp = path.size();
		while (path.size()) st[path.back()] = true, path.pop_back();
		fd = true;
		return tmp;
	}
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		path.push_back(j);
		int tmp = dfs(j, u, tar);
		if (fd) return tmp;
		path.pop_back();
		
	}
}

int main() {
	memset(head, -1, sizeof head);
	input(n), input(m), input(p[0]);
	for (int i = 1, x, y; i < n; ++ i){
		input(x), input(y);
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= m; ++ i) input(p[i]);
	int pre = p[0];
	for (int i = 1; i <= m; ++ i) {
		if (st[p[i]]) continue;
		fd = false;
		cnt += dfs(pre, 0, p[i]);
		pre = p[i];
	}
	printf("%d\n", cnt);
	return 0;
}
