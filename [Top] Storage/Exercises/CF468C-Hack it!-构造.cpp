#include <iostream>
using namespace std;
using LL = long long;
const LL INF = 1e18;
LL ansl, ansr, mod;
int main() {
	scanf("%lld", &mod);
	ansl = mod - INF % mod * 9 % mod * 9 % mod;
	ansr = ansl + INF - 1;
	printf("%lld %lld\n", ansl, ansr);
	return 0;
}
