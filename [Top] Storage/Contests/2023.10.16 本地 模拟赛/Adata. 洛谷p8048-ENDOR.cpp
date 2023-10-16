#include <bits/stdc++.h>
using namespace std;
const int N = 3e4;
const int K = 40;
const int L = 1e6;
mt19937 mt(chrono::system_clock::now().time_since_epoch().count());
map<int, bool> mp;

int main() {
	ios::sync_with_stdio(false), cout.tie(0);
	int n = mt() % N + 1;
	int k = mt() % K + 1;
	int l = mt() % L + 1;
//	n = N, k = K;
	cout << n << ' ' << k << ' ' << l << '\n';
	for (int i = 1, x, tmp; i <= n; ++ i) {
		do x = mt() % (l + 1); while (mp.find(x) != mp.end());
		cout << x << ' ' << mt() % k << ' ';
		cout << (mt() % 2 == 1 ? 'L' : 'D') << '\n';
	}
}
