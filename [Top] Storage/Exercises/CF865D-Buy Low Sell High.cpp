#include <bits/stdc++.h>
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

LL n, ans, tmp;
priority_queue<int> pri;

int main() {
	input(n);
	while (n --) {
		input(tmp);
		pri.push(-tmp), pri.push(-tmp);
		ans += tmp + pri.top();
		pri.pop();
	}
	cout << ans << endl;
}
