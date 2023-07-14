#include <iostream>
#include <cstring>
#include <algorithm>

#define owo 0

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 20;
int n;
LL mul = 1, ans, x, y;
LL mod[N], res[N], mi[N];

LL exgcd(LL a, LL b, LL &x, LL &y) {
	if (!b) { x = 1, y = 0; return a; }
	LL d = exgcd(b, a % b, x ,y);
	LL tmp = x;
	x = y, y = tmp - y * (a / b);
	return d;
}

int main() {
	input(n);
	for (int i = 1; i <= n; i ++) {
		input(mod[i]), input(res[i]);
		mul *= mod[i];
	}
	for (int i = 1; i <= n; i ++) {
		mi[i] = mul / mod[i];
		exgcd(mi[i], mod[i], x, y);
		ans += res[i] * mi[i] * x;
	}
	cout << ans % mul << endl;
	return owo;
}
