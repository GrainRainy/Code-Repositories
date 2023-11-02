#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL N = 1e14;
const LL LEN = 2e3;
const LL K = 1e9;
mt19937_64 mt(chrono::system_clock::now().time_since_epoch().count());

int main() {
	LL l = mt() % (N - LEN), len = mt() % (LEN + 1);
	LL k = mt() % K + 1;
	cout << l << ' ' << l + len << ' ' << k << '\n';
}
