#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

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
using PII = pair<int, int>;
using LL = long long;

const int N = 2e5 + 10;
int n, m, k;
// bases 
int head[N << 1], idx;
struct Node {
	int nxt, to, w;
}edge[N << 2];
// graph
priority_queue<PII, vector<PII>, greater<PII>> hp;
int dist[N << 1];
bool st[N << 1];
// the Shortest Path 

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
	edge[idx].w = c;
}

void dijkstra() {
	dist[1] = 0, hp.push({0, 1});
	while (hp.size()) {
		int cur = hp.top().second; hp.pop();
		if (st[cur]) continue;
		st[cur] = true;
		for (int i = head[cur], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			if (dist[j] > dist[cur] + edge[i].w) {
				dist[j] = dist[cur] + edge[i].w;
				hp.push({dist[j], j});
			}
		}
	}
}

int main() {
	input(n), input(m), input(k);
	memset(head, -1, sizeof head);
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1, a, b, c; i <= m; ++ i) {
		input(a), input(b), input(c);
		if (c) add(a, b, 1), add(b, a, 1);
		else add(a + n, b + n, 1), add(b + n, a + n, 1);
	}
	for (int i = 1, a; i <= k; ++ i)
		input(a), add(a, a + n, 0), add(a + n, a, 0);
	dijkstra();
	int mn = min(dist[n], dist[(n << 1)]);
	if (mn >= 0x3f3f3f3f) return puts("-1"), 0;
	cout << mn << endl;
	return 0;
}
