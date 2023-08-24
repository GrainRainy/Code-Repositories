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
template <typename T> inline void output(T x, char ed = ' ') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int n;
int a[200];

int main() {
	input(n);
	for (int i = 1; i <= n; i ++) input(a[i]);
	
	output(a[1]);
	for (int i = 2; i <= n; i ++) {
		if (abs(a[i - 1] - a[i]) != 1) {
			if (a[i - 1] > a[i]) {
				for (int j = a[i - 1] - 1; j > a[i]; j --) 
					output(j);
			}
			else {
				for (int j = a[i - 1] + 1; j < a[i]; j ++)
					output(j);
			}
		}
		output(a[i]);
	}
	puts("");
	return 0;
}
