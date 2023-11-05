#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, ans;
struct pos {
	int c, t;
	bool operator < (const pos &a) const { return t < a.t; }
}p[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> p[i].c >> p[i].t;
	sort(p + 1, p + n + 1);
	for (int i = 2; i <= n; ++ i) p[i].c += p[i - 1].c;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			if (j >= i and p[j].t - p[i].t < 9)
				ans = max(ans, p[j].c - p[i - 1].c);
			if (j < i and p[j].t + 24 - p[i].t < 9)
				ans = max(ans, p[n].c - p[i - 1].c + p[j].c);
		}
	}
	return cout << ans << '\n', 0;
}
