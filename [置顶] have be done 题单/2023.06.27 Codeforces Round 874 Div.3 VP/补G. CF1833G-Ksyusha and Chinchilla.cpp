#include <bits/stdc++.h>
#define debug(x) cout << #x << ' ' << x << endl;
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
const int N = 2e5 + 10;
int n;
int head[N], idx;
struct Node { int nxt, to; }edge[N << 1];
int stk[N], top;
int siz[N];

inline void add(int a, int b) {
	edge[++ idx].nxt = head[a];
	edge[head[a] = idx].to = b;
}

void decomposition(int u, int fa) {
	siz[u] = 1; int tmp;
	for (int i = head[u], j; ~i; i = edge[i].nxt) {
		j = edge[i].to;
		if (j == fa) { tmp = i; continue; }
		decomposition(j, u);
		siz[u] += siz[j];
	}
	if (!fa) return;
	if (siz[u] == 3) siz[u] = 0, stk[++ top] = tmp + 1 >> 1;
}

void solve() {
	input(n);
	idx = top = 0;
	memset(head, -1, sizeof(int) * (n + 10));
	for (int i = 1, a, b; i < n; ++ i) {
		input(a), input(b);
		add(a, b), add(b, a);
	}
	if (n % 3) return puts("-1"), void();
	if (n == 3) return puts("0\n"), void();
	decomposition(1, 0);
	if (top != n / 3 - 1) return puts("-1"), void();
	output(top);
	for (int i = 1; i <= top; ++ i) output(stk[i], " \n"[i == top]);
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
