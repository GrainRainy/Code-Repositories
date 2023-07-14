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

const int N = 2e5 + 10;
const int INF = 1e9 + 10;
int n, a[N], ans[N];

void solve() {
	input(n);
	map<int, bool> mp;
	bool judge = false;
	for (int i = 1; i <= (n >> 1); ++ i) {
		input(a[i]);
		if (mp[a[i]]) judge |= true;
		mp[a[i]] = true;
	}
	if (judge) return puts("-1"), void();
	set<int> st;
	st.insert(-INF), st.insert(INF); // elements available 
	for (int i = 1; i <= n; ++ i) if (!mp[i]) st.insert(i);
	for (int i = n / 2, val; i; -- i) {
		val = *-- st.lower_bound(a[i]);
		if (val == -INF) return puts("-1"), void();
		ans[i * 2 - 1] = val, ans[i * 2] = a[i];
		st.erase(val);
	}
	for (int i = 1; i <= n; ++ i) output(ans[i], " \n"[i == n]);
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
