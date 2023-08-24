#include <iostream>
using namespace std;
double a[10], sum, ans = 1;
int main() {
	for (int i = 1; i <= 7; ++ i)
		scanf("%lf", a + i), sum += a[i];
	for (int i = 1; i <= 6; ++ i) 
		ans = ans * a[i] / (sum - i + 1) * i;
	ans = ans * a[7] * 7;
	printf("%.3lf\n", ans);
	return 0;
}
