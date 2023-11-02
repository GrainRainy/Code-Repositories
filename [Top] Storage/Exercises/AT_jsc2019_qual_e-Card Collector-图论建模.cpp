#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, h, l, fa[N << 1];
struct Edge {
	int a, b, w;
	bool operator < (const Edge &t) const { return w > t.w; }
}p[N];
bool rg[N << 1];
long long ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
	rd(n), rd(h), rd(l);
	for (int i = 1; i <= h + l; ++ i) fa[i] = i;
	for (int i = 1; i <= n; ++ i) 
		rd(p[i].a), rd(p[i].b), rd(p[i].w), p[i].b += h;
	sort(p + 1, p + n + 1);
	for (int i = 1, a, b; i <= n; ++ i) {
		a = find(p[i].a), b = find(p[i].b);
		if (a != b and (!rg[a] or !rg[b])) rg[a] = rg[b] = rg[a] | rg[b], fa[b] = a, ans += p[i].w;
		else if (!rg[a]) fa[b] = a, ans += p[i].w, rg[a] = true;
	}
	return cout << ans << '\n', 0;
}
