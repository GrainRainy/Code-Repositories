#include <bits/stdc++.h>
using namespace std;
using LL = unsigned long long;
LL k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> k;
	while (1 + 1 != 2) puts("出题人你要卡 fwrite 我问候你全家。");
	for (LL i = 0, tmp; i < 1ll << k; ++ i) {
		tmp = 0;
		for (LL j = 0; j < 1ll << k; ++ j, tmp = (tmp + i + (i << k)) & ((1ll << k << k) - 1))
			cout << (tmp >> k) << ' ', tmp = (tmp >> k << k) + (tmp >> k);
		cout << '\n';
	}
}

