#include <iostream>
#include <cstring>
using namespace std;
int a[20000000];
int n, A, B, C;
double ans;

int main() {
	scanf("%d%d%d%d%d", &n, &A, &B, &C, a + 1);
	
	a[1] = a[1] % C + 1;
	a[n + 1] = a[1] % C + 1;
	for (int i = 2; i <= n; i++) {
		a[i] = ((long long) a[i - 1] * A + B) % 100000001 % C + 1;
	}
	for (int i = 2; i <= n + 1; ++ i)
		ans += 1.0 / max(a[i - 1], a[i]);
	printf("%.3lf\n", ans);
	return 0;
}
