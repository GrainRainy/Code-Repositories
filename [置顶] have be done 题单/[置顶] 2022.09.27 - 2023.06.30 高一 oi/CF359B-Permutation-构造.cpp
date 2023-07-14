#include <iostream>
int n, k;
int main() {
	scanf("%d%d", &n, &k);
	printf("%d ", k + 1);
	for (int i = 1; i <= n << 1; ++ i)
		if (i != k + 1) printf("%d ", i);
}
