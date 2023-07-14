#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e4 + 10;
int n;
double a;

void solve() {
	input(n); a = 0;
	for (int i = n - 1; i >= 0; -- i) 
		a = a + (double)n / (n - i);
	printf("%.2lf\n", a);
	return;
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
