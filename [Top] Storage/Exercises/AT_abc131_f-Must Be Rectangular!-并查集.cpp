#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, fa[N << 1], ch[N << 1], cl[N << 1];
long long ans;

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i < N << 1; ++ i) fa[i] = i;
	for (int i = 1, x, y; i <= n; ++ i) 
		cin >> x >> y, fa[find(x)] = find(y + N);
	for (int i = 1; i < N; ++ i) ch[find(i)] ++;
	for (int i = N + 1; i < N << 1; ++ i) cl[find(i)] ++;
	for (int i = 1; i < N << 1; ++ i) ans += (long long)ch[i] * cl[i];
	return cout << ans - n << '\n', 0;
}
