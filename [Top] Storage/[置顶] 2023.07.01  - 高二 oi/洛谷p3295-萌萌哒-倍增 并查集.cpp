#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
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
const int MK = 17;
const int MOD = 1e9 + 7;
int n, m, fa[N][MK], ans;

int find(int x, int k) {
	return fa[x][k] == x ? x : fa[x][k] = find(fa[x][k], k);
}

void merge(int x, int y, int k) {
	x = find(x, k), y = find(y, k);
	if (x ^ y) fa[x][k] = y;
}

int main() {
	input(n), input(m);
	const int mk = log2(n);
	for (int i = 1; i <= n; ++ i) 
		for (int k = 0; k <= mk; ++ k)
			fa[i][k] = i;
	for (int i = 1, la, ra, lb, rb; i <= m; ++ i) {
		input(la), input(ra), input(lb), input(rb);
		for (int k = mk; ~k; -- k)
			if (la + (1 << k) - 1 <= ra) 
				merge(la, lb, k), la += 1 << k, lb += 1 << k;
	}
	for (int k = mk; k; -- k)
		for (int i = 1, tmp; i + (1 << k) - 1 <= n; ++ i) {
			tmp = find(i, k);
			merge(i, tmp, k - 1), merge(i + (1 << k - 1), tmp + (1 << k - 1), k - 1);
		}
	for (int i = 1; i <= n; ++ i)
		if (fa[i][0] == i) ans = !ans ? 9 : 10ll * ans % MOD;
	return printf("%d\n", ans), 0;
}
