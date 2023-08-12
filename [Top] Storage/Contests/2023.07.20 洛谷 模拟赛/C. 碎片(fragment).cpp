#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int num, t, n, m;
char s[N][N];
int cnt[30], judge[N];

void solve() {
	cin >> n >> m;
	memset(cnt, 0, sizeof cnt);
	memset(judge, 0, sizeof judge);
	for (int i = 1; i <= n; ++ i) cin >> s[i] + 1;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j) 
			cnt[s[i][j] - 'A'] ++;
	for (int i = 1; i <= m; ++ i) judge[cnt[i] & 1] ++;
	if ((n * m) & 1) {
		if (judge[1] == 1) return puts("YES"), void();
		else return puts("NO"), void(); 
	} else {
		if (judge[1]) return puts("NO"), void();
		else return puts("YES"), void();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> num >> t;
	while (t --) solve();
}
