#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << endl;
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
int id, n;
LL sum[N], pre[N], nxt[N], ans;
char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> id >> n >> s + 1;
	int tmp = 0;
	for (int i = 1; i <= n; ++ i) {
		sum[i] = sum[i - 1] + (s[i] == '1');
		if (s[i] == '1') pre[i] = tmp, nxt[tmp] = i, tmp = i;
		else nxt[i] = pre[i] = -1;
	}
	nxt[tmp] = n + 1;
	if (id == 4) {
		int top = 0, stk[5];
		for (int i = 1; i <= n; ++ i)
			if (s[i] == '1') stk[++ top] = i;
		ans = stk[1] * (n - stk[3] + 1);
	} else if (id == 5) {
		for (int i = 1; i <= n; ++ i)
			ans += min(n - i, i - 1);
	} else {
		for (int mid = 2, len, l, r; mid < n; ++ mid) {
			if (s[mid] == '0') continue;
			len = min(sum[n] - sum[mid], sum[mid - 1]);
			ans += (LL)(mid - pre[mid] - 1) * (nxt[mid] - mid - 1);
			l = pre[mid], r = nxt[mid];
			for (int i = 1; i <= len; ++ i, l = pre[l], r = nxt[r]) {
				ans += (LL)(l - pre[l]) * (nxt[r] - r);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
