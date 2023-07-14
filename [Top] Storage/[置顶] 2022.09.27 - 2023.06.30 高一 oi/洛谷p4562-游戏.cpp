#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
using LL = long long;

const int N = 1e7 + 10;
const int MOD = 1e9 + 7;
LL l, r, cnt, ans, j;
bool st[N]; 

int main() {
	scanf("%lld%lld", &l, &r);
	for (int i = l; i <= r; ++ i) {
		if (!st[i]) {
			for (cnt ++, j = (i << 1); j <= r; j += i) 
				st[j] = true;
		}
	}
	ans = cnt;
	for (int i = 1; i <= r - l + 2; ++ i)
		if (i != cnt + 1) ans = ans * i % MOD;
	printf("%lld", ans);
	return 0;
}

