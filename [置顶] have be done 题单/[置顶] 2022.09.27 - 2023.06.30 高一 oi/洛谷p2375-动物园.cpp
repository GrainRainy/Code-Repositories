#include <iostream>
#include <cstring>

using namespace std;
using LL = long long;

const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
int n, nxt[N], tmp[N], ans;
char a[N];

void solve() {
	cin >> a + 1;
	n = strlen(a + 1), ans = 1, tmp[1] = 1;
	for (int i = 2, pos = 0; i <= n; ++ i) {
		while (pos and a[pos + 1] != a[i]) pos = nxt[pos];
		if (a[pos + 1] == a[i]) pos ++;
		nxt[i] = pos, tmp[i] = tmp[pos] + 1;
	}
	for (int i = 2, pos = 0; i <= n; ++ i) {
		while (pos and a[pos + 1] != a[i]) pos = nxt[pos];
		if (a[pos + 1] == a[i]) pos ++;
		while ((pos << 1) > i) pos = nxt[pos];
		ans = (LL)ans * (tmp[pos] + 1) % MOD;
	}
	printf("%d\n", ans);
	return;
}

int main() {
	int t; scanf("%d", &t);
	while (t --) solve();
}
