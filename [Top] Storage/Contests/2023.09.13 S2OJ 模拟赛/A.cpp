#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL k, p, q;

LL add(LL a) {
	LL res = 0;
	while (a) res += a % 10, a /= 10;
	return res;
}

LL mul(LL a) {
	LL res = 1;
	while (a) res *= a % 10, a /= 10;
	return res;
}

int main() {
	cin >> k;
	p = add(k) + 5, q = mul(k) + 233;
	if (!(q % p)) cout << 0 << '\n';
	else cout << 10ll * (p - q % p) << '\n';
	return 0;
}
