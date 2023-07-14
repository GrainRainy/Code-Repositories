#include <iostream>
#include <cstring>

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

const int N = 1e5 + 10;
int n;
int head[N], idx;
struct Node {
	int nxt, to;
}edge[N << 1];
// graph
int siz[N];
double ans;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void dfs(int u, int fa) {
	siz[u] = 1;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		dfs(j, u);
		siz[u] += siz[j];
	}
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) continue;
		ans += (LL)(n - siz[j]) * siz[j] * (n - siz[j]) * siz[j];
	}
}

int main() {
	while (~scanf("%d", &n)) {
		ans = idx = 0;
		int m = n * (n - 1) / 2; 
		memset(head, -1, sizeof(int) * (n + 10));
		for (int i = 1, a, b; i < n; ++ i)
			input(a), input(b), add(a, b), add(b, a);
		dfs(1, 0);
		printf("%.6lf\n", ans / m / m);
	}
	return 0;
}
