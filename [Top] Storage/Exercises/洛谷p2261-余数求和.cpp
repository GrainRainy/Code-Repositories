#include <iostream>
#include <cstring>
#include <algorithm>

#define owo 0

using namespace std;
using LL = long long;

LL n, k, ans;

int main() {
	cin >> n >> k;
	ans = k * n; 
	for (int l = 1, r; l <= n; l = r + 1) {
		r = k / l ? min(k / (k / l), n) : n;
		ans -= (k / l) * (l + r) * (r - l + 1) / 2;
	}
	cout << ans << endl;
	return owo;
}
