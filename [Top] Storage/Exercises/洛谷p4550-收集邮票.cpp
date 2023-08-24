#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 1e4 + 10;
int n;
double a[N], b[N];

int main() {
	scanf("%d", &n);
	for (int i = n - 1; i >= 0; -- i) {
		a[i] = a[i + 1] + (double)n / (n - i);
		b[i] = (double)i / (n - i) * (2 * a[i] + 1) + b[i + 1] + a[i + 1] * 2 + 1;
	}
	printf("%.2lf", 0.5 * (a[0] + b[0]));
	return 0;
}
