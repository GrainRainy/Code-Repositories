#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, fa[N], ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
	rd(n);
	iota(fa + 1, fa + n + 1, 1);
	for (int i = 1, x; i <= n; ++ i) 
		rd(x), fa[find(x)] = find(i);
	for (int i = 1; i <= n; ++ i) if (find(i) == i) ans ++;
	return cout << ans << '\n', 0;
}
