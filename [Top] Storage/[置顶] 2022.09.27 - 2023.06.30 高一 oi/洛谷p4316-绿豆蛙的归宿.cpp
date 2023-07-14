#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define owo 0

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
const int M = N << 1;
int n, m, u, v, w;

int head[N], idx;
struct Node{
	int nxt, to, w;
}edge[M];

int dg[N], outdg[N];
double dist[N];

inline void add(int a, int b, int c) {
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	edge[idx].w = c;
	head[a] = idx;
}

void topsort() {
	queue<int> q; q.push(n);
	
	while (q.size()) {
		auto x = q.front(); q.pop();
		for (int i = head[x]; ~i; i = edge[i].nxt) {
			int j = edge[i].to;
			dist[j] += (dist[x] + edge[i].w) / dg[j];
			outdg[j] --;
			if (!outdg[j]) q.push(j);
		}
	}
}

int main() {
	memset(head, -1, sizeof head);
	// init
	input(n), input(m);
	for (int i = 1; i <= m; i ++) {
		input(u), input(v), input(w);
		add(v, u, w);
		dg[u] ++, outdg[u] ++;
	}
	topsort();
	printf("%.2lf\n", dist[1]);
	return owo;
}
