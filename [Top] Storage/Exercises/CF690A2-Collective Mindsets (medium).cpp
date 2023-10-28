#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	return cout << (n & 1 ? n / 2 : (n - (1 << (int)log2(n))) >> 1) << '\n', 0;
}
