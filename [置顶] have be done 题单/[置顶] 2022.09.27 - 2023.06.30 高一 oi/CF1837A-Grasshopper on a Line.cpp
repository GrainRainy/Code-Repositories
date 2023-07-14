#include <iostream>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (t -- ) {
		int x, k;
		scanf("%d%d", &x, &k);
		if (x % k) puts("1"), printf("%d\n", x);
		else puts("2"), printf("%d %d\n", x - 1, 1);
	}
	return 0;
}
