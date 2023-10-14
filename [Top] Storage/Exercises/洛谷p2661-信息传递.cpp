#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 2e5 + 10;
int n, fa[N], dis[N];
int ans = 0x3f3f3f3f;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int find(int x) {
	if (x == fa[x]) return x;
	int tmpfa = fa[x];
	fa[x] = find(fa[x]);
	dis[x] += dis[tmpfa];
	return fa[x];
}

int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) fa[i] = i;
	for (int i = 1, t, a, b; i <= n; ++ i) {
		rd(t), a = find(i), b = find(t);
		if (a == b) ans = min(ans, dis[i] + dis[t] + 1);
		else fa[a] = b, dis[i] = dis[t] + 1;
	}
	return cout << ans << '\n', 0;
}
