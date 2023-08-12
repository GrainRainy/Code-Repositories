#include <bits/stdc++.h>

#define __DEBUG__ print();

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e3 + 10;
LL n, m;
struct Array{
	LL a, b, c;
}nums[N];

LL i, j, k;
LL ans = -0x3f3f3f3f3f3f3f3f;

bool cmp(const Array &x, const Array &y) {
	return x.a * i + x.b * j + x.c * k > y.a * i + y.b * j + y.c * k;
}

int main() {
	input(n), input(m);
	for (i = 1; i <= n; ++ i) {
		input(nums[i].a), input(nums[i].b), input(nums[i].c);
	}

	for (i = -1; i <= 1; i += 2)
		for (j = -1; j <= 1; j += 2)
			for (k = -1; k <= 1; k += 2){
				LL sum[4] = {0, 0, 0, 0};
				sort(nums + 1, nums + n + 1, cmp);
				for (int tmp = 1; tmp <= m; ++ tmp){
					sum[1] += nums[tmp].a;
					sum[2] += nums[tmp].b;
					sum[3] += nums[tmp].c;
				}
				ans = max(ans, sum[1] * i + sum[2] * j + sum[3] * k);
			} 
	cout << ans << '\n';
	return 0;
}
