#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
using LL = long long;

LL d, n, cnt, val;

int div(int u) {
	int cnt = 0;
	while (!(u % 100)) {
		u /= 100;
		cnt ++;
	}
	return cnt;
}

int main() {
	cin >> d >> n;
	while (cnt < n) {
		val ++;
		if (div(val) == d) cnt ++;
	}
	cout << val << endl;
	return 0;
}
