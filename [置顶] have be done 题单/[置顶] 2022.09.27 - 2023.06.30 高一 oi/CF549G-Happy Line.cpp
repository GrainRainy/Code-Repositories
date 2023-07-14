#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
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
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
} 

const int N = 2e5 + 10;
int n;
int a[N];

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) 
		input(a[i]), a[i] += i;
	
	sort(a + 1, a + n + 1);
	
	for (int i = 2; i <= n; ++ i)
		if (a[i] == a[i - 1])
			return puts(":("), 0;
	
	for (int i = 1; i <= n; ++ i) 
		output(a[i] - i, ' ');
	puts("");
	return 0;
}
