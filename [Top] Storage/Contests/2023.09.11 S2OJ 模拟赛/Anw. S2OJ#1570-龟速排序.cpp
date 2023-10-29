#include <bits/stdc++.h>
using namespace std;
int t, n, d;
int tmp[520], stk[520];

int rd() {
    static unsigned s = 0x80000001;
    unsigned long t = s;
    t ^= t >> 10, t ^= t << 9, t ^= t >> 25;
    s = t;
    return (t & INT_MAX);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t >> n >> d;
	cout << n << '\n';
	if (!t) for (int i = 1; i <= n; ++ i) cout << i << ' ';
	else {
		for (int i = 1; i <= n; ++ i) tmp[i] = i, stk[i] = rd() % (n - i + 1);
		for (int i = n; i; -- i) swap(tmp[i], tmp[i + stk[i]]);
		for (int i = 1; i <= n; ++ i) cout << tmp[i] << ' ';
	}
	return cout << '\n', 0;
}
