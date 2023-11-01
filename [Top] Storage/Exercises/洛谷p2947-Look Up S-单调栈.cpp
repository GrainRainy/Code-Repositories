#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, h[N], ans[N], stk[N], top;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> h[i];
		while (top and h[stk[top]] < h[i]) ans[stk[top --]] = i;
		stk[++ top] = i;
	}
	for (int i = 1; i <= n; ++ i) cout << ans[i] << '\n';
	return 0;
} 
