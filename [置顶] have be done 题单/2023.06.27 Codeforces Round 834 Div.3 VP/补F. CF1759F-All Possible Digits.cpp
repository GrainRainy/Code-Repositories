#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	} 
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;

const int N = 110;
int n, q, a[N];

void solve() {
	input(n), input(q);
	map<int, bool> mp;
	a[0] = 0;
	for (int i = 1; i <= n; ++ i) 
		input(a[i]), mp[a[i]] = true;
	for (int i = 0; i < a[n]; ++ i) {
		if (!mp[i]) {
			for (int j = n - 1; ~j; -- j) {
				a[j] ++;
				if (a[j] == q) a[j] = 0;
				mp[a[j]] = true;
				if (a[j]) break;
			}
			int cur = a[n] - 1;
			while (mp[cur] and cur) cur --;
			return output(cur + q - a[n], '\n');
		}
	}
	int cur = q - 1;
	while (mp[cur] and cur) cur --;
	return output(max(0, cur - a[n]));
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
