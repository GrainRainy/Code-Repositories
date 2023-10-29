#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, e, d, mx = -1e18, ans;
pair<int, int> p[N];

inline void rd(int &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

int main() {
	rd(n);
	for (int i = 1; i <= n; ++ i) rd(d), rd(e), p[i] = {e + d, e - d};
	sort(p + 1, p + n + 1, greater<pair<int, int>>());
	for (int i = 1; i <= n; ++ i) if (p[i].second > mx) ans ++, mx = p[i].second;
	return cout << ans << '\n', 0;
}
