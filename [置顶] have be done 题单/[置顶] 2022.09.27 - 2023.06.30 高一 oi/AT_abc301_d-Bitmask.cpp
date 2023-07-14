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

char a[70];
LL n, maxn;

int main() {
	cin >> a >> n;
	reverse(a, a + strlen(a));
	
	for (int i = 0; i < strlen(a); i ++)
		if (a[i] == '1') maxn += (1ll << i);
	for (int i = strlen(a) - 1; i >= 0; i --) 
		if (a[i] == '?' and maxn + (1ll << i) <= n) maxn += (1ll << i);
	if (maxn > n) maxn = -1;
	output(maxn);
	return 0;
}
