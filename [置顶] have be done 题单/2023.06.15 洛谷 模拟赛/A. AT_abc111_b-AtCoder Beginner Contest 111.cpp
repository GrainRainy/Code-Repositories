#include <bits/stdc++.h>
using namespace std;
inline bool check(int n) {
	int a = n % 10; n /= 10;
	int b = n % 10; n /= 10;
	int c = n % 10;
	return ((a == b) and (b == c));
}
int main() {
	int n; cin >> n;
	while (!check(n)) n ++;
	cout << n << endl;
	return 0;
}
