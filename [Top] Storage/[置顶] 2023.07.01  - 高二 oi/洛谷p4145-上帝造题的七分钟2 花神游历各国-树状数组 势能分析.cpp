#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar());
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
int n, m, fa[N];
LL tree[N], a[N];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void modify(int x, LL y) { while (x <= n) tree[x] += y, x += (x & -x); }
LL query(int x) {
	LL res = 0;
	while (x) res += tree[x], x -= (x & -x);
	return res;
}

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(a[i]), modify(i, a[i]), fa[i] = i;
	input(m);
	for (int i = 1, k, l, r; i <= m; ++ i) {
		input(k), input(l), input(r);
		if (l > r) swap(l, r);
		if (k) output(query(r) - query(l - 1));
		else for (int j = l; j <= r; j = (find(j) == j) ? j + 1 : fa[j])
			modify(j, (int)sqrt(a[j]) - a[j]), a[j] = sqrt(a[j]), fa[j] = (a[j] <= 1) ? j + 1 : j;
	}
	return 0;
}
