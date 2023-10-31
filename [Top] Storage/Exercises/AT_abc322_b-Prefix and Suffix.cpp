#include <bits/stdc++.h>
using namespace std;
int n, m;
string a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> a >> b;
	if (b.substr(0, n) == a and b.substr(m - n) == a) cout << 0 << '\n';
	else if (b.substr(0, n) == a) cout << 1 << '\n';
	else if (b.substr(m - n) == a) cout << 2 << '\n';
	else cout << 3 << '\n';
	return 0;
}
