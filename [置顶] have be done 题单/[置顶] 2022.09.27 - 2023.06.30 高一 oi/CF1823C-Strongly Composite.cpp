#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

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

template <typename T> inline void output(T x, char ed = '\n') {
	static short st[32], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int n, tmp;
unordered_map<int, int> list;
int dbl, sgl;

void add(int &u) {
	for (int i = 2; i <= u / i; i ++) {
		while (!(u % i)) {
			list[i] ++;
			u /= i;
		}
	}
	if (u > 1) list[u] ++;
	return;
}

void solve() {
	list.clear(); dbl = sgl = 0;
	input(n);
	for (int i = 1; i <= n; i ++) {
		input(tmp);
		add(tmp);
	}
	for (auto i : list) {
		dbl += i.second / 2;
		sgl += i.second % 2;
	}
	return output(dbl + sgl / 3), void();
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
