#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

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

const int N = 2e5 + 10;
int n;
LL sum[N];
LL ans = 0x3f3f3f3f3f3f3f3f;

int main() {
	input(n);
	for (int i = 1; i <= n; i ++){
		input(sum[i]);
		sum[i] += sum[i - 1];
	}
	// input 
	for (int l = 1, mid = 2, r = 3; mid <= n - 1; mid ++) {
		while (l + 1 < mid and abs(sum[mid] - (sum[l] << 1)) > abs(sum[mid] - (sum[l + 1] << 1))) l ++;
		while (r + 1 < n and abs(sum[n] + sum[mid] - (sum[r] << 1)) > abs(sum[n] + sum[mid] - (sum[r + 1] << 1))) r ++;
		ans = min(ans, max({sum[l], sum[mid] - sum[l], sum[r] - sum[mid], sum[n] - sum[r]}) - 
					   min({sum[l], sum[mid] - sum[l], sum[r] - sum[mid], sum[n] - sum[r]}));
	}
	cout << ans << endl;
	return 0;
}
