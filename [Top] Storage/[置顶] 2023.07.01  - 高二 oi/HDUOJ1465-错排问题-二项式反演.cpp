#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 20 + 10;
int n, top;
LL fac[N], C[N][N], ans[N];

int main() {
	C[0][0] = fac[0] = 1;
	for (int i = 1; i <= 20; ++ i) {
		fac[i] = (LL)fac[i - 1] * i;
		C[i][0] = 1;
		for (int j = 1; j <= i; ++ j)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	while (~scanf("%d", &n)) {
		if (ans[n]) { printf("%lld\n", ans[n]); continue; }
		for (int i = 0; i <= n; ++ i)
			ans[n] += C[n][i] * ((n - i) & 1 ? -1 : 1) * fac[i];
		printf("%lld\n", ans[n]);
	}
	return 0;
}
