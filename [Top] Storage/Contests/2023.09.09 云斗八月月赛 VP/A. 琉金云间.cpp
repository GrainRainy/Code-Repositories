#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, mn = N;
string a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> a;
	for (int i = 0; i < n; ++ i)
		if (a[i] == '1') mn = min({mn, i, n - i - 1});
	return cout << n - (mn << 1) << '\n', 0;
}
