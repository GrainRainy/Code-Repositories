#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL x;

int main() {
	cin >> x;
	while (!(x % 2)) x /= 2;
	while (!(x % 3)) x /= 3;
	if (x != 1) cout << "No\n";
	else cout << "Yes\n";
}
