#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 1e5 + 10;
int n;
double p[N], a[N], b[N], c[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lf", &p[i]);
		a[i] = (a[i - 1] + 1) * p[i];
		b[i] = (b[i - 1] + 2 * a[i - 1] + 1) * p[i];
		c[i] = (c[i - 1] + 3 * b[i - 1] + 3 * a[i - 1] + 1) * p[i] + c[i - 1] * (1 - p[i]);
	}
	printf("%.1lf\n", c[n]);
	return 0;
}
