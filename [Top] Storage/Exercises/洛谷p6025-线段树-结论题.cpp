
#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;
using LL = long long;
LL l, r;

LL log2(LL n) { // ceil 
	int l = 0, r = 63;
	while (l < r) {
		int mid = (l + r) >> 1;
		if ((1ll << mid) < n) l = mid + 1;
		else r = mid;
	}
	return l;
}

bool isPow(LL x) { return !(x & (x - 1)); }

LL f(LL x, LL dep) {
	if (isPow(x) or isPow(x - 1)) return ((x << 1) - 1);
	return f(x >> 1, dep - 1) + (1ll << dep);
}

LL work(LL x) {
	if (!x) return 0;
	LL res = 0;
	unordered_map<LL, bool> mp;
	for (LL i = 1; i <= x; i <<= 1) {
		if (i <= x and !mp[i]) mp[i] = true, res ^= f(i, log2(i));
		if (i | 1 <= x and !mp[i | 1])
			mp[i | 1] = true, res ^= f(i | 1, log2(i | 1));
	}
	if (!(x & 1) and !mp[x]) res ^= f(x, log2(x));
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> l >> r;
	cout << (work(r) ^ work(l - 1)) << '\n';
}
