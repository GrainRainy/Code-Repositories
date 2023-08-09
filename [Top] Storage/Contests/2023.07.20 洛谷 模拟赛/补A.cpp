#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << endl;
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
int id, n, nxt[N], sum[N];
char s[N];
LL cnt[3], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> id >> n >> s + 1;
	for (int i = 1; i <= n; ++ i) {
		sum[i] = sum[i - 1] + (s[i] == '1');
		cnt[sum[i] & 1] ++;
	}
	for (int i = n, tmp = n; i; -- i) {
		nxt[i] = tmp;
		if (s[i] == '1') tmp = i;
	}
	for (int i = 1, j = 1; i < n; ++ i) {
		while (j <= nxt[i]) cnt[sum[j] & 1] --, j ++;
		ans += cnt[!(sum[i - 1] & 1)];
	}
	return cout << ans << '\n', 0;
}
