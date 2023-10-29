#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
int n, f[N];

inline void upd(int &x, int &y) { x += y; if (x >= MOD) x -= MOD; }
int main() {
	cin >> n;
	for (int i = n; i >= 3; -- i) {
		f[i] = 1;
		for (int j = n / (i - 1) * (i - 1); j >= (i - 1); j -= (i - 1)) {
			if (j > i) upd(f[i], f[j]);
			if (j + 1 > i) upd(f[i], f[j + 1]);
			if (j + 2 > i and i != 3) upd(f[i], f[j + 2]);
		}
	} 
	return cout << (long long)f[3] * 2 * n % MOD << '\n', 0;
}
