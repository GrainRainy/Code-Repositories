#include <bits/stdc++.h>

#define enter putchar('\n')
#define FI first
#define SE second

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar(); bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T, typename... Args> 
	void input(T &x, Args&... args) {
		input(x), input(args...);
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
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

const int N = 2e5 + 10;
int n, m, k, q;
int fa[N];
map<PII, bool> mp;

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	fa[b] = a;
}

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) fa[i] = i;
	for (int i = 1, a, b; i <= m; ++ i) {
		input(a), input(b);
		merge(a, b);
	}
	for (int i = 1; i <= n; ++ i) find(i);
	input(k);
	for (int i = 1, a, b; i <= k; ++ i) {
		input(a), input(b);
		mp[{find(a), find(b)}] = mp[{find(b), find(a)}] = true;
	}
	input(q);
	for (int i = 1, a, b; i <= q; ++ i) {
		input(a), input(b);
		if (mp[{find(a), find(b)}] or mp[{find(b), find(a)}]) puts("No");
		else puts("Yes");
	}
	return 0;
}
