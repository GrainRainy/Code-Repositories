#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x; cin >> n >> x;
	for (int i = 1, y; i < n; ++ i) {
		cin >> y;
		if (y != x) return cout << "No\n", 0;
	}
	cout << "Yes\n";	
}
