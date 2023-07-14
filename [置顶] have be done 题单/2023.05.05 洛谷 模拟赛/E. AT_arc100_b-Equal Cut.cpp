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

const int N = 2e5 + 20;
int n;
LL nums[N], sum[N];
LL ans = 0x3f3f3f3f;

LL maxn(LL a, LL b, LL c, LL d) {
	LL tmpa = max(a, b);
	LL tmpb = max(c, d);
	return max(tmpa, tmpb);
}

LL minn(LL a, LL b, LL c, LL d) {
	LL tmpa = min(a, b);
	LL tmpb = min(c, d);
	return min(tmpa, tmpb);
}

int main() {
	input(n);
	for (int i = 1; i <= n; i ++){
		input(nums[i]);
		sum[i] = sum[i - 1] + nums[i];
	}
	
	for (int i = 1; i <= n - 3; i ++) {
		for (int j = i + 1; j <= n - 2; j ++) {
			for (int k = j + 1; k <= n - 1; k ++) {
				LL a = sum[i];
				LL b = sum[j] - sum[i];
				LL c = sum[k] - sum[j];
				LL d = sum[n] - sum[k];
				ans = min(ans, maxn(a, b, c, d) - minn(a, b, c, d));
			}
		}
	}
	cout << ans << endl;
	return 0;
}
