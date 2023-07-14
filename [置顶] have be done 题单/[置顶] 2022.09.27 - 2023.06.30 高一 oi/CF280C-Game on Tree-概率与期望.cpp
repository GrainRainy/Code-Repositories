#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

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

const int N = 1e5 + 10;
int n, u, v;
int head[N], idx;
struct Node {
	int nxt, to;
}edge[N << 1];
// graph
queue<int> q;
int dep[N], fa[N];
double ans;
// bfs 

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs() {
	ans = 1;
	q.push(1);
	
	while (q.size()) {
		auto t = q.front(); q.pop();
		for (int i = head[t]; ~i; i = edge[i].nxt) {
			int j = edge[i].to;
			if (j == fa[t]) continue;
			fa[j] = t, dep[j] = dep[t] + 1;
			ans += (double)1 / dep[j];
			q.push(j);
		}
	}
}

int main() {
	memset(head, -1, sizeof head);
	
	input(n);
	for (int i = 1; i < n; ++ i) {
		input(u), input(v);
		add(u, v), add(v, u);
	}
	
	dep[1] = 1, fa[1] = 1;
	dfs();
	
	printf("%.20lf", ans);
	return 0;
}

