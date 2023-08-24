#include <cstdio>
long long u, v, delta;
int main() {
	scanf("%lld%lld", &u, &v); delta = v - u;
	if (delta < 0 or (delta & 1)) puts("-1");
	else if (!delta and !u) puts("0");
	else if (!delta) printf("1\n%lld\n", u);
	else if (!((delta >> 1) & u)) printf("2\n%lld %lld\n", delta >> 1, (delta >> 1) ^ u);
	else printf("3\n%lld %lld %lld\n", delta >> 1, delta >> 1, u);
	return 0;
}
