#include <iostream>
#include <cstring>
#include <algorithm>

#define owo 0 

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

const int N = 5e6 + 10;
LL n, p, k;
int nums[N];
LL prefix[N], suffix[N];
LL ans;

LL inv(LL n) {
	return ((n == 1) ? 1 : (LL)(p - p / n) * inv(p % n) % p);
}

int main() {
	input(n), input(p), input(k);
	for (int i = 1; i <= n; ++ i) input(nums[i]);
	// input 
	prefix[0] = suffix[n + 1] = 1;
	for (int i = 1; i <= n; ++ i) {
		prefix[i] = prefix[i - 1] * nums[i] % p;
	}
	for (int i = n; i >= 1; -- i) {
		suffix[i] = suffix[i + 1] * nums[i] % p;
	}
	// initialize prefix and suffix 
	for (LL i = 1, j = k; i <= n; ++ i, j = j * k % p) {
		ans = (ans + j * prefix[i - 1] % p * suffix[i + 1] % p) % p;
	}
	return cout << ans * inv(prefix[n]) % p << '\n', owo;
}
