#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, m, w[N], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> w[i], w[i] <<= 1;
	for (int i = 1, a, b, c; i <= m; ++ i) 
		cin >> a >> b >> c, w[a] += c, w[b] += c;
	sort(w + 1, w + n + 1);
	for (int i = n; i; i -= 2) ans += w[i] - w[i - 1];
	return cout << (ans >> 1) << '\n', 0;
}
