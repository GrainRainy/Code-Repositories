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

int main() {
	map<int, int> st;
	string a;
	int n;
	cin >> n >> a;
	int last = 0;
	for (auto t : a) {
		if (t == 'A') st[0] ++, last = 0;
		if (t == 'T') st[1] ++, last = 1; 
	}
	if (st[0] != st[1]) {
		if (st[0] > st[1]) cout << 'A' << endl;
		else cout << 'T' << endl;
	}
	else {
		if (last == 0) cout << 'T' << endl;
		else cout << 'A' << endl;
	}
	return 0;
}
