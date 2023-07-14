#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input (T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while(x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
int n, m, tmp;
int lin, rin, cnt, ans;
bool st[N];
int sum[N];

inline void solve() {
	memset(st, 0, sizeof st);
	lin = rin = cnt = ans = 0;
	
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) {
		input(tmp);
		if (tmp == -1) lin ++;
		else if (tmp == -2) rin ++;
		else st[tmp] = true;
	}
		
	for (int i = 1; i <= m; i ++) sum[i] = sum[i - 1] + st[i];
	for (int i = m; i >= 1; i --) {
		if (st[i]) ans = max(ans, 1 + min(i - 1, sum[i - 1] + lin) + min(m - i, cnt ++ + rin));
	}
	ans = max(ans, min(m, sum[m] + max(lin, rin)));
	output(ans);
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
