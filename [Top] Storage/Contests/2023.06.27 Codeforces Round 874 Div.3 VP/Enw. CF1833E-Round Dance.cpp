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
int n, a[N];
int dg[N], fa[N], cnt;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void solve() {
	set<int> st;
	map<pair<int, int>, bool> mp;
	input(n); cnt = 0;
	memset(dg, 0, sizeof(int) * (n + 10));
	for (int i = 1; i <= n; ++ i) fa[i] = i;
	for (int i = 1; i <= n; ++ i) {
		input(a[i]);
		fa[find(i)] = find(a[i]);
		if (!mp[{i, a[i]}]) dg[i] ++, dg[a[i]] ++;
		mp[{i, a[i]}] = mp[{a[i], i}] = true;
	}
	for (int i = 1; i <= n; ++ i) {
		st.insert(find(i));
		cnt += (dg[i] == 1);
	}
	output(min(st.size(), st.size() - cnt / 2 + 1), ' ');
	output(st.size());
}

int main() {
	int t; input(t);
	while (t --) solve();
}
