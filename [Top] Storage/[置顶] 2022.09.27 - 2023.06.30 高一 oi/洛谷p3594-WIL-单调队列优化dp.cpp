#include <iostream>
#include <cstring>
#include <algorithm>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c =='-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	} 
}

using namespace IO;
using namespace std;
using LL = long long;

const int N = 2e6 + 10;
LL n, p, d, ary[N], sum[N];
int ans;
LL q[N]; int head, tail;

int main() {
	input(n), input(p), input(d);
	ans = q[0] = d; int l = 1;
	for (int i = 1; i < d + 1; ++ i) input(ary[i]), sum[i] = sum[i - 1] + ary[i];
	for (int i = d + 1; i <= n; ++ i) {
		input(ary[i]), sum[i] = sum[i - 1] + ary[i];
		while (head <= tail and sum[i] - sum[i - d] > sum[q[tail]] - sum[q[tail] - d]) tail --;
		q[++ tail] = i;
		while (head <= tail and sum[i] - sum[l - 1] - sum[q[head]] + sum[q[head] - d] > p) {
			l ++;
			while (head <= tail and q[head] - d + 1 < l) head ++;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
