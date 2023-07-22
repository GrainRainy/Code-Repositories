#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void output(T x, char ed = '\n') {
		static short st[40], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using IO::output;
using namespace std;
const int N = 1e6 + 10;
int n, m, p, q, pre[N], col[N];

int find(int x) { return x == pre[x] ? x : pre[x] = find(pre[x]); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> p >> q;
	for (int i = 1; i <= n; ++ i) pre[i] = i;
	for (int i = m, l, r; i and i >= m - n + 1; -- i) {
		l = (i * p + q) % n + 1, r = (i * q + p) % n + 1;
		if (r < l) swap(r, l);
		for (int j = r, pos; j >= l; j = pre[j]) {
			pos = find(j);
			if (pos == j) col[pos] = i, pre[j] = find(j - 1);
		}
	}
	for (int i = 1; i <= n; ++ i) output(col[i]);
	return 0;
}
