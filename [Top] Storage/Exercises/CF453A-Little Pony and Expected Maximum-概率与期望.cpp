#include <iostream>
using namespace std;
using D = double;

D n, m, ans;

D qpow(D a, int b) {
	D res = 1;
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int main() {
	scanf("%lf%lf", &m, &n);
	ans = m;
	for (int i = 1; i <= m - 1; ++ i)
		ans -= qpow((m - i) / m, n);
	printf("%.12lf\n", ans);
	return 0;
}
