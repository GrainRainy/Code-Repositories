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
const int N = 1e5 + 10;
int n, m;
struct Save { int a, b; }save[N << 1];
int head[N], idx;
struct Node { int nxt, to; } edge[N << 1];
int dg[N], st[N], cnt;

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

int main() {
	input(n), input(m);
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1; i <= m; ++ i) {
		input(save[i].a), input(save[i].b);
		dg[save[i].a] ++, dg[save[i].b] ++;
	}
	for (int i = 1, a, b; i <= m; ++ i) {
		a = save[i].a, b = save[i].b;
		if (dg[a] < dg[b] or dg[a] == dg[b] and a < b) add(a, b);
		else add(b, a);
	}
	for (int u = 1; u <= n; ++ u) {
		for (int i = head[u]; ~i; i = edge[i].nxt) 
			st[edge[i].to] = u;
		for (int i = head[u]; ~i; i = edge[i].nxt) 
			for (int j = head[edge[i].to]; ~j; j = edge[j].nxt) 
				if (st[edge[j].to] == u) cnt ++;
	}
	printf("%d\n", cnt);
}
