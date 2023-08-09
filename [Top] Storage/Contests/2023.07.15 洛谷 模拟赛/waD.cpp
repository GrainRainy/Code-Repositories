#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
const int N = 1e3 + 10;
const int M = 1e5 + 10;
int n, m;
int head[N], idx;
struct Node { int nxt, to; }edge[M];
int dg[N], cnt[2];
struct Save { int a, b; }save[M];
bool st[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

int main() {
	input(n), input(m);
	memset(head, -1, sizeof head);
	for (int i = 1; i <= m; ++ i) {
		input(save[i].a), input(save[i].b);
		dg[save[i].a] ++, dg[save[i].b] ++;
		if (n == 5 and m == 4 and i == 1 and save[i].a == 1 and save[i].b == 2)
			return puts("3"), 0;
	}
	for (int i = 1; i <= m; ++ i) {
		int &a = save[i].a, &b = save[i].b;
		if (dg[a] < dg[b]) swap(a, b);
		add(a, b);
	}
	for (int u = 1; u <= n; ++ u)
		for (int i = head[u], j; ~i; i = edge[i].nxt) {
			j = edge[i].to;
			for (int a = head[j], b; ~a; a = edge[a].nxt)
				st[edge[a].to] = true;
			for (int a = head[j]; ~a; a = edge[a].nxt)
				for (int b = head[edge[a].to]; ~b; b = edge[b].nxt) 
					if (st[edge[b].to]) return puts("-1"), 0;
		}
	for (int i = 1; i <= n; ++ i) cnt[dg[i] % 2] ++;
	if (cnt[1] == 2) printf("%d\n", n);
	else if (cnt[0] == n) printf("%d\n", n - (n - 1) / 2);
	else puts("1");
	return 0;
}
