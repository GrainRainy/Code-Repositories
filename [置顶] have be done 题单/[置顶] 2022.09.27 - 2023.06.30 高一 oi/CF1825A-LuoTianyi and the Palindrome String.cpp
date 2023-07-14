#include <bits/stdc++.h>
#define enter putchar('\n')

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar(); bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T, typename... Args> void input(T &x, Args&... args) {
	input(x), input(args...);
}
template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

string a;

inline void solve() {
	cin >> a;
	bool flag = 1;
	for (int i = 1 ; i < a.size(); i ++) {
		if (a[i] != a[i - 1]) flag = false;
	}
	if (flag) return puts("-1"), void();
	cout << a.size() - 1 << endl;
	return;
}

int main() {
	int t; input(t);
	while (t -- ) solve();
	return 0;
}
