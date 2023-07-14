#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
using LL = long long;

LL d, n;

int main() {
	cin >> d >> n;
	if (n == 100) cout << (d == 2 ? 10000 : 100) << endl;
	else cout << n * pow(100, d) << endl;
	return 0;
}
