#include <iostream>
#include <cstring>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f|= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace std;
using namespace IO;

const int N = 510;
const int K = N * N;
int n, k, ans;
int match[N + K];
bool st[N + K];
// basis 
int head[N], idx;
struct Node {
	int nxt, to;
}edge[N + K];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

bool find(int u) {
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (st[j]) continue;
		st[j] = true;
		if (!match[j] or find(match[j])) {
			match[j] = u;
			return true;
		}
	}
	return false;
}

int main() {
	input(n), input(k);
	memset(head, -1, sizeof head);
	for (int i = 1, u, v; i <= k; ++ i)
		input(u), input(v), add(u, v + n);
	for (int i = 1; i <= n; ++ i) {
		ans += find(i);
		memset(st, 0, sizeof (int) * (n + k + 10);
	}
	cout << ans << endl;
	return 0;
} 
