#include <bits/stdc++.h>
using namespace std;
using LL = long long;
string a, b;
long long ans, st[40];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> a >> b;
	ans = (LL)(a.size() + 1) * (b.size() + 1);
	for (auto t : a) st[t - 'a'] ++;
	for (auto t : b) ans -= st[t - 'a'];
	cout << ans << '\n';
}

