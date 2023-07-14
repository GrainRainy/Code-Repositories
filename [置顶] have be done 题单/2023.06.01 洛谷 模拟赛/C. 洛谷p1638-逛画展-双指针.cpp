#include <bits/stdc++.h>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace std;
using namespace IO;
using LL = long long;

const int N = 1e6 + 10;
const int M = 2e3 + 10;
int n, m, pic[N];
int st[M];
int cnt;
int mn = 0x3f3f3f3f, mnl, mnr;

inline void add(int u) {
	if (!st[u]) cnt ++;
	st[u] ++;
}

inline void del(int u) {
	st[u] --;
	if (!st[u]) cnt --;
}

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) input(pic[i]);
	
	int tmpl = 1, tmpr = 0;
	for (tmpr = 1; tmpr <= n; ++ tmpr) {
		add(pic[tmpr]);
		while (cnt > m or st[pic[tmpl]] > 1) del(pic[tmpl ++]);
		if (cnt >= m and tmpr - tmpl + 1 < mn) {
			mn = tmpr - tmpl + 1;
			mnl = tmpl, mnr = tmpr;
		}
	}
	cout << mnl << ' ' << mnr << endl;
	return 0;
}
