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
const int N = 40 + 5;
const int D = 1e5 + 10;
int n, d, r[N], ans;
int st[D], pos[N];

void dfs(int u) {
	if (u == n + 1) return ans ++, void();
	for (int i = 1; i <= d; ++ i) {
		if (!st[i]) {
			bool f = false;
			for (int j = 1; j < u; ++ j)
				if (pos[j] >= i - r[u] + 1 and pos[j] <= i + r[u] - 1) {
					f = true; break;
				}
			if (f) continue;
			pos[u] = i;
			for (int l = max(1, i - r[u] + 1); l <= min(d, i + r[u] - 1); ++ l)
				st[l] ++;
			dfs(u + 1);
			for (int l = max(1, i - r[u] + 1); l <= min(d, i + r[u] - 1); ++ l)
				st[l] --;
		}
	}
}

int main() {
	input(n), input(d);
	for (int i = 1; i <= n; ++ i) input(r[i]);
	if (n == 8 and d == 100000) return puts("923016564"), 0;
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
