#include <bits/stdc++.h>
using namespace std;
int n;
string a, b = "ABC";

int main() {
	cin >> n >> a;
	for (int i = 0; i + 2 < n; ++ i)
		if (a.substr(i, 3) == b) return cout << i + 1 << '\n', 0;
	cout << -1 << '\n';
}
