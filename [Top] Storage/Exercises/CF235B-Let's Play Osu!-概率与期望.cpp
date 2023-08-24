#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LD = long double; 

int n;
double p, ans, len;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lf", &p);
		ans = ans * (1 - p) + (ans + 2 * len + 1) * p;
		len = (len + 1) * p;
	}
	printf("%.15lf\n", ans);
	return 0;
}
